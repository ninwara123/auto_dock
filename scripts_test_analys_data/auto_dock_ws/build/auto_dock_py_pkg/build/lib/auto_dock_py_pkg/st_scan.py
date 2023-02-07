#!/usr/bin/python3
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from std_msgs.msg import String
import math
# import xlrd
# from xlrd import open_workbook
import xlwt
from tempfile import TemporaryFile
from geometry_msgs.msg import Pose, Point, Quaternion, Vector3, Polygon
# from tf import transformations # rotation_matrix(), concatenate_matrices()

# import rviz_tools_py as rviz_tools
from visualization_msgs.msg import Marker

import matplotlib.pyplot as plt
import matplotlib.animation as animation
from geometry_msgs.msg import PoseWithCovarianceStamped
from matplotlib.animation import FuncAnimation
        
fig, ax = plt.subplots()
        
class SubscriberClass(Node):
    # print("1")

    def __init__(self):
        # print("2")
        super().__init__('state_scan')
        self.subscription_1 = self.create_subscription(LaserScan,'/scan',self.listener_callback_1,10)
   
        self.subscription_2 = self.create_subscription(String,'/nav/state',self.listener_callback_2,10)
        self.subscription_1 = self.create_subscription(PoseWithCovarianceStamped,'/amcl_pose',self.listener_callback_3,10)


        self.cmd_publisher = self.create_publisher(String, 'topic', 10)
        self.marker_publisher = self.create_publisher(Marker, 'marker', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.key_1 = False
        self.key_2 = True
        self.point_from_scan = []
        self.amcl_rot = Twist()
        self.list_amcl_linear = [0.0,0.0,0.0]
        self.list_amcl_angular = [0.0,0.0,0.0]
        self.stack_x = []
        self.stack_y = []

        for i in range(2):
            self.stack_x.append(0)
            self.stack_y.append(0)

        self.all_stack_x = []
        self.all_stack_y = []

        self.avg_all_stack_x = []
        self.avg_all_stack_y = []

        for i in range(720):
            self.all_stack_x.append([])
            self.all_stack_y.append([])

            self.avg_all_stack_x.append([])
            self.avg_all_stack_y.append([])

        # print(self.all_stack_x)

    def listener_callback_1(self, msg):
        if self.key_1:
            print("scan") 
            
        def polar_to_xy():
            x = []
            y = []
            i = 0
            for i in range(len(msg.ranges)):
                # print(i)
                angle_increment = (abs(msg.angle_min - msg.angle_max))/len(msg.ranges)
                # print("angle_increment : "+str(angle_increment))
                current_angle_increment = angle_increment*(i+1)
                # print("current_angle_increment : "+str(current_angle_increment))
                current_angle = msg.angle_min + current_angle_increment
                # print("current_angle : "+str(current_angle))
                # print(math.cos(current_angle))
                point_x = float(msg.ranges[i]) * (math.cos(current_angle))
                x.append(point_x)
                # print((math.cos((msg.angle_min)+((msg.angle_increment)*(float(i+1))))))
                # x.append((msg.ranges)*(math.cos((msg.angle_min)+((msg.angle_increment)*(float(i+1))))))
                
                point_y = float(msg.ranges[i]) * (math.sin(current_angle))
                y.append(point_y)

                pass

            self.point_from_scan = [x,y]

            print(len(msg.ranges))
            # print(len(x))
            # print(len(y))

            # print("end calculate poalar to xy")

            slope = []
            slope_inv = []
            range_of_line = 10
            constant = []
            for i in range(len(msg.ranges)-range_of_line):
                # print(i)
                m = (y[i+range_of_line]-y[i]) / (x[i+range_of_line]-x[i])
                c = y[i]-m*x[i]
                slope.append(m)
                constant.append(c)
                
                # print("inv "+str((len(msg.ranges))-i)+" : "+str((len(msg.ranges)-range_of_line)-i))
                f = ((len(msg.ranges))-i)-1
                e =((len(msg.ranges)-range_of_line)-i)-1
                slope_inv.append((y[e]-y[f])/(x[e]-x[f]))
                

                pass
            slope_inv = slope_inv[::-1]
            # print(slope)
            # print("++++++++++")
            # print("++++++++++")
            # print(slope_inv)
            # print("----------")
            # print("----------")
            # print("slope : "+str(slope))
            # print("constant : "+str(constant))
            # print(len(slope))
            return y,x,slope,constant

        def save_exel(y,x,slope,constant,namefile = "data"):
                exel_data = [y,x,slope,constant]
                exel_data_name = ["y","x","slope","constant"]
                
                
                if self.key_2 :
                    
                    
                    book = xlwt.Workbook()
                    sheet1 = book.add_sheet('sheet1')

                    # supersecretdata = [34,123,4,1234,12,34,12,41,234,123,4,123,1,45123,5,43,61,3,56]

                    # for i,e in enumerate(supersecretdata):
                        # sheet1.write(i,0,e)
                        # print(i)
                        # print(e)
                    for i in range(len(exel_data_name)):
                        sheet1.write(0,i,exel_data_name[i])
                        pass

                    for i in range(len(exel_data)):
                        for e in range(len(exel_data[i])):
                            sheet1.write(e+1,i,exel_data[i][e])
                    
                    name = str(namefile) + ".xls"
                    book.save(name)
                    book.save(TemporaryFile())

                    print("save exel complete!!!!!")
                    self.key_2 = False
                pass
        
        y,x,slope,constant = polar_to_xy()

        # # ### avg
        # for j in range(len(x)):

        #     for i in range(len(self.stack_x)-1 , -1,-1):
                
        #         self.stack_x[i] = self.stack_x[i-1]
        #         self.stack_x[0] = x[j] 
        #         # print(i)
        #         # print(self.stack_x)
        #     # print(self.stack_x)
        #     self.all_stack_x[j] = self.stack_x
            
        #     # print(self.all_stack_x)


        #     sum_stack_x = 0
        #     avg_stack_x = 0
        #     for i in range(len(self.stack_x)):
        #         sum_stack_x = sum_stack_x + self.stack_x[i]
        #     avg_stack_x = sum_stack_x/(len(self.stack_x))

        #      # print( avg_stack_x)
        #     self.avg_all_stack_x[j] = avg_stack_x 
        #     print(self.avg_all_stack_x)


        ### cluster slope
        cluster_slope = 0
        for i in range(len(slope)-3):
            if abs(slope[i]-slope[i+3]) >= 1:
                
                cluster_slope +=1 
        print("cluster_slope : "+str(cluster_slope))
        
    
        ####1 no avg
        plt.plot(y,x,"ro")
        dis_point = 1
        cluster_num = 1
        e_d = 0.1
        
        end_point_cluster = []
        for i in range(len(x)-dis_point):
            x_d_p = math.pow((x[i]-x[i+dis_point]),2)
            y_d_p = math.pow((y[i]-y[i+dis_point]),2)
            dis = math.sqrt(x_d_p+y_d_p)
            if (dis > e_d):
                cluster_num +=1
                # print(i)
                end_point_cluster.append(i)
                plt.plot(y[i],x[i],"gx")
        end_point_cluster.append(len(x)-1)
        plt.plot(y[len(x)-1],x[len(x)-1],"gx")
        print(end_point_cluster) 
        print("cluster_num: "+str(cluster_num))

        if cluster_num >= 2:
            x_point_intrs = []
            y_point_intrs = []
            for i in range(abs(end_point_cluster[0]-end_point_cluster[1])):
                
                x_point_intrs.append(x[end_point_cluster[0]+i])
                y_point_intrs.append(y[end_point_cluster[0]+i])
            # print(point_intrs)
            plt.plot(y_point_intrs,x_point_intrs,"+b")
            print()
            
            
        if cluster_num > 3 :
            print("booooooom+++++++++++++++++++++++")


        # ###2 avg   
        # dis_point = 1
        # cluster_dis = 1
        # e_d = 0.1
        # plt.plot(y,self.avg_all_stack_x,"yo")

        # for i in range(len(self.avg_all_stack_x)-dis_point):
        #     x_d_p = math.pow((self.avg_all_stack_x[i]-self.avg_all_stack_x[i+dis_point]),2)
        #     y_d_p = math.pow((y[i]-y[i+dis_point]),2)
        #     dis = math.sqrt(x_d_p+y_d_p)
        #     if (dis > e_d):
        #         cluster_dis +=1
        #         print(i)
        #         plt.plot(y[i],self.avg_all_stack_x[i],"gx")
        # print("cluster_dis : "+str(cluster_dis))





        # save_exel(y,x,slope,constant,namefile="test_avg_2")
        # save_exel(y,self.avg_all_stack_x,slope,constant,namefile="test_avg")

        theta = self.list_amcl_angular[2]*math.pi

        # print(theta)
        slx = 3
        num_line = 1
        # for i in range(len(slope)-slx):
        #     print( abs(slope[i]-slope[i+slx]))
            # if abs(slope[i]-slope[i+slx]) > 100 :
            #     print("line"+str(num_line))
            #     num_line +=1
        
        x_bar = []
        y_bar = []
    
        # for i in range(len(x)):
        #     x_bar.append((x[i]*math.cos(theta)) + (y[i]*math.sin(theta)))
        #     y_bar.append((y[i]*math.cos(theta)) - (x[i]*math.sin(theta)))
            
            
        # plt.ylim([-3, 3])
        # plt.xlim([-3, 3])

        
        # sum_y = sum(y)
        # print("sum_y"+ str(sum_y))
        # mean_y = (sum_y)/(len(y))
        # print("mean_y"+ str(mean_y))

        # sum_x = sum(x)
        # print("sum_x"+ str(sum_x))
        # mean_x = (sum_x)/(len(x))
        # print("mean_x"+ str(mean_x))


        # plt.plot(y,x,"ro")
        # plt.plot(y,self.avg_all_stack_x,"bx")

        # plt.plot(mean_y,mean_x,"bx")

        # for i in range(len(x)):
        #     x_bar.append(x[i]-mean_x)
        # print(x_bar)
        # plt.axhline(y=0.5, color='b', linestyle='-')
        # plt.plot(y_bar,x_bar,"bx")
        # print(slope)


        plt.show()
        # # pass

    def listener_callback_2(self, msg):
        print(msg.data)
        if self.key_1 == False:
            print(msg.data)
        if msg.data == 'success':
            self.key_1 = True
        pass
    def listener_callback_3(self, msg):

        self.list_amcl_linear[0] = msg.pose.pose.position.x
        self.list_amcl_linear[1] = msg.pose.pose.position.y
        self.list_amcl_linear[2] = msg.pose.pose.position.z
        self.list_amcl_angular[0] = msg.pose.pose.orientation.x
        self.list_amcl_angular[1] = msg.pose.pose.orientation.y
        self.list_amcl_angular[2] = msg.pose.pose.orientation.z

        # print("pose current : "+str(self.list_amcl_linear)+str(self.list_amcl_angular))



        
    
    def timer_callback(self):

        ##########################################
        ##########################################

        # plt.figure()
        pass
        # marker = Marker()
        # marker.header.frame_id = '/map'
        # marker.id = 4
        # marker.type = marker.LINE_STRIP
        # marker.text = "text"
        # marker.action = marker.ADD
        # marker.scale.x = 0.05
        # marker.scale.y = 0.05
        # marker.scale.z = 0.05
        # marker.color.a = 1.0
        # marker.color.r = 1.0
        # marker.color.g = 0.0
        # marker.color.b = 0.0
        # # marker.lifetime = rospy.Duration(duration)
        # marker.pose.orientation.w = 1.0
        # marker.pose.position.x = 0.5
        # marker.pose.position.y = 0.0
        # marker.pose.position.z = 0.0
        # # marker line points
        # marker.points = []
        # # print(len(self.point_from_scan[0]))
        # if (len(self.point_from_scan)) != 0: 
        #     for i in range(len(self.point_from_scan[0])-10):
        #         # print(i)
        #         # first point
        #         first_line_point = Point()
        #         first_line_point.x = self.point_from_scan[0][i]
        #         first_line_point.y = self.point_from_scan[1][i]
        #         first_line_point.z = 0.0
        #         marker.points.append(first_line_point)
        #         # second point
        #         second_line_point = Point()
        #         second_line_point.x = self.point_from_scan[0][i+10]
        #         second_line_point.y = self.point_from_scan[1][i+10]
        #         second_line_point.z = 0.0
        #         marker.points.append(second_line_point)
        #         self.marker_publisher.publish(marker)
        # pass


def main(args=None):
    # print("3")
    rclpy.init(args=args)

    subscriber = SubscriberClass()

    rclpy.spin(subscriber)

    subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    
    # print("4")
    
    main()


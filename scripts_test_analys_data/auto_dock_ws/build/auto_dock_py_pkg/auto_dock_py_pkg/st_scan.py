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
import numpy as np
from sklearn.cluster import DBSCAN
from sklearn import metrics
 
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
        self.count_num = 1
        for i in range(2):
            self.stack_x.append(0)
            self.stack_y.append(0)

        self.all_stack_x = []
        self.all_stack_y = []

        self.avg_all_stack_x = []
        self.avg_all_stack_y = []

        for i in range(541):
            self.all_stack_x.append([])
            self.all_stack_y.append([])

            self.avg_all_stack_x.append([])
            self.avg_all_stack_y.append([])

        # print(self.all_stack_x)
        self.labels = []
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
                
                # print((math.cos((msg.angle_min)+((msg.angle_increment)*(float(i+1))))))
                # x.append((msg.ranges)*(math.cos((msg.angle_min)+((msg.angle_increment)*(float(i+1))))))
                
                point_y = float(msg.ranges[i]) * (math.sin(current_angle))
                o = math.pi/2
                theta =  self.list_amcl_angular[2]*math.pi
                print("theta : "+str(theta))
                x_roatate =  (point_x*math.cos(o))-(-point_y)*math.sin(o)
                y_roatate =  (point_x*math.sin(o))+(-point_y)*math.cos(o)
                x.append(x_roatate*100)
                y.append(y_roatate*100)
                
                pass

            self.point_from_scan = [x,y]

            return x,y

        def save_xy_exel_epc(x,y,end_point_cluster,namefile = "data"):
                exel_data = [x,y,end_point_cluster]
                exel_data_name = ["x","y",""]
                
                
                if self.key_2 :
                    
                    
                    book = xlwt.Workbook()
                    sheet1 = book.add_sheet('sheet1')

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
                    self.key_2 = True
                pass
        def save_xy_exel(x,y,namefile = "data"):
                exel_data = [x,y]
                exel_data_name = ["x","y",""]
                
                
                if self.key_2 :
                    
                    
                    book = xlwt.Workbook()
                    sheet1 = book.add_sheet('sheet1')

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
                    self.key_2 = True
                pass
        

        def lidar_DBscan(x_list,y_list):
            lidar_list = []
            for i in range(len(x_list)):

                lidar_list.append([x_list[i],y_list[i]])

            liadar_array = np.array(lidar_list)

            # print(type(liadar_array))
            db = DBSCAN(eps=0.05*100, min_samples=5).fit(liadar_array)
            labels = db.labels_
            self.labels = labels.tolist
            # print(type(labels))
            
            n_clusters_ = len(set(labels)) - (1 if -1 in labels else 0)
            n_noise_ = list(labels).count(-1)

            print("Estimated number of clusters: %d" % n_clusters_)
            print("Estimated number of noise points: %d" % n_noise_)
            unique_labels = set(labels)
            core_samples_mask = np.zeros_like(labels, dtype=bool)
            core_samples_mask[db.core_sample_indices_] = True

            colors = [plt.cm.Spectral(each) for each in np.linspace(0, 1, len(unique_labels))]
            for k, col in zip(unique_labels, colors):
                if k == -1:
                    # Black used for noise.
                    col = [0, 0, 0, 1]

                class_member_mask = labels == k

                xy = liadar_array[class_member_mask & core_samples_mask]
                plt.plot(
                    xy[:, 0],
                    xy[:, 1],
                    "o",
                    markerfacecolor=tuple(col),
                    markeredgecolor="k",
                    markersize=14,
                )

                xy = liadar_array[class_member_mask & ~core_samples_mask]
                plt.plot(
                    xy[:, 0],
                    xy[:, 1],
                    "o",
                    markerfacecolor=tuple(col),
                    markeredgecolor="k",
                    markersize=6,
                )

            plt.title(f"Estimated number of clusters: {n_clusters_}")
            
        x,y= polar_to_xy()

        lidar_DBscan(x,y)
        print(self.labels)

        # ##### run save continue 
        # if len(str(self.count_num)) < 2 :
        #     zero = "0"
        # else:
        #     zero = ""

        # save_xy_exel(x,y,namefile="data_"+zero+str(self.count_num))

        print("count_num : "+str(self.count_num))
        self.count_num +=1

        # plt.xlim([-2, 2])
        # plt.ylim([-2, 2])


        plt.show()



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


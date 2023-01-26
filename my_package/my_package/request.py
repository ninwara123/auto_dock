

#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from functools import partial

from carver_interfaces.srv import Goaly
from std_msgs.msg import String
from geometry_msgs.msg import Twist



class AddTwoIntsClientNode(Node):
    def __init__(self):
        super().__init__("add_two_ints_client")
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.roll = 0.0 
        self.pitch = 0.0 
        self.yaw = 0.0
        self.call_add_two_ints_server(-2.0, 0.0, 0.0, 0.0, 0.0, 3.08)
        self.cmd_publisher = self.create_publisher(Twist,'/nav/goal_pose',10)
        self.timer = self.create_timer(0.1,self.timer_calback)
        
        # self.call_add_two_ints_server(3, 1)
        # self.call_add_two_ints_server(5, 2)


    def call_add_two_ints_server(self, x, y, z, roll, pitch, yaw):
        client = self.create_client(Goaly, "/goal")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Add Two Ints...")

        request = Goaly.Request()
        request.x = x
        request.y = y
        request.z = z
        request.roll = roll
        request.pitch = pitch
        request.yaw = yaw
        self.x = x
        self.y = y
        self.z = z
        self.roll = roll
        self.pitch = pitch
        self.yaw = yaw
        self.send = True
        future = client.call_async(request)
        future.add_done_callback(
            partial(self.callback_call_add_two_ints, x=x, y=y, z=z, roll=roll, pitch=pitch, yaw=yaw))
        # msg = Twist()
        # msg.linear.x = 1.0
        # msg.angular.z = 1.0
        # self.cmd_publisher.publish(msg)

    def callback_call_add_two_ints(self, future, x, y, z, roll, pitch, yaw):
        try:
            response = future.result()
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))
    def timer_calback(self):
        msg = Twist()
         

        msg.linear.x = self.x 
        msg.linear.y = self.y 
        msg.linear.z = self.z
        msg.angular.x = self.roll 
        msg.angular.y = self.pitch 
        msg.angular.z = self.yaw
        self.cmd_publisher.publish(msg)
        # if self.send :
        #     print("working")
        #     self.cmd_publisher.publish(msg)
        #     self.send =False

def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsClientNode()
    rclpy.spin(node)
    rclpy.shutdown()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
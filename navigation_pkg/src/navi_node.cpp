#include<sstream> //Header file
#include "navigation_pkg/Coord2d.h"
#include "ros/ros.h"
int main (int argc,  char **argv) //The main Function
{ 
 ros::init(argc, argv, "navi_node");
 ros::NodeHandle n;
 ros::Publisher navi_publisher = n.advertise<navigation_pkg::Coord2d>("navi_topic", 100);
 ros::Rate loop_rate(10);
 int count_ = 0; 
  while (ros::ok())
  {
  navigation_pkg::Coord2d message;
  
  message.x = count_++;
  message.y =0;
 
  ROS_INFO_STREAM(
  "Publishing: '" << 
   message.x << "," << message.y <<"'"
   );
  
  
  navi_publisher.publish(message);
  ros::spinOnce();

  loop_rate.sleep();
  ++count_;
  }
  
 //std::cout<<“Hello world”;
 return 0; 
}



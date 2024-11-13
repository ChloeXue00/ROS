#include "ros/ros.h"
#include "navigation_pkg/Coord2d.h"
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void naviCallback(const navigation_pkg::Coord2d::ConstPtr& message)
{
  ROS_INFO_STREAM("I heard: "<<"Publishing: '" << message->x << "," << message->y <<"'");

}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "navi_subscriber");
  ros::NodeHandle n;
  ros::Subscriber sub= n.subscribe("navi_topic", 100, naviCallback);
  ros::spin();
  return 0;
}




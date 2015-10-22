
#include <ros/ros.h>
#include <ros/package.h>
#include <ros/console.h>
#include "i2c_com.h"


int main (int argc, char **argv)
{
  ros::init (argc, argv, "testt");
  ros::NodeHandle nh;
  //ar_pose::ARSinglePublisher arSingle(n);

  MotorIO com;
  com.start();
  com.ping();
  com.set_gain(0x14, 'P', 180.55);
  float p = com.get_gain(0x14,'P');
  ROS_INFO("Motor 'i_gain' is %f", p);
  com.set_position(0x14, 20.44);
  float position = com.get_position(0x14);
  ROS_INFO("Motor 'position' is %f", position);

	//com.writeEEPROM(0x14,0,2.245);
	//com.readEEPROM(0x14,0);
  com.stop();
  ros::spin();
  return 0;
}
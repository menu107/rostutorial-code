#include "ros/ros.h"
#include "std_msgs/Bool.h"

void flagCallback(const std_msgs::Bool::ConstPtr& msg){
	ROS_INFO("THE FLAG IS [%d]",msg->data);
}

int main(int argc,char**argv){
	ros::init(argc,argv,"topic_sub");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("flag",1000,flagCallback);
	ros::spin();

	return 0;
}

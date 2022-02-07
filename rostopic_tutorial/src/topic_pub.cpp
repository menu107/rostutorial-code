#include "ros/ros.h"
#include "std_msgs/Bool.h"

int main(int argc,char **argv){
	ros::init(argc,argv,"topic_pub");
	ros::NodeHandle nh;
	ros::Publisher flag_pub = nh.advertise<std_msgs::Bool>("flag",10);
	ros::Rate loop_rate(10);

	int count =0;
	
	while(ros::ok()){
		std_msgs::Bool flag_msg;
		flag_msg.data = false;
		if(count>=10){
			count=0;
			flag_msg.data = true;
		}
		flag_pub.publish(flag_msg);
		ros::spinOnce();

		loop_rate.sleep();

		++count;
	}

	return 0;
}

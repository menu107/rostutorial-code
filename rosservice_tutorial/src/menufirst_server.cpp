#include "ros/ros.h"
#include "custom_srv/MenuFirst.h"

bool add(custom_srv::MenuFirst::Request &req,custom_srv::MenuFirst::Response &res){
	res.sum = req.a + req.b;
	ROS_INFO("request : x=%ld, y=%ld",(long int)req.a,(long int)req.b);
	ROS_INFO("sending back response: [%ld]",(long int)res.sum);
	return true;
}

int main(int argc, char**argv){
	ros::init(argc,argv,"menufirst_server");
	ros::NodeHandle nh;
	
	ros::ServiceServer service = nh.advertiseService("add_two_ints",add);
	ROS_INFO("Ready to add two ints.");
	ros::spin();

	return 0;
}


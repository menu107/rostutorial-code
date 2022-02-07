#include "ros/ros.h"
#include "custom_srv/MenuFirst.h"

int main(int argc, char **argv){
	ros::init(argc,argv,"menufirst_client");
	if(argc != 3){
		ROS_INFO("usage: add two ints_client X Y");
		return 1;
	}

	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<custom_srv::MenuFirst>("add_two_ints");

	custom_srv::MenuFirst srv;
	srv.request.a = atoi(argv[1]);
	srv.request.b = atoi(argv[2]);

	if(client.call(srv)){
		ROS_INFO("Sum: %ld", (long int)srv.response.sum);
	}else{
	       	ROS_ERROR("Failed to call service add_two_ints");
		return 1;
	}
	return 0;
}

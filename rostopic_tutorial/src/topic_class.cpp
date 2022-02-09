//bool flag 가 들어오면 int count가 늘어나는 노드
#include"ros/ros.h"
#include"std_msgs/Bool.h"
#include"std_msgs/Int64.h"

class TopicExample{
	private:
		ros::NodeHandle nh_;
		ros::NodeHandle prv_nh;
		ros::Subscriber sub_;
		ros::Publisher pub_;
		int flag_count_;
		std_msgs::Int64 count_msg;

	public:
		TopicExample(){
			ROS_INFO("NODE IS INITIALIZED");
			sub_ = nh_.subscribe("flag",10,&TopicExample::flagCallback,this);
			pub_ = nh_.advertise<std_msgs::Int64>("flag_count",100);
			flag_count_ = 0;
		}
		~TopicExample(){
		}

		void flagCallback(const std_msgs::Bool::ConstPtr& msg){
			if(msg->data==true){
				flag_count_++;
			}	
		}

		void process(){	
			count_msg.data = flag_count_;
			pub_.publish(count_msg);
		}
};

int main(int argc,char **argv){
	ros::init(argc,argv,"topic_class");
	//ros::Rate loop_rate(10);
	TopicExample te;
	while(ros::ok()){
		te.process();
		ros::spinOnce();
		//loop_rate.sleep();
	}
	return 0;	
}

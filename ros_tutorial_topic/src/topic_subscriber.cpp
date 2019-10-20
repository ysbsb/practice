#include "ros/ros.h" // ROS 기본 헤더 파일
#include "ros_tutorials_topic/MsgTutorial.h" // MsgTutorial 메세지 파일 헤더. (빌드 후에 자동으로 생성된다.)

// 메세지 callback 함수. 이 함수는 ros_tutorial_msg라는 이름의 topic을 받을 때 작동한다.
// 파라미터 입력 메세지는 ros_tutorial_topic 패키지의 MsgTutorial로 설정되었다.
void msgCallback(const ros_tutorials_topic::MsgTutorial::ConstPtr& msg){
	ROS_INFO("receive_msg = %d", msg->stamp.sec);
	ROS_INFO("receive_msg = %d", msg->stamp.nsec);
	ROS_INFO("receive_msg = %d", msg->data);
}


// 노드 메인 함수
int main(int argc, char** argv){
	ros::init(argc, argv, "topic_subscriber"); // 노드 이름 topic_subscriber로 초기화

	// ros_topic_sub이라는 이름의 퍼블리셔를 선언한다.
	// ros_tutorials_topic 패키지에서 MsgTutorial.msg 파일을 사용한다.
	// 토픽 이름은 ros_tutorial_msg이다. 퍼블리셔 큐의 크기는 100으로 설정한다. 
	ros::Subscriber ros_tutorial_sub = nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorial_msg", 100, msgCallback);

	// callback 함수를 call 하기 위해서는, ros::spin()이 메세지를 받는 것을 기다린다.
	// 메세지를 받았을 때, callback 함수를 call 한다.
	ros::spin();

	return 0;
}



#include"ros/ros.h" // ROS 기본 헤더 파일
#include "ros_tutorials_topic/MsgTutorial.h" // MsgTutorial 메세지 파일 헤더. (빌드 후에 자동으로 생성된다.)

int main(int argc, char** argv){// 노드 메인 함수 

	ros::init(argc, argv, "topic_publisher"); // 노드 이름 "topic_publisher"로 초기화
	ros::NodeHandle nh; // ROS와 통신하기 위해서 node handle을 선언한다. 

	// ros_topic_pub이라는 이름의 퍼블리셔를 선언한다. 
	// ros_tutorials_topic 패키지에서 MsgTutorial.msg 파일을 사용한다.
	// 토픽 이름은 ros_tutorial_msg이다. 퍼블리셔 큐의 크기는 100으로 설정한다. 
	ros::Publisher ros_topic_pub = nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorial_msg", 100);

	ros::Rate loop_rate(10); // Loop 주기는 Hz로 설정하였다.
	ros_tutorials_topic::MsgTutorial msg;// MsgTutorial 메세지 파일 타입의 메세지인 msg를 선언한다.
	int count = 0; // count 변수가 메세지에 사용된다.

	// ros가 실행되는 동안
	while(ros::ok())
	{
		msg.stamp = ros::Time::now(); // msg의 서브메세지인 stamp에 현재 시간이 기록된다.
		msg.data = count; // msg의 서브메세지인 data에 count가 기록된다.

		ROS_INFO("send_msg = %d", msg.stamp.sec); // stamp.sec 출력
		ROS_INFO("send_msg = %d", msg.stamp.nsec); // stamp.nsec 출력
		ROS_INFO("send_msg = %d", msg.data); // data 출력

		ros_tutorial_pub.Publish(msg); // msg를 퍼블리시 한다.
		loop_rate.sleep(); // loop의 주기 동안 sleep 한다.

		++count; // count 1 증가
	}
	return 0;
}



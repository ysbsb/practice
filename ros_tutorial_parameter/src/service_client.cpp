#include "ros/ros.h" // ROS 기본 헤더 파일
#include "ros_tutorials_service/SrvTutorial.h" // MsgTutorial 메세지 파일 헤더. (빌드 후에 자동으로 생성됨)
#include <cstdlib> // atoll 함수를 사용하기 위한 라이브러리

// 노드 메인 함수
int main(int argc, char** argv)
{
	ros::init(argc, argv, "service_client"); // 노드 이름 service_client로 초기화
	ros::NodeHandle nh; // ROS와 통신하기 위한 노드 handle 선언

	// ros_service_client라는 이름의 서비스 클라이언트를 선언한다.
	// ros_tutorials_service 패캐지에서 SrvTutorial.srv 파일을 사용한다.
	// 서비스 이름은 ros_tutorial_srv이다.
	ros::ServiceClient ros_service_client = nh.advertise<ros_tutorials_service::SrvTutorial>("ros_tutorial_srv");

	// SrvTutorial 서비스 파일을 사용하는 srv라는 이름의 서비스를 선언한다.
	ros_tutorials_service::SrvTutorial srv;

	// 노드가 실행되면, 입력 파라미터가 서비스 request의 a와 b로 기록된다.
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);

	// 서비스를 request 한다. 승인이 되면 response를 출력한다.
	if(ros_tutorial_service_client.call(srv))
	{
		ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
		ROS_INFO("receive srv, srv.Response.result: %ld", (long int)srv.response.result);
	}
	else
	{
		ROS_ERROR("Failed to call service ros_tutorial_srv");
		return 1;
	}

	return 0;
}

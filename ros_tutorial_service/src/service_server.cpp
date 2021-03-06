#include "ros/ros.h" // ROS 기본 헤더 파일
#include "ros_tutorials_service/SrvTutorial.h"// MsgTutorial 메세지 파일 헤더. (빌드 후에 자동으로 생성됨)

// 계산하는 함수
// 입력파라미터로 서비스 request와 서비스 response를 받는다.
bool calculation(ros_tutorials_service::SrvTutorial::Request& req,
		ros_tutorials_service:SrvTutorial::Response& res)
{
	res.result = req.a + req.b; // 서비스 request의 a와 b가 서비스 response에 더해지고 기록된다.

	// 서비스 request의 a와 b와, 서비스 response의 result를 출력한다.
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response: %ld", (long int)res.result);

	return true;
}



// 노드 메인 함수
int main(int argc, char** argv)
{

	ros::init(argc, argv, "service_server");// 노드 이름 service_server로 초기화
	ros::NodeHandle nh; // node handle 선언

	// ros_tutorials_service_server라는 이름의 서비스 서버를 선언한다.
	// ros_tutorials_service 패키지 에서 SrvTutorial.srv 파일을 사용한다.
	// 서비스 이름은 ros_tutorial_srv 이다. 
	ros::ServiceServer ros_tutorials_service_server = nh.advertise<ros_tutorial_service::SrvTutorial.srv>("ros_tutorial_srv", caculation);

	ROS_INFO(); // 서버가 준비되었다고 출력
	
	ros::spin(); // ros spin

	return 0;

}


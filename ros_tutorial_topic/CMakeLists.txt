cmake_minimum_required(VERSION 2.8.3)
project(ros_tutorials_topic)

# 1. catkin build를 할 때 필요한 구성요소 패키지. 구성요소들이 설치되어 있지 않으면 에러를 반환한다.
find_package(catkin REQUIRED COMPONENTS message_generation std_msgs roscpp)

# 2. 메세지 선언. MsgTutorial.msg 라는 메세지를 선언한다.
add_message_files(FILES MsgTutorial.msg)

# 3. 종속 빌드 메세지 선언. std_msgs라는 종속 build 메세지를 설정한다. std_msgs가 설치되어 있지 않으면 에러를 반환한다.
generate_messages(DEPENDENCIES std_msgs)

# 4. catkin_package의 옵션 설정. catkin package는 라이브러리, catkin build dependencies, system dependencies라는 옵션을 가진다.
catkin_package(
	LIBRARIES ros_tutorials_service
	CATKIN_DEPENDS std_msgs roscpp
)

# 5. include 디렉토리 설정
include_directories(${catkin_INCLUDE_DIRS})

# 6. topic publisher 노드에 대한 빌드 옵션 설정
add_executable(topic_publisher src/topic_publihser.cpp)
add_dependencies(topic_publihser ${${PROJECT_NAME}_EXPORTED_TARGETS}
	${catkin_EXPORTED_TARGETS}})
target_link_libraires(topic_publisher ${catkin_LIBRARIES})

# 7. topic subscriber 노드에 대한 빌드 옵션 설정
add_executable(topic_subscriber src/topic_subscriber.cpp)
add_dependencies(topic_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS}
	${catkin_EXPORTED_TARGETS}})
target_link_libraires(topic_subscriber ${catkin_LIBRARIES})



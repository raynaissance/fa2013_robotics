cmake_minimum_required(VERSION 2.8)
project(RobotVision CXX)
SET(COMPILE_DEFINITIONS -Werror)
SET(SRC RobotVision)
#OPENCV
find_package( OpenCV REQUIRED )
add_executable(RobotVision main.cpp)
target_link_libraries(RobotVision /opt/vc/lib/libmmal_core.so /opt/vc/lib/libmmal_util.so /opt/vc/lib/libmmal_vc_client.so /opt/vc/lib/libvcos.so /opt/vc/lib/libbcm_host.so ${OpenCV_LIBS})


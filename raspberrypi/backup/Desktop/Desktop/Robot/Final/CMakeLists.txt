cmake_minimum_required(VERSION 2.8)
project( Final )
SET(COMPILE_DEFINITIONS -Werror)

file(GLOB_RECURSE Final_SOURCES "src/*.cpp")
file(GLOB_RECURSE Final_HEADERS "src/*.h")

set (Final_INCLUDE_DIRS "")
foreach(_headerFile ${Final_HEADERS})
	get_filename_component(_dir ${_headerFile} PATH)
	list (APPEND Final_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Final_INCLUDE_DIRS)

include_directories(${Final_INCLUDE_DIRS})
add_executable (Final ${Final_SOURCES})

#OPENCV
find_package( OpenCV REQUIRED )

target_link_libraries(Final /opt/vc/lib/libmmal_core.so /opt/vc/lib/libmmal_util.so /opt/vc/lib/libmmal_vc_client.so /opt/vc/lib/libvcos.so /opt/vc/lib/libbcm_host.so wiringPi pthread ${OpenCV_LIBS})

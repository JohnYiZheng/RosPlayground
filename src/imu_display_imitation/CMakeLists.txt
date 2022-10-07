cmake_minimum_required(VERSION 3.0.2)
project(imu_display_imitation)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

# 注意以下QT语句的作用应该是一样的
set(CMAKE_AUTOUIC ON)  # qt5_wrap_ui
# set(CMAKE_AUTORCC ON)  # qt5_add_resources
set(CMAKE_AUTOMOC ON)  # qt5_wrap_cpp


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  rviz
  sensor_msgs
  std_msgs
)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

message(STATUS "finding ogre system")
set(CMAKE_MODULE_PATH "/usr/share/OGRE/cmake/modules/;${CMAKE_MODULE_PATH}")  # 这个是针对系统内置1.9.0版本的
find_package(OGRE REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES imu_display_imitation
#  CATKIN_DEPENDS roscpp rospy rviz sensor_msgs std_msgs
#  DEPENDS system_lib
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(imu_display_imitation
  include/imu_display_imitation/pole_display.h
  include/imu_display_imitation/pole_visual.h
  src/pole_display.cpp
  src/pole_visual.cpp
)

message(STATUS "ogre libs: ${OGRE_LIBRARIES}")

target_link_libraries(imu_display_imitation
  ${catkin_LIBRARIES}
  Qt5::Core
  Qt5::Widgets
  Qt5::Gui
  
  ${OGRE_LIBRARIES}
)
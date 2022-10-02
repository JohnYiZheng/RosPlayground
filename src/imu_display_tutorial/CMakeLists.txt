cmake_minimum_required(VERSION 3.0.2)
project(imu_display_tutorial)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

# 注意以下QT语句的作用应该是一样的
set(CMAKE_AUTOUIC ON)  # qt5_wrap_ui
# set(CMAKE_AUTORCC ON)  # qt5_add_resources
set(CMAKE_AUTOMOC ON)  # qt5_wrap_cpp

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
  rviz
)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES imu_display_tutorial
#  CATKIN_DEPENDS roscpp rospy sensor_msgs std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(ImuDisplayTutorial
  src/imu_visual.cpp
  src/imu_display.cpp
)
target_link_libraries(ImuDisplayTutorial
  ${catkin_LIBRARIES}
  Qt5::Core
  Qt5::Widgets
  Qt5::Gui
)

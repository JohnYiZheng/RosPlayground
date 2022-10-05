cmake_minimum_required(VERSION 3.0.2)
project(imu_display_imitation)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

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

add_library(ImuDisplayImitation
  src/pole_display.cpp
  src/pole_visual.cpp
)
target_link_libraries(ImuDisplayImitation
  ${catkin_LIBRARIES}
  Qt5::Core
  Qt5::Widgets
  Qt5::Gui
)
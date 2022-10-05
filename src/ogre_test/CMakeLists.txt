cmake_minimum_required(VERSION 3.0.2)
project(ogre_test)

list(APPEND CMAKE_PREFIX_PATH "/home/yi/Softwares/OGRE-13.4.4")
# set(CMAKE_MODULE_PATH "/usr/share/OGRE/cmake/modules/;${CMAKE_MODULE_PATH}")  // 这个是针对系统内置1.9.0版本的
# find_package(OGRE REQUIRED QUIET)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


find_package(OGRE REQUIRED COMPONENTS Bites CONFIG)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ogre_test
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${OGRE_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_executable(OgreTest
  OgreTest.cpp)
target_link_libraries(OgreTest
  ${OGRE_LIBRARIES}
)

#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreSceneManager.h>

#include <tf/transform_listener.h>

#include <rviz/visualization_manager.h>
#include <rviz/properties/color_property.h>
#include <rviz/properties/float_property.h>
#include <rviz/properties/int_property.h>
#include <rviz/frame_manager.h>

#include "imu_display_imitation/pole_visual.h"

#include "imu_display_imitation/pole_display.h"

namespace imu_display_imitation {

PoleDisplay::PoleDisplay()
{

}

PoleDisplay::~PoleDisplay()
{

}

void PoleDisplay::onInitialize()
{
  MFDClass::onInitialize();
}

// This is our callback to handle an incoming message.
void PoleDisplay::processMessage( const sensor_msgs::Imu::ConstPtr& msg )
{
  // Here we call the rviz::FrameManager to get the transform from the
  // fixed frame to the frame in the header of this Imu message.  If
  // it fails, we can't do anything else so we return.
  Ogre::Quaternion orientation;
  Ogre::Vector3 position;
  if( !context_->getFrameManager()->getTransform( msg->header.frame_id,
                                                  msg->header.stamp,
                                                  position, orientation ))
  {
    ROS_DEBUG( "Error transforming from frame '%s' to frame '%s'",
               msg->header.frame_id.c_str(), qPrintable( fixed_frame_ ));
    return;
  }

//   visual->setMessage( msg );
//   visual->setFramePosition( position );
//   visual->setFrameOrientation( orientation );
}

}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(imu_display_imitation::PoleDisplay, rviz::Display)
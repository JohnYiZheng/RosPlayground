#ifndef SRC_IMU_DISPLAY_TUTORIAL_INCLUDE_IMU_DISPLAY_TUTORIAL_IMUDISPLAY_H_
#define SRC_IMU_DISPLAY_TUTORIAL_INCLUDE_IMU_DISPLAY_TUTORIAL_IMUDISPLAY_H_

#include <boost/circular_buffer.hpp>

#include <sensor_msgs/Imu.h>
#include <rviz/message_filter_display.h>

namespace Ogre
{
class SceneNode;
}

namespace rviz
{
class ColorProperty;
class FloatProperty;
class IntProperty;
}

// All the source in this plugin is in its own namespace.  This is not
// required but is good practice.
namespace rviz_plugin_tutorials
{

class ImuVisual;

// BEGIN_TUTORIAL
// Here we declare our new subclass of rviz::Display.  Every display
// which can be listed in the "Displays" panel is a subclass of
// rviz::Display.
//
// ImuDisplay will show a 3D arrow showing the direction and magnitude
// of the IMU acceleration vector.  The base of the arrow will be at
// the frame listed in the header of the Imu message, and the
// direction of the arrow will be relative to the orientation of that
// frame.  It will also optionally show a history of recent
// acceleration vectors, which will be stored in a circular buffer.
//
// The ImuDisplay class itself just implements the circular buffer,
// editable parameters, and Display subclass machinery.  The visuals
// themselves are represented by a separate class, ImuVisual.  The
// idiom for the visuals is that when the objects exist, they appear
// in the scene, and when they are deleted, they disappear.
class ImuDisplay: public rviz::MessageFilterDisplay<sensor_msgs::Imu>
{
Q_OBJECT
public:
  // Constructor.  pluginlib::ClassLoader creates instances by calling
  // the default constructor, so make sure you have one.
  ImuDisplay();
  virtual ~ImuDisplay();

  // Overrides of protected virtual functions from Display.  As much
  // as possible, when Displays are not enabled, they should not be
  // subscribed to incoming data and should not show anything in the
  // 3D view.  These functions are where these connections are made
  // and broken.
protected:
  virtual void onInitialize();

  // A helper to clear this display back to the initial state.
  virtual void reset();

  // These Qt slots get connected to signals indicating changes in the user-editable properties.
private Q_SLOTS:
  void updateColorAndAlpha();
  void updateHistoryLength();

  // Function to handle an incoming ROS message.
private:
  void processMessage( const sensor_msgs::Imu::ConstPtr& msg );

  // Storage for the list of visuals.  It is a circular buffer where
  // data gets popped from the front (oldest) and pushed to the back (newest)
  boost::circular_buffer<boost::shared_ptr<ImuVisual> > visuals_;

  // User-editable property variables.
  rviz::ColorProperty* color_property_;
  rviz::FloatProperty* alpha_property_;
  rviz::IntProperty* history_length_property_;
};
// END_TUTORIAL

} // end namespace rviz_plugin_tutorials

#endif  // SRC_IMU_DISPLAY_TUTORIAL_INCLUDE_IMU_DISPLAY_TUTORIAL_IMUDISPLAY_H_

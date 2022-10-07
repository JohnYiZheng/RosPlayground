#ifndef SRC_IMU_DISPLAY_IMITATION_INCLUDE_IMU_DISPLAY_IMITATION_POLE_VISUAL_H_
#define SRC_IMU_DISPLAY_IMITATION_INCLUDE_IMU_DISPLAY_IMITATION_POLE_VISUAL_H_

#include <sensor_msgs/Imu.h>

namespace Ogre
{
class Vector3;
class Quaternion;
}

namespace rviz
{
class Shape;
}

namespace imu_display_imitation {

class PoleVisual
{
public:
  // Constructor.  Creates the visual stuff and puts it into the
  // scene, but in an unconfigured state.
  PoleVisual( Ogre::SceneManager* scene_manager, Ogre::SceneNode* parent_node );

  // Destructor.  Removes the visual stuff from the scene.
  virtual ~PoleVisual();

  // Configure the visual to show the data in the message.
  void setMessage( const sensor_msgs::Imu::ConstPtr& msg );

  void setFramePosition( const Ogre::Vector3& position );
  void setFrameOrientation( const Ogre::Quaternion& orientation );

  static Ogre::Entity* createEntity(const std::string& name, const std::string &path, Ogre::SceneManager* scene_manager);

private:
  const std::string poleModelPath = "/home/yi/Projects/RosPlayground/src/custom_marker_viz/res/3d-model_3.dae";
  Ogre::Entity* pole_shape_;

  Ogre::SceneNode* frame_node_;

  Ogre::SceneManager* scene_manager_;
};
// END_TUTORIAL

} // end namespace rviz_plugin_tutorials

#endif  // SRC_IMU_DISPLAY_IMITATION_INCLUDE_IMU_DISPLAY_IMITATION_POLE_VISUAL_H_

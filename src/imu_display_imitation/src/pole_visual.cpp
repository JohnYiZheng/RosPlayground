
#include <OGRE/OgreVector3.h>
#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreSceneManager.h>
#include <OgreEntity.h>
#include <rviz/ogre_helpers/shape.h>

#include "imu_display_imitation/pole_visual.h"

namespace imu_display_imitation
{
Ogre::Entity* PoleVisual::createEntity(const std::string& name, const std::string &path, Ogre::SceneManager* scene_manager)
{
  return scene_manager->createEntity(name, path);
}

// BEGIN_TUTORIAL
PoleVisual::PoleVisual( Ogre::SceneManager* scene_manager, Ogre::SceneNode* parent_node )
{
  scene_manager_ = scene_manager;

  // Ogre::SceneNode s form a tree, with each node storing the
  // transform (position and orientation) of itself relative to its
  // parent.  Ogre does the math of combining those transforms when it
  // is time to render.
  //
  // Here we create a node to store the pose of the Imu's header frame
  // relative to the RViz fixed frame.
  frame_node_ = parent_node->createChildSceneNode();

  // We create the arrow object within the frame node so that we can
  // set its position and direction relative to its header frame.
  pole_shape_ = createEntity("pole", poleModelPath, scene_manager);
  if (pole_shape_)
    frame_node_->attachObject(pole_shape_);
}

PoleVisual::~PoleVisual()
{
  // Destroy the frame node since we don't need it anymore.
  scene_manager_->destroySceneNode( frame_node_ );
}

void PoleVisual::setMessage( const sensor_msgs::Imu::ConstPtr& msg )
{
  const geometry_msgs::Vector3& a = msg->linear_acceleration;

  // Convert the geometry_msgs::Vector3 to an Ogre::Vector3.
  Ogre::Vector3 acc( a.x, a.y, a.z );

  // Find the magnitude of the acceleration vector.
  float length = acc.length();

  // Scale the arrow's thickness in each dimension along with its length.
  Ogre::Vector3 scale( length, length, length );
  frame_node_->setScale( scale );
}

// Position and orientation are passed through to the SceneNode.
void PoleVisual::setFramePosition( const Ogre::Vector3& position )
{
  frame_node_->setPosition( position );
}

void PoleVisual::setFrameOrientation( const Ogre::Quaternion& orientation )
{
  frame_node_->setOrientation( orientation );
}

} // end namespace imu_display_imitation
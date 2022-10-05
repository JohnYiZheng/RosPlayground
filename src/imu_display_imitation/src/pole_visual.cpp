
#include <OGRE/OgreVector3.h>
#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreSceneManager.h>

#include <rviz/ogre_helpers/shape.h>

#include "imu_display_imitation/pole_visual.h"

namespace imu_display_imitation
{

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
  pole_shape_.reset(new rviz::Shape(rviz::Shape::Type::Mesh, scene_manager_, frame_node_ ));
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
  pole_shape_->setScale( scale );
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
#ifndef SRC_IMU_DISPLAY_IMITATION_INCLUDE_IMU_DISPLAY_IMITATION_POLE_DISPLAY_H_
#define SRC_IMU_DISPLAY_IMITATION_INCLUDE_IMU_DISPLAY_IMITATION_POLE_DISPLAY_H_

#include <sensor_msgs/Imu.h>
#include <rviz/message_filter_display.h>
#include <memory>

namespace Ogre
{
class SceneNode;
}

namespace imu_display_imitation {

class PoleVisual;

class PoleDisplay : public rviz::MessageFilterDisplay<sensor_msgs::Imu>
{
Q_OBJECT
public:
    PoleDisplay();
    virtual ~PoleDisplay();

protected:
    virtual void onInitialize();
    virtual void reset();
// private Q_SLOTS:
//     void updateColorAndAlpha();
//     void updateHistoryLength();
private:
    void processMessage(const sensor_msgs::Imu::ConstPtr &msg);

    std::shared_ptr<PoleVisual> visual;

    // User-editable property variables.
    // rviz::ColorProperty* color_property_;
    // rviz::FloatProperty* alpha_property_;
    // rviz::IntProperty* history_length_property_;
    
};

}

#endif  // SRC_IMU_DISPLAY_IMITATION_INCLUDE_IMU_DISPLAY_IMITATION_POLE_DISPLAY_H_

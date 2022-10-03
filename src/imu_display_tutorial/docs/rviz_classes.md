xxx_visual:
imu_visual ---- boost::shared_ptr\<rviz::Arrow>

battery_visual ---- std::vector\<std::shared_ptr\<rviz::Shape>> battery_shape_

point_visual ---- rviz::Shape* point_

effort_visual ---- std::map\<std::string, rviz::Arrow*> effort_arrow_;

wrench_visual ---- rviz::BillboardLine* circle_torque_;

covariance_visual ---- rviz::Shape* position_shape_

总结下来，共同点是，都具有一个表示形状的指针对象

这些指针均继承自rviz::Shape

rviz::Shape有一个重要的成员，为Ogre::Entity*

https://www.ogre3d.org/docs/api/1.7/class_ogre_1_1_entity.html
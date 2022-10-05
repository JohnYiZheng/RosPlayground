xxx_visual:
imu_visual ---- boost::shared_ptr\<rviz::Arrow>

battery_visual ---- std::vector\<std::shared_ptr\<rviz::Shape>> battery_shape_

point_visual ---- rviz::Shape* point_

effort_visual ---- std::map\<std::string, rviz::Arrow*> effort_arrow_;

wrench_visual ---- rviz::BillboardLine* circle_torque_;

covariance_visual ---- rviz::Shape* position_shape_

总结下来，共同点是，都具有一个表示形状的指针对象

这些指针均包含rviz::Shape
rviz shape为**固定图形**，支持Cone,Cube,Cylinder,Sphere,Mesh
可以仿照rviz shape源码自己写一个类，包装一下ogre的一些操作罢了

rviz::Shape有一个重要的成员，为Ogre::Entity*

https://www.ogre3d.org/docs/api/1.7/class_ogre_1_1_entity.html
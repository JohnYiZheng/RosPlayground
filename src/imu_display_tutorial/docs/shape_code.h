
class Shape : public Object
{
public:
  enum Type
  {
    Cone,
    Cube,
    Cylinder,
    Sphere,
    Mesh,
  };

  /**
   * \brief Constructor
   *
   * @param scene_manager The scene manager this object is associated with
   * @param parent_node A scene node to use as the parent of this object.  If NULL, uses the root scene
   * node.
   */
  Shape(Type shape_type, Ogre::SceneManager* scene_manager, Ogre::SceneNode* parent_node = nullptr);
  ~Shape() override;

  Type getType()
  {
    return type_;
  }

  /**
   * \brief Set the offset for this shape
   *
   * The default is no offset, which puts the pivot point directly in the center of the object.
   *
   * @param offset Amount to offset the center of the object from the pivot point
   */
  void setOffset(const Ogre::Vector3& offset);

  void setColor(float r, float g, float b, float a) override;
  void setColor(const Ogre::ColourValue& c);
  void setPosition(const Ogre::Vector3& position) override;
  void setOrientation(const Ogre::Quaternion& orientation) override;
  void setScale(const Ogre::Vector3& scale) override;
  const Ogre::Vector3& getPosition() override;
  const Ogre::Quaternion& getOrientation() override;

  /**
   * \brief Get the root scene node (pivot node) for this object
   *
   * @return The root scene node of this object
   */
  Ogre::SceneNode* getRootNode()
  {
    return scene_node_;
  }

  /**
   * \brief Sets user data on all ogre objects we own
   */
  void setUserData(const Ogre::Any& data) override;

  Ogre::Entity* getEntity()
  {
    return entity_;
  }

  Ogre::MaterialPtr getMaterial()
  {
    return material_;
  }

  static Ogre::Entity*
  createEntity(const std::string& name, Type shape_type, Ogre::SceneManager* scene_manager);

protected:
  Ogre::SceneNode* scene_node_;
  Ogre::SceneNode* offset_node_;
  Ogre::Entity* entity_;
  Ogre::MaterialPtr material_;
  std::string material_name_;

  Type type_;
};
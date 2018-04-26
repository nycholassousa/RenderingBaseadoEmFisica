#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "../primitives/primitive.h"
#include "../shapes/sphere.h"
#include "../shapes/triangle.h"
#include "../loader/loader.h"
#include "../materials/object.h"

class Scene
{
public:
  Scene(void);

  ~Scene(void);

  bool intersect(const Ray &ray,
                 IntersectionRecord &intersection_record) const;

  void load(void);

  void loadObject(const std::string file_name, int material_index);

  std::vector<Primitive::PrimitiveUniquePtr> primitives_;

  std::vector<Object::ObjectUniquePtr> objects_;
};

#endif /* SCENE_H_ */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <glm/glm.hpp>
#include "../primitives/primitive.h"
#include "../primitives/intersection_record.h"
#include "../primitives/ray.h"

#define EPSILON 0.000001

class Triangle : public Primitive
{
  public:
	Triangle(void);

	Triangle(const glm::vec3 &vertex0, const glm::vec3 &vertex1, const glm::vec3 &vertex2);

	bool intersect(const Ray &ray,
				   IntersectionRecord &intersection_record) const;

	glm::vec3 vertex0_ = {0.0f, 0.0f, 0.0f};
	glm::vec3 vertex1_ = {0.0f, 0.0f, 0.0f};
	glm::vec3 vertex2_ = {0.0f, 0.0f, 0.0f};

  private:
	static const float kIntersectionTestEpsilon_;
};

#endif /* TRIANGLE_H_ */

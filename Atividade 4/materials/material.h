#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <glm/glm.hpp>

struct Material
{
    glm::vec3 emittance_;
    glm::vec3 reflectance_;
    glm::vec3 (*brdf_pointer)(const glm::vec3 &reflectance);
    glm::vec3 brdf(void);

    static glm::vec3 diffuse(const glm::vec3 &reflectance);
};

#endif /* MATERIAL_H_ */
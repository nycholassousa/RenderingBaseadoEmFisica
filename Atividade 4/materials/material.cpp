#include "material.h"

glm::vec3 Material::diffuse(const glm::vec3 &reflectance)
{
    return reflectance / float(M_PI);
}

glm::vec3 Material::brdf(void)
{
    return brdf_pointer(reflectance_);
}
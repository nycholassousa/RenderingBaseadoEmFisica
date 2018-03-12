#include "triangle.h"

Triangle::Triangle(void)
{
}

Triangle::Triangle(const glm::vec3 &vertex0, const glm::vec3 &vertex1, const glm::vec3 &vertex2) : vertex0_{vertex0},
                                                                                                   vertex1_{vertex1},
                                                                                                   vertex2_{vertex2}
{
}

bool Triangle::intersect(const Ray &ray,
                         IntersectionRecord &intersection_record) const
{
    /* Find vectors for two edges sharing vert0 */
    glm::vec3 edge1 = vertex1_ - vertex0_;
    glm::vec3 edge2 = vertex2_ - vertex0_;

    /* Begin calculating determinant - also used to calculate U parameter*/
    glm::vec3 pvec = glm::cross(ray.direction_, edge2);

    /* If determinant is near zero, ray lies in plane or triangle */
    float det = glm::dot(edge1, pvec);

    if (det > -EPSILON && det < EPSILON)
        return false;

    float inv_det = 1.0 / det;

    /* Calculate distance from vert0 to ray origin */
    glm::vec3 tvec = ray.origin_ - vertex0_;

    /* Calculate U parameter and test bounds */
    float u = glm::dot(tvec, pvec) * inv_det;
    if (u < 0.0 || u > 1.0)
        return false;

    /* Prepare to test V parameter */
    glm::vec3 qvec = glm::cross(tvec, edge1);

    /* Calculate V parameter and test bounds */
    float v = glm::dot(ray.direction_, qvec) * inv_det;
    if (v < 0.0 || u + v > 1.0)
        return false;

    /* Calculate t, ray intersects triangle */
    intersection_record.t_ = glm::dot(edge2, qvec) * inv_det;
    intersection_record.normal_ = glm::cross(edge1, edge2);

    ///The point that the ray intercects the triangle
    intersection_record.position_ = ray.origin_ + ray.direction_ * (intersection_record.t_);
    intersection_record.object = this;

    return true;
}

#ifndef PATHTRACER_H_
#define PATHTRACER_H_

#include <sstream>
#include <iomanip>
#include <cmath>
#include <random>
#include <atomic>
#include <chrono>
#include <thread>

#include "../camera/camera.h"
#include "../scenes/scene.h"
#include "../buffer/buffer.h"

class PathTracer
{
public:
  PathTracer(Camera &camera,
             const Scene &scene,
             const glm::vec3 background_color,
             Buffer &buffer);

  // void integrate( void );

  void integrate(const int num_threads = 4, const int num_rays = 10);

  void integrateParallel(const int num_rays);

  glm::vec3 L(const Ray &r, int depth,
              std::uniform_real_distribution<float> &theta,
              std::uniform_real_distribution<float> &phi,
              std::mt19937 &generator);

  void progressStatus();

private:
  const Camera &camera_;

  const Scene &scene_;

  glm::dvec3 background_color_;

  Buffer &buffer_;

  std::atomic<int> block{0};
};

#endif /* PATHTRACER_H_ */

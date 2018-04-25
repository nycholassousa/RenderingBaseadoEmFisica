#include "main.h"

int main(void)
{
    unsigned int x_resolution = 512;
    unsigned int y_resolution = 512;

    PerspectiveCamera camera{-1.0f,
                             1.0f,
                             -1.0f,
                             1.0f,
                             glm::ivec2{x_resolution, y_resolution},
                             glm::vec3{1.0f, 0.0f, 2.0f},  // position
                             glm::vec3{0.0f, 1.0f, 0.0f},  // up
                             glm::vec3{0.0f, 0.0f, -1.0f}, // look at
                             1.0f};
    Scene scene{};

    scene.load();

    Buffer rendering_buffer{x_resolution, y_resolution};
    glm::vec3 background_color{0.0f, 0.0f, 0.0f};

    // Set up the renderer.
    RayTracer rt(camera,
                 scene,
                 background_color,
                 rendering_buffer);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); //Staring to count time
    const int num_threads = 4;
    std::thread *threads[num_threads];
    std::thread control{&RayTracer::print_progress, &rt};

    for (int i = 0; i < num_threads; i++)
        threads[i] = new std::thread{&RayTracer::integrate, &rt};

    for (int i = 0; i < num_threads; i++)
    {
        threads[i]->join();
        delete threads[i];
    }

    control.join();

    // Save the rendered image to a .ppm file.
    rendering_buffer.save("output_image.ppm");
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); //Ending counting time

    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000 << " seconds" << std::endl;
    return EXIT_SUCCESS;
}

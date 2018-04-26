#include "main.h"

int depthMain = 0;

int main(int argc, char *argv[])
{

    if (argc != 5){
        std::cout << "How to Use:" << std::endl;
        std::cout << "./swpathtracer spp depth numThreads fileName\n";
        std::cout << "spp: Samples Per Pixel\n"
                  << "depth: Maximum ray depth\n"
                  << "num_threads: Number of Threads (recommended 4)\n" 
                  << "file_name: Output filename\n" << std::endl;
        std::cout << "Example: ./swpathtracer 100 5 4 output" << std::endl;

        return EXIT_FAILURE;
    }

    int spp = strtol(argv[1], NULL, 10);
    depthMain = strtol(argv[2], NULL, 10);
    int num_threads = strtol(argv[3], NULL, 10);
    std::string output_file = std::string(argv[4]) + ".ppm";

    unsigned int x_resolution = 512;
    unsigned int y_resolution = 512;

    PerspectiveCamera camera{-1.0f,
                             1.0f,
                             -1.0f,
                             1.0f,
                             glm::ivec2{x_resolution, y_resolution},
                             glm::vec3{0.0f, 1.0f, 2.5f},  // position
                             glm::vec3{0.0f, 1.0f, 0.0f},  // up
                             glm::vec3{0.0f, 0.0f, -1.0f}, // look at
                             1.0f};
    Scene scene{};

    scene.load();

    Buffer rendering_buffer{x_resolution, y_resolution};
    glm::vec3 background_color{0.0f, 0.0f, 0.0f};

    // Set up the renderer.
    PathTracer pt(camera,
                 scene,
                 background_color,
                 rendering_buffer);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); //Staring to count time
    pt.integrate(num_threads, spp);                                                 // Renders the final image.
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();   //Ending counting time

    // Save the rendered image to a .ppm file.
    rendering_buffer.save(output_file);
    std::cout << "Elapsed Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000 << " seconds" << std::endl;

    return EXIT_SUCCESS;
}

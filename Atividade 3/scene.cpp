#include "scene.h"

Scene::Scene(void)
{
}

Scene::~Scene(void)
{
}

bool Scene::intersect(const Ray &ray,
                      IntersectionRecord &intersection_record) const
{
    bool intersection_result = false;
    IntersectionRecord tmp_intersection_record;
    std::size_t num_primitives = primitives_.size();

    // Loops over the list of primitives, testing the intersection of each primitive against the given ray
    for (std::size_t primitive_id = 0; primitive_id < num_primitives; primitive_id++)
        if (primitives_[primitive_id]->intersect(ray, tmp_intersection_record))
            if ((tmp_intersection_record.t_ < intersection_record.t_) && (tmp_intersection_record.t_ > 0.0))
            {
                intersection_record = tmp_intersection_record;
                intersection_result = true; // the ray intersects a primitive!
            }

    return intersection_result;
}

void Scene::load(void)
{
    //Spheres
    
    //Sphere 1
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.0f, 0.0f,  0.0f }, 0.2f } ) );
    primitives_.back()->color = glm::vec3{ rand()%256/255.0,rand()%256/255.0,rand()%256/255.0};
    //Sphere 2
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, 0.0f, -1.0f }, 0.2f } ) );
    primitives_.back()->color = glm::vec3{ rand()%256/255.0,rand()%256/255.0,rand()%256/255.0};
    //Sphere 3
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.0f,-0.5f, -2.0f }, 0.2f } ) );
    primitives_.back()->color = glm::vec3{ rand()%256/255.0,rand()%256/255.0,rand()%256/255.0};
    //Sphere 4
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.0f, 0.5f, -3.0f }, 0.2f } ) );
    primitives_.back()->color = glm::vec3{ rand()%256/255.0,rand()%256/255.0,rand()%256/255.0};
    

    //Triangles
    /*
    //Triangle 1
    glm::vec3 vertex0 = { 0.9f, 0.9f, 0.0f };
    glm::vec3 vertex1 = { 0.9f , -0.9f , 0.0f };
    glm::vec3 vertex2 = { 0.3f , 0.3f , 0.3f}; 
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle{ vertex0, vertex1, vertex2 } ) );
    primitives_.back()->color = glm::vec3{ rand()%256/255.0,rand()%256/255.0,rand()%256/255.0};

    //Triangle 2
    vertex0 = { -1.0f, 1.0f, -3.0f };
    vertex1 = { 1.0f , 1.0f , -3.0f };
    vertex2 = { 0.0f , 0.0f , -3.0f}; 
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle{ vertex0, vertex1, vertex2 } ) );
    primitives_.back()->color = glm::vec3{ rand()%256/255.0,rand()%256/255.0,rand()%256/255.0};

    //Triangle 3
    vertex0 = { -0.9f, 0.0f, -1.0f };
    vertex1 = { -0.9f , 0.5f , -1.0f };
    vertex2 = { 0.0f , -0.0f , -1.0f}; 
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle{ vertex0, vertex1, vertex2 } ) );
    primitives_.back()->color = glm::vec3{ rand()%256/255.0,rand()%256/255.0,rand()%256/255.0};
    */
    

    //OBJ Loader
    /*
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvs;
    std::vector<Indexed_Face> faces;
    int vertex_count;
    int normal_count;
    int uv_count;
    int face_count;

    load_data("monkey_head2.obj",
              vertices,
              normals,
              uvs,
              faces,
              vertex_count,
              normal_count,
              uv_count,
              face_count);

    for (int i = 0; i < face_count; i++)
    {
        primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle{
            vertices[faces[i].vertices[0] - 1],
            vertices[faces[i].vertices[1] - 1],
            vertices[faces[i].vertices[2] - 1]}));

        primitives_.back()->color = glm::vec3{rand() % 256 / 255.0,
                                              rand() % 256 / 255.0,
                                              rand() % 256 / 255.0};
    }
    */
}

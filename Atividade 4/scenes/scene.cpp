#include "scene.h"

Scene::Scene( void )
{}

Scene::~Scene( void )
{}

bool Scene::intersect( const Ray &ray,
					   IntersectionRecord &intersection_record ) const
{
	bool intersection_result = false;
	IntersectionRecord tmp_intersection_record;
	intersection_record.t_ = std::numeric_limits< double >::max();
	//std::size_t num_primitives = primitives_.size();
	std::size_t num_objects = objects_.size();
	std::size_t num_primitives;

	// Loops over the list of primitives, testing the intersection of each primitive against the given ray 
	// for ( std::size_t primitive_id = 0; primitive_id < num_primitives; primitive_id++ )
	// 	if ( primitives_[primitive_id]->intersect( ray, tmp_intersection_record ) )
	// 		if ( ( tmp_intersection_record.t_ < intersection_record.t_ ) && ( tmp_intersection_record.t_ > 0.0 ) )
	// 		{
	// 			intersection_record = tmp_intersection_record;
	// 			intersection_result = true; // the ray intersects a primitive!
	// 		}

	// Loops over the list of primitives, testing the intersection of each primitive against the given ray 
	for ( std::size_t object_id = 0; object_id < num_objects; object_id++ ){
		
		num_primitives = objects_[object_id]->primitives_.size();

		for ( std::size_t primitive_id = 0; primitive_id < num_primitives; primitive_id++ )
			if ( objects_[object_id]->primitives_[primitive_id]->intersect( ray, tmp_intersection_record ) )
				if ( ( tmp_intersection_record.t_ < intersection_record.t_ ) && ( tmp_intersection_record.t_ > 0.0 ) )
				{
					intersection_record = tmp_intersection_record;
					intersection_result = true; // the ray intersects a primitive!
				}
	}

	return intersection_result;
}

void Scene::load( void ) {
	
	// Material m1 = {glm::vec3{0.0f, 0.0f, 0.0f}, Material::diffuse_gray};
	// Material m2 = {glm::vec3{30.0f, 30.0f, 30.0f}, nullptr};

	// Object::material_list.push_back(m1);
	// Object::material_list.push_back(m2);

	// objects_.push_back(Object::ObjectUniquePtr(new Object));
	// objects_.back()->primitives_.push_back(Primitive::PrimitiveUniquePtr(new Sphere{
	// 															glm::vec3{ 0.0f, 2.0f, 0.0f},
	// 															1.0f} ));

	// //primitives_.back()->color = glm::vec3{ 30.0f, 30.0f, 30.0f};
	// objects_.back()->primitives_.back()->material_index = 1;
	// //primitives_.back()->emiter = true;
	
	// objects_.push_back(Object::ObjectUniquePtr(new Object));

	// std::vector<glm::vec3> vertices;
	// std::vector<glm::vec3> normals;
	// std::vector<glm::vec2> uvs;
	// std::vector<Indexed_Face> faces;
	// int vertex_count;
	// int normal_count; 
	// int uv_count;
	// int face_count;

	// load_data(	"objects/monkey90.obj",
	// 			vertices, 
	// 			normals, 
	// 			uvs, 
	// 			faces, 
	// 			vertex_count, 
	// 			normal_count, 
	// 			uv_count, 
	// 			face_count); 

	// for(int i = 0; i < face_count; i++){
	// 	objects_.back()->primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle{ 
	// 																vertices[faces[i].vertices[0]-1],
	// 																vertices[faces[i].vertices[1]-1],
	// 																vertices[faces[i].vertices[2]-1]}));
		
	// 	//primitives_.back()->color = glm::vec3{ 0.5f, 0.5f, 0.5f};
	// 	objects_.back()->primitives_.back()->material_index = 0;
	// }

	Material m0 = {glm::vec3{0.0f}, Material::diffuse_white};
	Material m1 = {glm::vec3{0.0f}, Material::diffuse_gray};
	Material m2 = {glm::vec3{0.0f}, Material::diffuse_red};
	Material m3 = {glm::vec3{0.0f}, Material::diffuse_green};
	Material m4 = {glm::vec3{37.0f, 32.0f, 24.0f}, Material::diffuse_yellow}; //24.0f

	Object::material_list.push_back(m1);
	Object::material_list.push_back(m2);
	Object::material_list.push_back(m3);
	Object::material_list.push_back(m4);
	Object::material_list.push_back(m0);

	loadObject("objs/cornell_box01.obj", 0);
	loadObject("objs/cornell_box02.obj", 1);
	loadObject("objs/cornell_box03.obj", 2);
	loadObject("objs/cornell_box04.obj", 3);	
}

void Scene::loadObject(const std::string file_name, int material_index){

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	std::vector<Indexed_Face> faces;
	int vertex_count;
	int normal_count; 
	int uv_count;
	int face_count;
	
	objects_.push_back(Object::ObjectUniquePtr(new Object));

	load_data(	file_name,
				vertices, 
				normals, 
				uvs, 
				faces, 
				vertex_count, 
				normal_count, 
				uv_count, 
				face_count); 

	for(int i = 0; i < face_count; i++){
		objects_.back()->primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle{ 
																	vertices[faces[i].vertices[0]-1],
																	vertices[faces[i].vertices[1]-1],
																	vertices[faces[i].vertices[2]-1]}));

		objects_.back()->primitives_.back()->material_index = material_index;
	}

}
#ifndef OBJECT_H
#define OBJECT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <array>

#include "emuns.h"

class Object
{
public:
    Object() = delete;
    Object(Objects obj);
    Object(Objects obj, float size);
	~Object();

    void Move(glm::vec3 move_vec);
    void Scale(glm::vec3 scale_vec);
    void Rotate(glm::vec3 rot_vec, float angle);

    glm::mat4 GetObjMatrix();

private:
    Objects     m_type;
    glm::mat4   m_position;

};

class Camera
{
public:
	Camera();
	~Camera(){};

    glm::mat4 GetProjMatrix();
    glm::mat4 GetLookMatrix();

private:
	glm::mat4	m_look_at;
    glm::mat4   m_proj_matrix;
};

#endif //OBJECT_H
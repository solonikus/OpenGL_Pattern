
#ifndef SCENE_H
#define SCENE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>
#include <vector>

#include "emuns.h"
#include "object.h"
#include "shader.h"

class GLEngine
{
public:
	GLEngine();
	~GLEngine(){};

	GLuint m_vao, m_vbo, m_ebo;
	GLFWwindow   *window;

private:

	void InputKeys(GLFWscrollfun, GLFWmousebuttonfun, GLFWcursorposfun, GLFWkeyfun);
	void BindKeys(int);
};

class Scene : public GLEngine
{
public:
	Scene();
	~Scene();

	std::vector<Object> m_objects;
	ShaderManage		m_shaders;
	Camera				m_camera;

	std::vector<float>	m_array_vertex;
	std::vector<int>	m_array_indexes;

	void InitScene();
	void AddObject(Objects obj);
	void Loop();

	int GetShaderID(){return m_shaders.GetShaderId();};
};

#endif //SCENE_H
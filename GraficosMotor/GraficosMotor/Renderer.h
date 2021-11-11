#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ZENGINE_API Renderer
{
protected:
	
	float color[4] = { 0.1f,0.1f,0.1f,1.0f };//Maneja el color de la pantalla
	float color2[4] = { 0.1f,0.1f,0.1f,1.0f };
	glm::mat4 ViewMatrix;
	glm::mat4 CameraMatrix;
	glm::mat4 projectionMatrix;
	glm::mat4 MVPmatrix;
	GLFWwindow* wind;
public:
	Renderer(GLFWwindow * win);
	~Renderer();
	void UpdateWindow();
	void MoveEntity(float speed,std::string moveDirection);
	void ScaleEntity(float scale);
	void ModifyScaleEntity(float scale);
	void RotationXEntity(float _angle);
	void RotationYEntity(float _angle);
	void RotationZEntity(float _angle);
	void SetColorBackground(float a, float b, float c);//Cambia el color de la ventana
	void setColorBackground(float a, float b, float c, float d);//Cambia el color y el alpha de la ventana
	void FreeMemory();
	void Draw(int count);
	//Camera
	void ConfigCamera();

};


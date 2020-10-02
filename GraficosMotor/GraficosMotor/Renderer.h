#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include <iostream>
#include "Entity.h"

class ZENGINE_API Renderer
{
protected:
	float color[4] = { 0.1f,0.1f,0.1f,1.0f };//Maneja el color de la pantalla
	float color2[4] = { 0.1f,0.1f,0.1f,1.0f };
	Entity * ent;
public:
	Renderer();
	~Renderer();
	void UpdateWindow(GLFWwindow* win);
	void MoveEntity(float speed,std::string moveDirection);
	void ScaleEntity(float scale);
	void SetColorBackground(float a, float b, float c);//Cambia el color de la ventana
	void setColorBackground(float a, float b, float c, float d);//Cambia el color y el alpha de la ventana
};


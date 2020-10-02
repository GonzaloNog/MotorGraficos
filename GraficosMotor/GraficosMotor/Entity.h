#pragma once
#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ZENGINE_API Entity
{
protected:
	float positions[6] = {
		-0.5f, -0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};
	glm::vec3 * position = new glm::vec3(0.0f, 0.0f, 0.0f);
	float rotationX = 0.f;
	float rotationY = 0.f;
	float rotationZ = 0.f;
	float scale = 1.f;
	//glm::mat4 * ModelMatrix =  new glm::mat4(1.f);
public:
	Entity();
	~Entity();
	void Draw(std::string figure, glm::mat4 camera);
	void TrasformPosition(float pos[6]);
	void MovePosition(float Speed, std::string MoveDirection);
	void RotationX(float angle);
	void RotationY(float angle);
	void RotationZ(float angle);
	void Scale(float _scale);
	void ModifyScale(float _scale);
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	static unsigned int CompileShader(const std::string& source, unsigned int type);
private:
	int CodeString(std::string code);
	void DrawTriangle(glm::mat4 camera);
	int LongitudArray();
};


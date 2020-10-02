#pragma once
#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include <iostream>
#include <math.h>

class ZENGINE_API Entity
{
protected:
	float positions[6] = {
		-0.5f, -0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};
	float scaleBase[6] = {
		-0.5f, -0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};
public:
	Entity();
	~Entity();
	void Draw(std::string figure);
	void TrasformPosition(float pos[6]);
	void MovePosition(float Speed, std::string MoveDirection);
	void Rotation(std::string eje, float angle);
	void Scale(float scale);
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	static unsigned int CompileShader(const std::string& source, unsigned int type);
private:
	int CodeString(std::string code);
	void DrawTriangle();
	int LongitudArray();
};


#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include <iostream>
#include "Renderer.h"
#include "Material.h"
#include "Timer.h"
#include "Animator.h"

class ZENGINE_API Entity
{
protected:
	Renderer* ren;
	Material* material = nullptr;
	Animator* anim = nullptr;
	float positions[32] = {
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   
		 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   
		-0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f    
	};
	glm::vec3 * position = new glm::vec3(0.0f, 0.0f, 0.0f);
	float rotationX = 0.f;
	float rotationY = 0.f;
	float rotationZ = 0.f;
	//float scale = 1.f;
	glm::vec3 * scale = new glm::vec3(1.0f, 1.0f, 1.0f);
	float * frame = new float[8]{1.0f,1.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f};
	//glm::mat4 * ModelMatrix =  new glm::mat4(1.f);
	float elapsedTIme = 0.0f;
	float frames = 0;
	unsigned int indices[6]{
		0, 1, 3,
		1, 2, 3
	};
	unsigned int buffer, VAO, EBO;
public:
	Entity();
	Entity(Renderer* ren);
	Entity(float x, float y, Renderer * rend);
	~Entity();
	void Draw();
    virtual void Draw(std::string figure, glm::mat4 camera);
	void TrasformPosition(float pos[6]);
	void MovePosition(float Speed, std::string MoveDirection);
	void RotationX(float angle);
	void RotationY(float angle);
	void RotationZ(float angle);
	void Scale(float _scale);
	void Scale(float x, float y, float z);
	void ScalePlus(float _scalePlus);
	void ScalePlus(float xPlus, float yPlus, float zPlus);
	void AspectRatio(float x, float y);
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader, unsigned int * program);
	static unsigned int CompileShader(const std::string& source, unsigned int type);
	void FreeMemory();
	int LongitudArray();
	virtual int CodeString(std::string code);
	void AddComponent(std::string comp);
	Material* GetMaterial();
	Animator* GetAnimator();
	void SetTextCords();
};


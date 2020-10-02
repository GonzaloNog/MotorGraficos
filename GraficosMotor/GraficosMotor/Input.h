#include <glew.h>
#include <glfw3.h>
#include "Exports.h"
#include <iostream>

class ZENGINE_API Input
{
protected:
	GLFWwindow* wind;
public:
	Input();
	~Input();
	void Initialize(GLFWwindow * _windows);
	bool PressedKey(std::string keyCode, std::string tipe); // tipe Press, Released, Repeat
};


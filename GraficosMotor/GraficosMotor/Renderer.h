#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include <iostream>

class ZENGINE_API Renderer
{
protected:
	
public:
	Renderer();
	~Renderer();
	void DrawTriangle(GLFWwindow* win);
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	static unsigned int CompileShader(const std::string& source, unsigned int type);
};


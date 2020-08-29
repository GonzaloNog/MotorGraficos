#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Exports.h"
#include <vector>

class ZENGINE_API Windows
{
private:
protected:
	float color[4] = {0.1f,0.1f,0.1f,1.0f};
	GLFWwindow* window;
public:
	Windows();
	~Windows();
	void Open(int x, int y, std::string name);
	bool IsOpen();
	void SetColorBackground(float a, float b, float c);
	void setColorBackground(float a, float b, float c, float d);
};


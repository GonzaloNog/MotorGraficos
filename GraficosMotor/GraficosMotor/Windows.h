#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Exports.h"

class ZENGINE_API Windows
{
private:
protected:
	
	GLFWwindow* window;
public:
	Windows();
	~Windows();
	void Open(int x, int y, std::string name);
	bool IsOpen();
};


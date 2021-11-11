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
	GLFWwindow* window;//Puntero de una ventana GLFW
public:
	Windows();
	~Windows();
	void Open(int x, int y, std::string name);//Crea una ventana nueva con GLFW
	bool IsOpen();//Comprueba si la ventana esta abierta 
	void FreeMemory();
	void Close();
	GLFWwindow* GetWindows();
};


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
	float color[4] = {0.1f,0.1f,0.1f,1.0f};//Maneja el color de la pantalla
	GLFWwindow* window;//Puntero de una ventana GLFW
public:
	Windows();
	~Windows();
	void Open(int x, int y, std::string name);//Crea una ventana nueva con GLFW
	bool IsOpen();//Comprueba si la ventana esta abierta 
	void SetColorBackground(float a, float b, float c);//Cambia el color de la ventana
	void setColorBackground(float a, float b, float c, float d);//Cambia el color y el alpha de la ventana
	void UpdateWindows();//Refresca la pantalla (frame)
	GLFWwindow* GetWindows();
	//Render
	//static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
};


#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include "Input.h"
#include "Windows.h"
#include <string>

class ZENGINE_API BaseGame
{
private:

protected:
	Windows* window;//puntero de la clase de windows
	Input* input;
public:
	BaseGame();
	~BaseGame();
	//Windows
	void OpenWindows(int x, int y, std::string name);//Le pide a la clase Windows que cree una ventana
	void Update();//Update del motor
	void SetColorBackground(float a, float b, float c);//Le pide a la clase Windows que cambia el color del fondo 
	void SetColorBackground(float a, float b, float c, float d);// Le pide a la clase Windows que cambia el color de fondo y el alpha
	void UpdateWindows();
	//Render
	void DrawTriangle();
	//Input
	bool GetKay(std::string _kay);
};


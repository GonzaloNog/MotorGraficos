#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include "Input.h"
#include "Windows.h"
#include "Renderer.h"
#include <string>
#include <iostream>

class ZENGINE_API BaseGame
{
private:

protected:
	Windows* window;//puntero de la clase de windows
	Input* input;
	Renderer* rend;
public:
	BaseGame();
	~BaseGame();
	//Windows
	void OpenWindows(int x, int y, std::string name);//Le pide a la clase Windows que cree una ventana
	void Update();//Update del motor
	//Render
	void MoveEntity(float speed, std::string moveDirection);
	void ScaleEntity(float scale);
	void SetColorBackground(float a, float b, float c);//Le pide a la clase Windows que cambia el color del fondo 
	void SetColorBackground(float a, float b, float c, float d);// Le pide a la clase Windows que cambia el color de fondo y el alpha
	void UpdateWindow();
	//Input
	bool GetKay(std::string _kay,std::string tipe);
};


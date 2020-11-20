#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include "Input.h"
#include "Windows.h"
#include <string>
#include <iostream>
#include "Shape.h"
#include "Timer.h"
#include "ColliderControler.h"
//#include <vl>

class ZENGINE_API BaseGame
{
protected:
	Windows* window;//puntero de la clase de windows
	Input* input;
	Renderer* rend;
	//Secuencia de ejecucion
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Delete() = 0;
	//Timer
	EngineUtils::Timer* timer = EngineUtils::Timer::Instance();
	EngineUtils::ColliderControler* coll = EngineUtils::ColliderControler::Instance();

public:
	BaseGame();
	~BaseGame();
	
	//Windows
	void OpenWindows(int x, int y, std::string name);//Le pide a la clase Windows que cree una ventana
	void Play();//Inicia el motors
	void CloseWindow();
	//Render
	void MoveEntity(float speed, std::string moveDirection);
	void ScaleEntity(float scale);
	void ModifyScaleEntity(float scale);
	void RotationXEntity(float _angle);
	void RotationYEntity(float _angle);
	void RotationZEntity(float _angle);
	void SetColorBackground(float a, float b, float c);//Le pide a la clase Windows que cambia el color del fondo 
	void SetColorBackground(float a, float b, float c, float d);// Le pide a la clase Windows que cambia el color de fondo y el alpha
	void FreeMemory();
	void UpdateWindow();
	Entity * NewEntity();
	Renderer* GetRenderer();
	//Input
	bool GetKay(std::string _kay,std::string tipe);
	void EngineUpdate();
};


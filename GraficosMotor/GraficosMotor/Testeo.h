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

class Testeo
{
public:	
	virtual void intento() {
		std::cout << "hola";
	}	
	Testeo();
	~Testeo();
};


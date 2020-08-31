#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Windows.h"

class ZENGINE_API Input
{
protected:
	Windows* wind;
public:
	Input();
	~Input();
	void Initialize(Windows * _windows);
	bool PressedKey(std::string keyCode);
};


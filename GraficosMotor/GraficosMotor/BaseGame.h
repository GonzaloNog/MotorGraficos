#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "Exports.h"
#include "Windows.h"
#include <string>

class ZENGINE_API BaseGame
{
private:

protected:
	Windows* window;
public:
	BaseGame();
	~BaseGame();
	void OpenWindows(int x, int y, std::string name);
	void DrawTriangle();
	void Update();
};


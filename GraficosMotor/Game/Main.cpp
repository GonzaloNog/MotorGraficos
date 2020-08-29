#include <stdio.h>
#include <stdlib.h>

#include"Game.h"

int main() {
	Game * b = new Game();
	b->OpenWindows(500,500, "gonzalo");
	b->SetColorBackground(0.9f, 0.5f, 0.5f,0.5f);
	b->OpenWindows(800, 800, "eduardo");
	
	//b->Update();
}
#include "BaseGame.h"


BaseGame::BaseGame() {

}
BaseGame::~BaseGame() {
	
}
void BaseGame::OpenWindows(int x, int y, std::string name) {
	window = new Windows();
	window->Open(x, y, name);
}
void BaseGame::DrawTriangle() {

}
void BaseGame::Update() {
	while (window->IsOpen()) {

	}
}
void BaseGame::SetColorBackground(float a, float b, float c) {
	window->SetColorBackground(a, b, c);
}
void BaseGame::SetColorBackground(float a, float b, float c, float d) {
	window->setColorBackground(a,b,c,d);
}

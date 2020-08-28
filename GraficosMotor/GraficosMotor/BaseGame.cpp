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

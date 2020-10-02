#include "BaseGame.h"


BaseGame::BaseGame() {

}
BaseGame::~BaseGame() {
	
}
// WIDNOWS
void BaseGame::OpenWindows(int x, int y, std::string name) {
	window = new Windows();
	window->Open(x, y, name);
	input = new Input();
	rend = new Renderer();
	input->Initialize(window->GetWindows());
}
void BaseGame::Update() {
	while (window->IsOpen()) {

	}
}

// RENDERER
void BaseGame::SetColorBackground(float a, float b, float c) {
	rend->SetColorBackground(a, b, c);
}
void BaseGame::SetColorBackground(float a, float b, float c, float d) {
	rend->setColorBackground(a,b,c,d);
}
void BaseGame::UpdateWindow() {
	rend->UpdateWindow(window->GetWindows());
}
void BaseGame::MoveEntity(float speed, std::string moveDirection) {
	rend->MoveEntity(speed, moveDirection);
}
void BaseGame::ScaleEntity(float scale) {
	rend->ScaleEntity(scale);
}

// INPUT
bool BaseGame::GetKay(std::string _kay, std::string tipe) {
	return input->PressedKey(_kay,tipe);
}

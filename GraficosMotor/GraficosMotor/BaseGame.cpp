#include "BaseGame.h"


BaseGame::BaseGame() {

}
BaseGame::~BaseGame() {
	
}
void BaseGame::OpenWindows(int x, int y, std::string name) {
	window = new Windows();
	input = new Input();
	rend = new Renderer();
	window->Open(x, y, name);
	input->Initialize(window->GetWindows());
}
void BaseGame::DrawTriangle() {
	rend->DrawTriangle(window->GetWindows());
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
void BaseGame::UpdateWindows() {
	window->UpdateWindows();
}
bool BaseGame::GetKay(std::string _kay) {
	return input->PressedKey(_kay);
}

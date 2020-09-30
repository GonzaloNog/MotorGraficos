#include "BaseGame.h"


BaseGame::BaseGame() {

}
BaseGame::~BaseGame() {
	
}
void BaseGame::OpenWindows(int x, int y, std::string name) {
	window = new Windows();
	window->Open(x, y, name);
	input = new Input();
	input->Initialize(window->GetWindows());
}
void BaseGame::DrawTriangle() {
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
}
void BaseGame::Update() {
	while (window->IsOpen()) {

	}
}
void BaseGame::SetColorBackground(float a, float b, float c) {
	rend->SetColorBackground(a, b, c);
}
void BaseGame::SetColorBackground(float a, float b, float c, float d) {
	rend->setColorBackground(a,b,c,d);
}
void BaseGame::UpdateWindow() {
	rend->UpdateWindow(window->GetWindows());
}
bool BaseGame::GetKay(std::string _kay) {
	return input->PressedKey(_kay);
}

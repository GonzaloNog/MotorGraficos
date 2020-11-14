#include "BaseGame.h"


BaseGame::BaseGame() {

}
BaseGame::~BaseGame() {

}
void BaseGame::FreeMemory() {
	EngineUtils::Timer::Release();
	window->FreeMemory();
	delete window;
	rend->FreeMemory();
	delete rend;
	delete input;
}
void BaseGame::Play() {
	Start();
	while (window->IsOpen()) {
		Update();
	}
	Delete();
}	
// WIDNOWS
void BaseGame::OpenWindows(int x, int y, std::string name) {
	window = new Windows();
	window->Open(x, y, name);
	input = new Input();
	rend = new Renderer(window->GetWindows());
	input->Initialize(window->GetWindows());
}
void BaseGame::CloseWindow() {
	window->Close();
}


// RENDERER
void BaseGame::SetColorBackground(float a, float b, float c) {
	rend->SetColorBackground(a, b, c);
}
void BaseGame::SetColorBackground(float a, float b, float c, float d) {
	rend->setColorBackground(a,b,c,d);
}
void BaseGame::UpdateWindow() {
	rend->UpdateWindow();
}
void BaseGame::MoveEntity(float speed, std::string moveDirection) {
	rend->MoveEntity(speed, moveDirection);
}
void BaseGame::ScaleEntity(float scale) {
	rend->ScaleEntity(scale);
}
void BaseGame::ModifyScaleEntity(float scale) {
	rend->ModifyScaleEntity(scale);
}
void BaseGame::RotationXEntity(float _angle) {
	rend->RotationXEntity(_angle);
}
void BaseGame::RotationYEntity(float _angle) {
	rend->RotationYEntity(_angle);
}
void BaseGame::RotationZEntity(float _angle) {
	rend->RotationZEntity(_angle);
}
Entity * BaseGame::NewEntity() {
	Entity * aux = new Entity(rend);
	return aux;
}

// INPUT
bool BaseGame::GetKay(std::string _kay, std::string tipe) {
	return input->PressedKey(_kay,tipe);
}

//TImer
void BaseGame::TimeUpdate() {
	EngineUtils::Timer::Instance()->Tick();
	EngineUtils::Timer::Instance()->Reset();
}

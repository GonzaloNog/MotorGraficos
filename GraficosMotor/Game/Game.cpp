#include "Game.h"

Game::Game() {

}
Game::~Game() {

}
void Game::Loop() {
	OpenWindows(500, 500, "gonzalo");
	while (running) {
		UpdateWindows();
		if (GetKay("space")) {
			SetColorBackground(0.5f,0.7f,0.3f);
		}
	}
}
//Set y Get
void Game::SetRunning(bool _running) {
	running = _running;
}
bool Game::GetRunning() {
	return running;
}

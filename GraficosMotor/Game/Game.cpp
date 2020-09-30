#include "Game.h"

Game::Game() {

}
Game::~Game() {

}
void Game::Loop() {
	std::cout << "Open Windows"<<std::endl;
	OpenWindows(500, 500, "gonzalo");
	std::cout << "Start Loop" << std::endl;
	while (running) {
<<<<<<< Updated upstream
		UpdateWindows();
=======
		//DrawTriangle();
		UpdateWindow();
>>>>>>> Stashed changes
		if (GetKay("space")) {
			std::cout << "space press" << std::endl;
			SetColorBackground(0.1f,0.7f,0.3f);
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

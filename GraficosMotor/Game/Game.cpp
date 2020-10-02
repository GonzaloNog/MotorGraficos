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
		UpdateWindow();
		if (GetKay("space","Press")) {
			std::cout << "space press" << std::endl;
			SetColorBackground(0.1f,0.7f,0.3f);
		}
		if (GetKay("w", "Press")) {
			MoveEntity(0.001,"Up");
			std::cout << "W press" << std::endl;
		}
		if (GetKay("s", "Press")) {
			MoveEntity(0.001, "Down");
			std::cout << "W press" << std::endl;
		}
		if (GetKay("a", "Press")) {
			MoveEntity(0.001, "Left");
			std::cout << "W press" << std::endl;
		}
		if (GetKay("d", "Press")) {
			MoveEntity(0.001, "Right");
			std::cout << "W press" << std::endl;
		}
		if (GetKay("q", "Press")) {
			//ScaleEntity(0.5);
			ModifyScaleEntity(0.005);
			std::cout << "W press" << std::endl;
		}
		if (GetKay("e", "Press")) {
			//ScaleEntity(2);
			ModifyScaleEntity(-0.005);
			std::cout << "W press" << std::endl;
		}
		if (GetKay("1", "Press")) {
			RotationXEntity(0.5f);
			std::cout << "W press" << std::endl;
		}
		if (GetKay("2", "Press")) {
			RotationYEntity(0.5f);
			std::cout << "W press" << std::endl;
		}
		if (GetKay("3", "Press")) {
			RotationZEntity(0.5f);
			std::cout << "W press" << std::endl;
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

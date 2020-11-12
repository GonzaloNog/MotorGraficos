#include "Game.h"

Game::Game() {

}
Game::~Game() {

}
void Game::Start() {
	std::cout << "Open Windows" << std::endl;
	OpenWindows(800, 600, "gonzalo");
	std::cout << "Start Loop" << std::endl;
	player = NewEntity();
	player2 = NewEntity();
	player->AddComponent("Material");
	player->GetMaterial()->SetSpriteSheet("img6.png",6,4);
	player2->AddComponent("Material");
	player2->GetMaterial()->SetCurrentSprite("img1.png");
	player->Scale(0.25);
	player2->Scale(2,2,1);
	player->GetMaterial()->SetIdFrame(2);
}
void Game::Delete() {
	FreeMemory();
}
void Game::Update() {
	player2->Draw();
	player->Draw();
	UpdateWindow();
	if (GetKay("space", "Press")) {
		player->GetMaterial()->SetCurrentSprite("img2.jpg");
		std::cout << "space press" << std::endl;
		SetColorBackground(0.1f, 0.7f, 0.3f);
	}
	if (GetKay("esc", "Press")) {
		CloseWindow();
	}
	if (GetKay("w", "Press")) {
		player->MovePosition(0.01, "Up");
		std::cout << "W press" << std::endl;
		player->GetMaterial()->SetIdFrame(14);
	}
	if (GetKay("s", "Press")) {
		player->MovePosition(0.01, "Down");
		std::cout << "S press" << std::endl;
		player->GetMaterial()->SetIdFrame(2);
	}
	if (GetKay("a", "Press")) {
		player->MovePosition(0.01, "Left");
		std::cout << "A press" << std::endl;
		player->GetMaterial()->SetIdFrame(19);
	}
	if (GetKay("d", "Press")) {
		player->MovePosition(0.01, "Right");
		std::cout << "D press" << std::endl;
		player->GetMaterial()->SetIdFrame(7);
	}
	if (GetKay("q", "Press")) {
		//ScaleEntity(0.5);
		player->ScalePlus(0.005);
		std::cout << "W press" << std::endl;
	}
	if (GetKay("e", "Press")) {
		//ScaleEntity(2);
		player->ScalePlus(-0.005);
		std::cout << "W press" << std::endl;
	}
	if (GetKay("1", "Press")) {
		player->RotationX(5.5f);
		std::cout << "W press" << std::endl;
	}
	if (GetKay("2", "Press")) {
		player->RotationY(5.5f);
		std::cout << "W press" << std::endl;
	}
	if (GetKay("3", "Press")) {
		player->RotationZ(5.5f);
		std::cout << "W press" << std::endl;
	}
}

#include "Game.h"


Game::Game() {

}
Game::~Game() {

}
void Game::Start() {
	std::cout << "Open Windows" << std::endl;
	OpenWindows(800, 600, "gonzalo");
	std::cout << "Start Loop" << std::endl;
	player = new Player(GetRenderer());
	player2 = NewEntity();
	player->AddComponent("Material");
	player->GetMaterial()->SetSpriteSheet("img6.png",6,4);
	player->AddComponent("Animator");
	std::list<int>  mylist{1};
	player->GetAnimator()->NewAnimation(mylist,0.1f,"idle");
	std::list<int>  mylist2{1, 2, 3, 4, 5, 6};
	player->GetAnimator()->NewAnimation(mylist2, 0.1f, "walkS");
	std::list<int>  mylist3{7, 8, 9, 10, 11, 12};
	player->GetAnimator()->NewAnimation(mylist3, 0.1f, "walkD");
	std::list<int>  mylist4{13, 14, 15, 16, 17, 18};
	player->GetAnimator()->NewAnimation(mylist4, 0.1f, "walkW");
	std::list<int>  mylist5{19, 20, 21, 22, 23, 24};
	player->GetAnimator()->NewAnimation(mylist5, 0.1f, "walkA");
	player2->AddComponent("Material");
	player2->GetMaterial()->SetCurrentSprite("img1.png");
	player->Scale(0.25);
	player2->Scale(0.25);
	
	//player2->Scale(2,2,1);
	player->GetMaterial()->SetIdFrame(2);
	player->AddComponent("BoxCollider2D");
	player2->AddComponent("BoxCollider2D");
	player2->MovePosition(0.3, "Right");
}

void Game::Update() {
	EngineUpdate();
	player->GetAnimator()->StartAnimation("idle");
	elapsedTIme += timer->DeltaTime();
	if (elapsedTIme >= 1) {
		frames++;
		//std::cout << frames << std::endl;
		elapsedTIme = 0;
	}
	
	if (GetKay("space", "Press")) {
		player->GetMaterial()->SetCurrentSprite("img2.jpg");
		//std::cout << "space press" << std::endl;
		SetColorBackground(0.1f, 0.7f, 0.3f);
	}
	if (GetKay("esc", "Press")) {
		CloseWindow();
	}
	if (GetKay("w", "Press")) {
		player->MovePosition(0.005, "Up");
		//std::cout << "W press" << std::endl;
		//player->GetMaterial()->SetIdFrame(14);
		player->GetAnimator()->StartAnimation("walkW");
	}
	if (GetKay("s", "Press")) {
		player->MovePosition(0.005, "Down");
		//std::cout << "S press" << std::endl;
		//player->GetMaterial()->SetIdFrame(2);
		player->GetAnimator()->StartAnimation("walkS");
	}
	if (GetKay("a", "Press")) {
		player->MovePosition(0.005, "Left");
		//std::cout << "A press" << std::endl;
		//player->GetMaterial()->SetIdFrame(19);
		player->GetAnimator()->StartAnimation("walkA");
	}
	if (GetKay("d", "Press")) {
		player->MovePosition(0.005, "Right");
		//std::cout << "D press" << std::endl;
		//player->GetMaterial()->SetIdFrame(7);
		player->GetAnimator()->StartAnimation("walkD");
	}
	if (GetKay("q", "Press")) {
		//ScaleEntity(0.5);
		player->ScalePlus(0.005);
		//std::cout << "Q press" << std::endl;
	}
	if (GetKay("e", "Press")) {
		//ScaleEntity(2);
		player->ScalePlus(-0.005);
		//std::cout << "E press" << std::endl;
	}
	if (GetKay("1", "Press")) {
		player->RotationX(5.5f);
		//std::cout << "1 press" << std::endl;
	}
	if (GetKay("2", "Press")) {
		player->RotationY(5.5f);
		//std::cout << "2 press" << std::endl;
	}
	if (GetKay("3", "Press")) {
		player->RotationZ(5.5f);
		//std::cout << "3 press" << std::endl;
	}
	player2->Draw();
	player->Draw();
	UpdateWindow();
}
void Game::Delete() {
	player->FreeMemory();
	player2->FreeMemory();
	FreeMemory();
}

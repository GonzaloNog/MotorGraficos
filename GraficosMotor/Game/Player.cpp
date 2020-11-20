#include "Player.h"

Player::Player(Renderer * rend) {
	ren = rend;
}
Player::~Player() {

}
void Player::OnColliderEnter2D(Collider* _coll) {
	std::cout << "Enter" << std::endl;
}
void Player::OnColliderStay2D(Collider* _coll) {
	std::cout << "Stay" << std::endl;
}
void Player::OnColliderExit2D(Collider* _coll) {
	std::cout << "Exit" << std::endl;
}

#include "Animator.h"

Animator::Animator() {

}
Animator::~Animator() {

}
void Animator::NewAnimation(std::list<int> _frames, float _time, std::string _name) {
	an = new Animation(_frames, _time,_name);
	ListAnim.push_back(an);
	if (empty) {
		empty = false;
		CurrentAnimation = "_name";
	}
}
void Animator::StartAnimation(std::string name) {
	CurrentAnimation = name;
}
int Animator::GetSprite() {
	Animation * anim;
	std::list <Animation*> auxList;
	auxList = ListAnim;
	while(!auxList.empty()) {
		anim = auxList.front();
		//std::cout << anim->GetName() << " " << CurrentAnimation << std::endl;
		if (CurrentAnimation == anim->GetName()) {
			return anim->getSpriteCurrent();
		}
		auxList.pop_front();
	}
	return 0;
}
bool Animator::GetEmpty() {
	return empty;
}
void Animator::FreeMemory() {
	Animation* anim;
	std::list <Animation*> auxList;
	auxList = ListAnim;
	while (!auxList.empty()) {
		anim = auxList.front();
		delete anim;
		auxList.pop_front();
	}
}

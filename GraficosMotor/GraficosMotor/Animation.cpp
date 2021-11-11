#include "Animation.h"

Animation::Animation(std::list<int> _frames, float _time, std::string _name) {
	frames = _frames;
	timeChangeFrame = _time;
	name = _name;
}
Animation::~Animation() {

}
int Animation::getSpriteCurrent() {
	time +=EngineUtils::Timer::Instance()->DeltaTime();
	std::list<int>::iterator it;
	it = frames.begin();
	if (time >= timeChangeFrame) {
		idFrame++;
		if (idFrame >= frames.size()) {
			idFrame = 0;
		}
		time = 0;
	}
	for (int a = 0; a < idFrame; a++) {
		it++;
	}
	return *it;
}
std::string Animation::GetName() {
	return name;
}



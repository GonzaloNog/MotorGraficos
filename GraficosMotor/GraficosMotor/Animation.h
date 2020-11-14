#include <list>
#include <iostream> 
#include "Timer.h"
#include "Exports.h"

class ZENGINE_API Animation
{
protected:
	std::list <int>  frames;
	float timeChangeFrame;
	int idFrame = 0;
	float time = 0.0f;
	std::string name;
public:
	Animation(std::list<int>  _frames, float _time, std::string _name);
	~Animation();
	int getSpriteCurrent();
	std::string GetName();
};


#include "Animation.h"


class ZENGINE_API Animator
{
protected:
	std::list <Animation*> ListAnim;
	Animation * an;
	std::string CurrentAnimation = "null";
	bool empty = true;
public:
	Animator();
	~Animator();
	void NewAnimation(std::list<int> _frames, float _time, std::string _name);
	int GetSprite();
	void StartAnimation(std::string name);
	bool GetEmpty();
	void FreeMemory();
};


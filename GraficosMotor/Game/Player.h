#include"Entity.h"
class Player: public Entity
{
protected:
public:
	Player(Renderer * rend);
	~Player();
	void OnColliderEnter2D(Collider* _coll);
	void OnColliderStay2D(Collider* _coll);
	void OnColliderExit2D(Collider* _coll);
};


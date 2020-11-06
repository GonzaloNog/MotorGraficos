#include "BaseGame.h"


class Game : public BaseGame
{
protected:
	Entity* player;
	Entity* player2;
public:
	Game();
	~Game();
	void Update();
	void Start() ;
	void Delete();
};


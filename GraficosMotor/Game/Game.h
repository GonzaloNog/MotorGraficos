#include "BaseGame.h"



class Game : public BaseGame
{
protected:
	Entity* player;
	Entity* player2;

	float elapsedTIme = 0.0f;
	float frames = 0;
public:
	Game();
	~Game();
	void Update();
	void Start() ;
	void Delete();
};


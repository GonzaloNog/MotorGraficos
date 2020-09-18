#include "BaseGame.h"


class Game : public BaseGame
{
private:
	bool running = true;//Determina la entrada y salida del loop 
public:
	Game();
	~Game();
	void Loop();//loop del juego 
	//Set y Get
	void SetRunning(bool _running);
	bool GetRunning();
};


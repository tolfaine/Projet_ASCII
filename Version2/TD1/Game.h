#pragma once


#include <vector>




class Game
{
public:
	Game();
	~Game();


	void run ();
	void pause ();
	void stop ();
	void resume ();

	void inputs ();
	void logic ();
	void render ();


private:

	//std::vector<Player> _players;

};


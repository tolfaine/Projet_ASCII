#include "Game.h"

using namespace std;
Game::Game()
{
	
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	player = new Hero();

}


Game::~Game()
{
}



void Game::run()
{
	timer.start();

	double previous = timer.getElapsedMs();
	double lag = 0.0;

	while (true)
	{
		double current = timer.getElapsedMs();
		double elapsed = current - previous;
		previous = current;

		lag += elapsed;

		inputs();

		
		while (lag >= TIME_PER_FRAME)
		{
			update();
			lag -= TIME_PER_FRAME;

			
		}
		render();
	}
}

void Game::pause()
{

}

void Game::stop()
{

}


void Game::resume()
{

}


void Game::inputs()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		player->setDirection(LEFT,true);
	//	cout << "LEFT" << endl;
	}
	else
	{
		player->setDirection(LEFT, false);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		player->setDirection(RIGHT, true);
	//	cout << "RIGHT" << endl;
	}
	else
	{
		player->setDirection(RIGHT, false);
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		player->setDirection(UP, true);
		//cout << "UP" << endl;
	}
	else
	{
		player->setDirection(UP, false);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		player->setDirection(DOWN, true);
	//	cout << "DOWN" << endl;
	}
	else
	{
		player->setDirection(DOWN, false);
	}

	if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
	{
		cout << "SHOT DAT MORTHAFUCKA" << endl;
	}

}

void Game::update()
{
	//loop -> call update method for each component

	clear();
	player->update();
}

void Game::render()
{


	renderPlayer();


	//Render screen


	WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}

void Game::renderPlayer()
{
	int spriteX = player->spriteX;
	int spriteY = player->spriteY;

	std::pair<COORD, CHAR_INFO* > playerRenderInfo = player->getRenderInfo();
	CHAR_INFO c1 = playerRenderInfo.second[0];
	COORD c = playerRenderInfo.first;

	int index = 0;

	for (int i = 0; i <spriteX; i++)
	{
		for (int j = 0; j < spriteY; j++)
		{
			buffer[j + c.Y][i + c.X] = playerRenderInfo.second[index++];

		}
	}
}

void Game::clear()
{
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			buffer[i][j].Char.AsciiChar = '\0';
			buffer[i][j].Char.UnicodeChar = '\0';
			buffer[i][j].Attributes = 0;
		}
	}
}


vector<GameObject*> Game::getGameObjectAt(const int x, const int y)
{
	return collisionMatrix[x][y];
}

void Game::setGameObjectAt(const int x, const int y, GameObject* c)
{
	collisionMatrix[x][y].push_back(c);
}

void Game::removeGameObjectAt(const int x, const int y, GameObject* c)
{
	auto v = collisionMatrix[x][y];

	auto it = find(v.begin(), v.end(), c);

	if (it != v.end())
	{
		// remove de collisionMatrix
		v.erase(it);
		
		// remove de components
		objects.erase(it);

		// appeler suppression dans pool
	}

}
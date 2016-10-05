#include "Game.h"

using namespace std;
Game::Game()
{

	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	//buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	buffer = new CHAR_INFO*[SCREEN_WIDTH];
	for (int i = 0; i < SCREEN_WIDTH; ++i)
	{
		buffer[i] = new CHAR_INFO[SCREEN_HEIGHT];
	}


	int** a;

	a = new int*[20];
	for (int i = 0; i < 20; ++i)
	{
		a[i] = new int[30];
	}

	buffer[0][0].Char.AsciiChar = 'X';
	buffer[0][0].Attributes = 0x0E;

	buffer[1][0].Char.AsciiChar = 'A';
	buffer[1][0].Attributes = 0x0E;

	player = new Hero(buffer);
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
		player->setDirection(LEFT);
		cout << "LEFT" << endl;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		player->setDirection(RIGHT);
		cout << "RIGHT" << endl;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		player->setDirection(UP);
		cout << "UP" << endl;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		player->setDirection(DOWN);
		cout << "DOWN" << endl;
	}

	if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
	{
		cout << "SHOT DAT MORTHAFUCKA" << endl;
	}

}

void Game::update()
{
	clear();
	//buffer[8][10].Char.AsciiChar = (char)i++;
	//buffer[8][10].Attributes = 0x0E;
	buffer[6][10].Char.AsciiChar = 'H';
	buffer[6][10].Attributes = 0x0E;
	buffer[6][11].Char.AsciiChar = 'i';
	buffer[6][11].Attributes = 0x0B;
	buffer[6][12].Char.AsciiChar = '!';
	buffer[6][12].Attributes = 0x0A;
}

void Game::render()
{
	player->renderHero();

	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}

void Game::clear()
{
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			buffer[i][j].Char.AsciiChar = ' ';
			buffer[i][j].Attributes = 0x00;
		}
	}
}
#include "Game.h"


using namespace std;


Game::Game()
{

	GameObject* g1 = new GameObject(this, new PlayerInputComponent(), 5.0, 5.0,10,3,HERO);
	g1->setSprite(populateSpriteHero(g1->getRenderInfo().pixels));
	GameObject* g2 = new GameObject(this, new InputComponent(), 20.0, 20.0,5,0,ENEMY);
	g2->setSprite(populateSpriteHero(g2->getRenderInfo().pixels));
	_gameObjects.push_back(g1);
	_gameObjects.push_back(g2);


	_physics = new PhysicsEngine(this);
	_inputs = new InputEngine(this);

	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

}


Game::~Game()
{

}

void Game::run()
{
	_timer.start();

	double previous = _timer.getElapsedMs();
	double lag = 0.0;

	while (true)
	{
		double current = _timer.getElapsedMs();
		double elapsed = current - previous;
		previous = current;

		lag += elapsed;

		//inputs();
		while (lag >= TIME_PER_FRAME)
		{
			update(elapsed);
			lag -= TIME_PER_FRAME;
		}
		renderGraphics();
	}
}


void Game::update(double elaspedMS)
{
	_inputs->handleInputs();
	_physics->update(elaspedMS);

	//takeCareOfDeadBodies();
}


void Game::takeCareOfDeadBodies()
{

	for (int i = 0; i < _gameObjects.size(); i++)
	{
		if (_gameObjects[i]->isDead())
		{
			delete _gameObjects[i];
		}
		_gameObjects.clear();
	}
}


void Game::renderGraphics()
{
	clear();
	for (GameObject* gObject : _gameObjects) {
		drawSprite(gObject->getRenderInfo());
	}

	WriteConsoleOutput(hOutput, (CHAR_INFO*)map, dwBufferSize,
		dwBufferCoord, &rcRegion);
}


void Game::drawSprite(const SpriteData spriteToDraw)
{
	COORD c = spriteToDraw.coord;

	for (Pixel pix : spriteToDraw.pixels)
	{
		map[c.Y + pix.y][c.X + pix.x] = pix.c;
	}
}

void Game::clear()
{
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			map[i][j].Char.AsciiChar = '\0';
			map[i][j].Char.UnicodeChar = '\0';
			map[i][j].Attributes = 0;
		}
	}
}


vector<Pixel>& Game::populateSpriteHero(vector<Pixel>& spriteSheet)
{

	CHAR_INFO c;
	c.Char.UnicodeChar = '=';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,0,0 });

	c.Char.UnicodeChar = '=';
	c.Attributes = 0x0;
	spriteSheet.push_back(Pixel{ c,0,1 });

	c.Char.UnicodeChar = '=';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,0,2 });

	c.Char.UnicodeChar = '|';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,1,0 });

	c.Char.UnicodeChar = '|';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,1,1 });

	c.Char.UnicodeChar = '|';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,1,2 });


	c.Char.UnicodeChar = '92';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,2,0 });

	c.Char.UnicodeChar = 'o';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,2,1 });

	c.Char.UnicodeChar = '47';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,2,2 });


	c.Char.UnicodeChar = '\0';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,3,0 });

	c.Char.UnicodeChar = ')';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,3,1 });

	c.Char.UnicodeChar = '\0';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,3,2 });


	c.Char.UnicodeChar = '\0';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,4,0 });

	c.Char.UnicodeChar = '>';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,4,1 });

	c.Char.UnicodeChar = '\0';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,4,2 });

	return spriteSheet;
}
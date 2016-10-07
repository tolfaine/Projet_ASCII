#include "Game.h"


using namespace std;


Game::Game()
{

	createGameObject(GameObjectData{ { 5.0, 5.0 }, F_HERO, T_PLAYER });
	createGameObject(GameObjectData{ { 20.0, 20.0 }, F_ENEMY, T_ENEMY});

	_graphics = new GraphicsEngine();
	_physics = new PhysicsEngine();
	_inputs = new InputEngine();
	_gameUI = new UI(this);

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

		inputs();
		addGameObjects();
		while (lag >= TIME_PER_FRAME)
		{
			update();
			lag -= TIME_PER_FRAME;
		}
		render();
		
	}
}


void Game::update()
{
	_physics->update(_gameObjects);
	_gameUI->update();
	takeCareOfDeadBodies();
}


void Game::inputs()
{
	_inputs->handleInputs(_gameObjects);
}


void Game::render()
{
	_graphics->renderGraphics(_gameObjects);
}


void Game::createGameObject(GameObjectData data)
{
	_gameObjectsData.push_back(data);

}

void Game::addGameObjects()
{
	for (GameObjectData data : _gameObjectsData)
	{
		InputComponent* iComponent = new InputComponent();
		int life = 0;
		int damage = 0;
		HitBox hitbox;
		double speed;

		switch (data.type)
		{
		case T_WALL:
			// iComponent = new InputComponent();
			life = 1000;
			damage = 1000;
			hitbox.height = 1.0;
			hitbox.width = 1.0;
			speed = -1.0;
			break;

		case T_PLAYER:
			iComponent = new PlayerInputComponent();
			life = 10;
			damage = 5;
			hitbox.height = 3.0;
			hitbox.width = 5.0;
			speed = 2.0;
			break;

		case T_ENEMY:
			// iComponent = new InputComponent();
			life = 5;
			damage = 2;
			hitbox.height = 3.0;
			hitbox.width = 3.0;
			speed = -2.0;
			break;

		case T_MISSILE:
			iComponent = new MissileInputComponent();
			life = 1;
			damage = 1;
			hitbox.height = 1;
			hitbox.width = 3;
			speed = 3.0;
			break;
		}


		GameObject* g = new GameObject(
			this,
			iComponent,
			data.coord.x,
			data.coord.y,
			hitbox,
			life,
			damage,
			data.faction,
			data.type,
			speed);

		if (data.type == T_MISSILE) g->setSprite(populateSpriteMissile(g->getRenderInfo().pixels));
		//if (data.type == T_PLAYER) g->setSprite(populateSpriteHero(g->getRenderInfo().pixels));
		else g->setSprite(populateSpriteHero(g->getRenderInfo().pixels));
		


		_gameObjects.push_back(g);
	}

	_gameObjectsData.clear();

}




void Game::takeCareOfDeadBodies()
{

	for (int i = 0; i < _gameObjects.size(); i++)
	{
		if (_gameObjects[i]->isDead())
		{
			delete _gameObjects[i];
			_gameObjects.erase(_gameObjects.begin() + i);
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


	c.Char.UnicodeChar = 92;
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,2,0 });

	c.Char.UnicodeChar = 'o';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c,2,1 });

	c.Char.UnicodeChar = 47;
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


vector<Pixel>& Game::populateSpriteMissile(vector<Pixel>& spriteSheet)
{

	CHAR_INFO c;
	c.Char.UnicodeChar = '8';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c, 0, 0 });


	c.Char.UnicodeChar = '=';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c, 1, 0 });



	c.Char.UnicodeChar = '>';
	c.Attributes = 0x0A;
	spriteSheet.push_back(Pixel{ c, 2, 0 });


	return spriteSheet;
}

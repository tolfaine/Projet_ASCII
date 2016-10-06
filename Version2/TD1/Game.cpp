#include "Game.h"

using namespace std;

Game::Game()
{
	pEngine = PhysicsEngine(this);
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	//buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	//player = new Hero();

	init();
	run();
}


Game::~Game()
{

}

void Game::init()
{
	//rajout des objets
	Hero player1 = Hero(this, Coord{10.0, 10.0}, 1);
	components.push_back(player1);

	controllers.push_back(PlayerController(player1));
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

		cout << current << " " << elapsed << endl;

		lag += elapsed;

		inputs();
		while (lag >= TIME_PER_FRAME)
		{
			update(elapsed);
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
	for (Controller controller : controllers) {
		controller.inputs();
	}
}

void Game::update(long elapsedMs)
{
	//loop -> call update method for each component

	clear();
	for (GameObject component : components)
	{
		component.update(elapsedMs);
	}

	pEngine.update(elapsedMs);
}

void Game::render()
{
	for (GameObject component : components) {
		draw(component.getRenderInfo());
	}

	WriteConsoleOutput(hOutput, (CHAR_INFO*)map, dwBufferSize,
		dwBufferCoord, &rcRegion);
}

void Game::draw(const std::pair<COORD, vector<Pixel>>& renderInfo)
{
	COORD c = renderInfo.first;

	for (Pixel pix : renderInfo.second)
	{
		map[c.Y + pix.y][c.X + pix.x] = pix.c;
	}

	/*int spriteX = renderInfo.second.width;
	int spriteY = renderInfo.second.height;


	int index = 0;

	for (int i = 0; i <spriteX; i++)
	{
		for (int j = 0; j < spriteY; j++)
		{
			map[j + c.Y][i + c.X] = renderInfo.second.tab[index++];
		}
	}*/
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
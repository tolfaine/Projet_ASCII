#include "GraphicsEngine.h"



using namespace std;


GraphicsEngine::GraphicsEngine()
{
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	rOutput = (HANDLE)GetStdHandle(STD_INPUT_HANDLE);
	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT+10 };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT+10 };

	SetConsoleWindowInfo(hOutput, TRUE, &rcRegion);
	SetConsoleScreenBufferSize(hOutput, dwBufferSize);
}



GraphicsEngine::~GraphicsEngine()
{
}



void GraphicsEngine::renderGraphics(vector<GameObject*> objects)
{
	clear();
	for (GameObject* gObject : objects) {
		drawSprite(gObject->getRenderInfo());
	}

	//drawSprite(_gameUI->getRenderInfo());
	WriteConsoleOutput(hOutput, (CHAR_INFO*)map, dwBufferSize,
		dwBufferCoord, &rcRegion);
}


void GraphicsEngine::drawSprite(const SpriteData spriteToDraw)
{
	COORD c = spriteToDraw.coord;

	for (Pixel pix : spriteToDraw.pixels)
	{
		map[c.Y + pix.y][c.X + pix.x] = pix.c;
	}
}

void GraphicsEngine::clear()
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

#pragma once

#include <Windows.h>
#include <vector>

#include "GameObject.h"

class GameObject;

class GraphicsEngine
{


public:


	GraphicsEngine();
	~GraphicsEngine();


	// renders the graphics
	void renderGraphics(std::vector<GameObject*>);

	// clears the graphics buffer, shall be put in graphicsengine at some point
	void clear();
	// draws a sprite in the graphics buffer at the coordinates indicated, shall be put in graphicsengine at some point
	void drawSprite(const SpriteData spriteToDraw);


private:

	CHAR_INFO map[SCREEN_HEIGHT + 10][SCREEN_WIDTH];

	HANDLE hOutput;
	HANDLE rOutput;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;



};


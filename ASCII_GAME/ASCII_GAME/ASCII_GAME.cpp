// ASCII_GAME.cpp : Defines the entry point for the console application.
//


#include "Game.h"


int main(void)
{



	//HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	//COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
	//COORD dwBufferCoord = { 0, 0 };
	//SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	//CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	//ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
	//	dwBufferCoord, &rcRegion);

	//buffer[5][10].Char.AsciiChar = 'H';
	//buffer[5][10].Attributes = 0x0E;
	//buffer[5][11].Char.AsciiChar = 'i';
	//buffer[5][11].Attributes = 0x0B;
	//buffer[5][12].Char.AsciiChar = '!';
	//buffer[5][12].Attributes = 0x0A;

	//WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
	//	dwBufferCoord, &rcRegion);


	Game game;

	game.run();

    return 0;
}


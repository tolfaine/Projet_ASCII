// TD1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "NYTimer.h"

using namespace std;


#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define TIME_PER_FRAME 1000 / 120


void clear();
void inputs();
void update();
void render();


HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

COORD dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
COORD dwBufferCoord = { 0, 0 };
SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

int main(int argc, _TCHAR* argv[])
{

	
	NYTimer timer;
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



	return 0;
}



void inputs()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		cout << "LEFT" << endl;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		cout << "RIGHT" << endl;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		cout << "UP" << endl;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		cout << "DOWN" << endl;
	}

	if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
	{
		cout << "SHOT DAT MORTHAFUCKA" << endl;
	}



}

int i = 0;
void update()
{ 
	clear();
	buffer[8][10].Char.AsciiChar = (char)i++;
	buffer[8][10].Attributes = 0x0E;
	buffer[6][10].Char.AsciiChar = 'H';
	buffer[6][10].Attributes = 0x0E;
	buffer[6][11].Char.AsciiChar = 'i';
	buffer[6][11].Attributes = 0x0B;
	buffer[6][12].Char.AsciiChar = '!';
	buffer[6][12].Attributes = 0x0A;
}

void render()
{
	
	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
	
}




void clear()
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

//
///* Read console input buffer and return malloc'd INPUT_RECORD array */
//DWORD getInput(INPUT_RECORD **eventBuffer)
//{
//	/* Variable for holding the number of current events, and a point to it */
//	DWORD numEvents = 0;
//
//
//	/* Variable for holding how many events were read */
//	DWORD numEventsRead = 0;
//
//
//	/* Put the number of console input events into numEvents */
//	GetNumberOfConsoleInputEvents(rHnd, &numEvents);
//
//
//	if (numEvents) /* if there's an event */
//	{
//		/* Allocate the correct amount of memory to store the events */
//		*eventBuffer = malloc(sizeof(INPUT_RECORD) * numEvents);
//
//		/* Place the stored events into the eventBuffer pointer */
//		ReadConsoleInput(rHnd, *eventBuffer, numEvents, &numEventsRead);
//	}
//
//
//	/* Return the amount of events successfully read */
//	return numEventsRead;
//}
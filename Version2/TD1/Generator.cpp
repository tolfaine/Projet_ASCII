#include "Generator.h"

#include <time.h>
#include <stdlib.h>


using namespace std;

Generator::Generator()
{
	sectionTotalLenght = getRandRange (SECTION_MIN,SECTION_MAX);
	sectionRemaingingLenght = sectionTotalLenght;

	floorCurrent = getRandRange(FLOOR_MIN, FLOOR_MAX);
	ceilingCurrent = getRandRange(CEILING_MIN, CEILING_MAX);

	floorNext = getRandRange(FLOOR_MIN, FLOOR_MAX);
	ceilingNext = getRandRange(CEILING_MIN, CEILING_MAX);

	initBag();
}

Generator::~Generator()
{
}


void Generator::getNext (array<Square, WINDOW_H>& nextColumn )
{
	generateWalls (nextColumn);

	for (int i = floorCurrent + 1; i < ceilingCurrent; ++i)
	{
		nextColumn[i].setType(getFromBag());
	}
}


void Generator::generateWalls(std::array<Square, WINDOW_H>& nextColumn)
{
	if (sectionRemaingingLenght > 0)
	{
		nextColumn[floorCurrent].setType(WALL);
		nextColumn[ceilingCurrent].setType(WALL);

		--sectionRemaingingLenght;
	}

	else if (sectionRemaingingLenght == 0)
	{
		bool wallsUpToDate = true;

		if (floorCurrent < floorNext)
		{
			++floorCurrent;
			if (floorCurrent == floorNext)
			{
				nextColumn[floorCurrent].setType(WALL);
			}
			else
			{
				nextColumn[floorCurrent].setType(WALL_RIGHT);
				wallsUpToDate = false;
			}
		}

		else if (floorCurrent > floorNext)
		{
			--floorCurrent;
			if (floorCurrent == floorNext)
			{
				nextColumn[floorCurrent].setType(WALL);
			}
			else
			{
				nextColumn[floorCurrent].setType(WALL_LEFT);
				wallsUpToDate = false;
			}
		}

		if (ceilingCurrent < ceilingNext)
		{
			++ceilingCurrent;
			if (ceilingCurrent == ceilingNext)
			{
				nextColumn[ceilingCurrent].setType(WALL);
			}
			else
			{
				nextColumn[ceilingCurrent].setType(WALL_LEFT);
				wallsUpToDate = false;
			}
		}

		else if (ceilingCurrent > ceilingNext)
		{
			--ceilingCurrent;
			if (ceilingCurrent == ceilingNext)
			{
				nextColumn[ceilingCurrent].setType(WALL);
			}
			else
			{
				nextColumn[ceilingCurrent].setType(WALL_RIGHT);
				wallsUpToDate = false;
			}
		}

		if (wallsUpToDate)
		{
			sectionRemaingingLenght = getRandRange(SECTION_MIN, SECTION_MAX);
			floorNext = getRandRange(FLOOR_MIN, FLOOR_MAX);
			ceilingNext = getRandRange(CEILING_MIN, CEILING_MAX);
		}
	}
}

SquareType Generator::getFromBag()
{
	if (typeBag.empty())
	{
		initBag();
	}
	int index = getRandRange(0, typeBag.size());
	SquareType type = typeBag[index];
	typeBag.erase(typeBag.begin()+index);

	return type;
}


int Generator::getRandRange(int min, int max)
{
	srand((unsigned)time(0));
	int range = (max - min);
	return min + int((range * rand()) / (RAND_MAX + 1.0));
}



void Generator::initBag()
{

	for (int i = 0; i < BAG_SIZE; ++i)
	{
		if (i < BAG_ENEMY)
		{
			typeBag.push_back(ENEMY);
		}
		else
		{
			typeBag.push_back(EMPTY);
		}
	}
}
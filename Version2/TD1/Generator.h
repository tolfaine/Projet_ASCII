#pragma once


#define FLOOR_MIN 0
#define FLOOR_MAX 10
#define CEILING_MIN 40
#define CEILING_MAX 50
#define SECTION_MIN 5
#define SECTION_MAX 30
#define BAG_SIZE 500
#define BAG_ENEMY 100

#include <array>
#include <vector>

#include "Parametres.h"
#include "Square.h"

class Generator
{
public:
	Generator();
	~Generator();

	void getNext (std::array<Square, WINDOW_H>& nextColumn);

	int getRandRange(int min, int max);

private:

	void generateWalls (std::array<Square, WINDOW_H>& nextColumn);
	SquareType getFromBag();
	void initBag();

	int sectionTotalLenght;
	int sectionRemaingingLenght;
	int floorCurrent;
	int ceilingCurrent;

	int floorNext;
	int ceilingNext;

	vector<SquareType> typeBag;
};


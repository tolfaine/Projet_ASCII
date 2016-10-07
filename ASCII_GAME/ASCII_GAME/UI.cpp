
#include "UI.h"
#include <sstream>
#include <string>

using namespace std;
UI::UI(Game* g)
{
	_game = g;
}


UI::~UI()
{

}
void UI::update() {

	clean();

	CHAR_INFO c;

	c.Char.UnicodeChar = '-';
	c.Attributes = 0x0A;


	for (int i = 0; i < SCREEN_WIDTH; i++) {
		_sprite.pixels.push_back(Pixel{ c,i,SCREEN_HEIGHT });
		_sprite.pixels.push_back(Pixel{ c,i,MIN_HEIGHT - 1 });
	}


	int life = _game->getPlayer()->getLife();
	int maxLife = _game->getPlayer()->getMaxLife();
	double pourcLife = life / maxLife;
	int cellSize =5;
	int startLifeDrawX = (SCREEN_WIDTH / 2) - ((maxLife*cellSize + 2) / 2);


	c.Char.UnicodeChar = '-';
	c.Attributes = 0x0A;

	_sprite.pixels.push_back(Pixel{ c,startLifeDrawX - 1,SCREEN_HEIGHT + 1 });
	_sprite.pixels.push_back(Pixel{ c,startLifeDrawX - 1,SCREEN_HEIGHT + 2 });
	_sprite.pixels.push_back(Pixel{ c,startLifeDrawX - 1,SCREEN_HEIGHT + 3 });

	_sprite.pixels.push_back(Pixel{ c,startLifeDrawX + maxLife*cellSize,SCREEN_HEIGHT + 1 });
	_sprite.pixels.push_back(Pixel{ c,startLifeDrawX + maxLife*cellSize ,SCREEN_HEIGHT + 2 });
	_sprite.pixels.push_back(Pixel{ c,startLifeDrawX + maxLife*cellSize ,SCREEN_HEIGHT + 3 });

	for (int i = 0; i < maxLife*cellSize; i++) {
		_sprite.pixels.push_back(Pixel{ c,startLifeDrawX + i,SCREEN_HEIGHT+1 });
		_sprite.pixels.push_back(Pixel{ c,startLifeDrawX  + i,SCREEN_HEIGHT + 3 });
	}

	int currentLifeX = life*cellSize;
	c.Attributes = 0x0A;

	c.Char.UnicodeChar = 0x2588;
	int b = life * 100 / maxLife;
	// 0x0C : rouge      E : jaune   A :vert
	if (life / (double)maxLife > 0.66){
		c.Attributes = 0x0A;
	}
	else if (life / (double)maxLife> 0.33){
		c.Attributes = 0x0E;
	}
	else if (life / (double)maxLife> 0) {
		c.Attributes = 0x0C;
	}

	for (int i = 0; i < currentLifeX; i++) {
		_sprite.pixels.push_back(Pixel{ c,startLifeDrawX + i,SCREEN_HEIGHT + 2 });
	}


}

void UI::clean() {

	_sprite.pixels.clear();
}  

#include "UI.h"
#include <sstream>
#include <string>

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
	 

	/*
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
	spriteSheet.push_back(Pixel{ c,4,2 });*/


}

void UI::clean() {

	_sprite.pixels.clear();
}
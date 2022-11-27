#pragma once
#include "nglCursor.h"

#define RD setColor(LightRed, Black)
#define GR setColor(DarkGray, Black)
#define CN setColor(LightCyan, Black)
#define YL setColor(Yellow, Black)
#define WT setColor(White, Black)           //цвет подсвеченного пункта меню
#define HG setColor(LightRed, Black)        //цвет подсвеченного пункта меню
#define BR setColor(Yellow, Black)        //инвертированный цвет пункта меню


///////////////////////// ЦВЕТА /////////////////////////
enum COLORS{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};


//устанавливает цвет шрифта
void setColor(int clr){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD) ((Black << 4) | clr));
}
//устанавливает цвет шрифта и фона
void setColor(int clr1, int clr2){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD) ((clr2 << 4) | clr1));
}

void insertTab(){
	COORD pos;
	returnCursorCOORD(pos);
	pos.X+=8;
	setNewCursorCOORD(pos);
}

void insertNewTab(){
	COORD pos;
	returnCursorCOORD(pos);
	pos.X-=8;
	pos.Y+=1;
	setNewCursorCOORD(pos);
}

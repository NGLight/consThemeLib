//перенести коорды курсора в правый верхний угол
#pragma once
#include <iostream>
#define _WIN32_WINNT 	0x0500
#include <windows.h>

#include "nglKeys.h"
short getKeys();

using namespace std;
void returnCursorCOORD(COORD& pos);
void setNewCursorCOORD(COORD pos);
void setNewCursorCOORD(int posX, int posY);
void showCursorCOORD();
void showCursor(bool cursor);

///////////////////////// УПРАВЛЕНИЕ КУРСОРОМ /////////////////////////
void returnCursorCOORD(COORD& pos){
	//возвращаем текущие коорды курсора и принимаем их за нулевые
	CONSOLE_SCREEN_BUFFER_INFO buffInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buffInfo);
	pos.X = buffInfo.dwCursorPosition.X;
	pos.Y = buffInfo.dwCursorPosition.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setNewCursorCOORD(COORD pos){
	//ставим произвольные коорды курсора в том числе и относительно нулевых
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setNewCursorCOORD(int posX, int posY){
	COORD pos;
	pos.X = posX;
	pos.Y = posY;
	//ставим произвольные коорды курсора в том числе и относительно нулевых
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//выводит
void showCursorCOORD(){
	//просто выводим текущие коорди курсора
	//отладочная функция
	COORD nullPos = {0,0}, currPos;
	returnCursorCOORD(currPos);
	short key = getKeys();
	while(key != BUTT_ESC || key != BUTT_ENTER){
		switch (key){
		case BUTT_DOWN:
			if (currPos.Y < 38){
				currPos.Y++;
				showCursor(false);
				setNewCursorCOORD(nullPos);
				cout << "x:" << currPos.X << " y:" << currPos.Y << " ";
				setNewCursorCOORD(currPos);
				showCursor(true);
				}
			break;

		case BUTT_UP:
			if (currPos.Y > 0){
				currPos.Y--;
							showCursor(false);
				setNewCursorCOORD(nullPos);
				cout << "x:" << currPos.X << " y:" << currPos.Y << " ";
				setNewCursorCOORD(currPos);
				showCursor(true);
				}
			break;

		case BUTT_LEFT:
			if (currPos.X > 0){
				currPos.X--;
							showCursor(false);
				setNewCursorCOORD(nullPos);
				cout << "x:" << currPos.X << " y:" << currPos.Y << " ";
				setNewCursorCOORD(currPos);
				showCursor(true);
				}
			break;

		case BUTT_RIGHT:
			if (currPos.X < 125){
				currPos.X++;
							showCursor(false);
				setNewCursorCOORD(nullPos);
				cout << "x:" << currPos.X << " y:" << currPos.Y << " ";
				setNewCursorCOORD(currPos);
				showCursor(true);
				}
			break;
		}
		key = getKeys();
	}

}

void showCursor(bool cursor){
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&structCursorInfo);
	structCursorInfo.bVisible = cursor;
	SetConsoleCursorInfo( GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo );
}

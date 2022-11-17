//код нажатой клавишы в парвый верхний угол
#pragma once
#include <iostream>
//#include <iostream>
#include <conio.h>
#define _WIN32_WINNT 	0x0500
#include <windows.h>

#include "nglCursor.h"
void setNewCursorCOORD(COORD pos);

using namespace std;
short getKeys();
void returnCodeKey();

///////////////////////// УПРАВЛЕНИЕ КУРСОРОМ /////////////////////////
enum KEYS{
	BUTT_LEFT = 0x4B,
	BUTT_UP = 0x48,
	BUTT_RIGHT = 0x4D,
	BUTT_DOWN = 0x50,
	BUTT_ENTER = 0x0D,
	BUTT_ESC = 0x1B,
	BUTT_SPACE = 0x20,
	BUTT_BACKSPACE = 0x08,

	BUTT_0 = 0x30,
	BUTT_1 = 0x31, BUTT_2 = 0x32, BUTT_3 = 0x33,
	BUTT_4 = 0x34, BUTT_5 = 0x35, BUTT_6 = 0x36,
	BUTT_7 = 0x37, BUTT_8 = 0x38, BUTT_9 = 0x39
};

short getKeys(){
	int key;
	while(true)
	switch(key = _getch()){
		case BUTT_LEFT:		return key; break;
		case BUTT_RIGHT:	return key; break;
		case BUTT_UP:		return key; break;
		case BUTT_DOWN:		return key; break;
		case BUTT_ENTER:	return key; break;
		case BUTT_SPACE:	return key; break;
		case BUTT_ESC:		return key; break;

		case BUTT_0: return key; break;
		case BUTT_1: return key; break;
		case BUTT_2: return key; break;
		case BUTT_3: return key; break;
		case BUTT_4: return key; break;
		case BUTT_5: return key; break;
		case BUTT_6: return key; break;
		case BUTT_7: return key; break;
		case BUTT_8: return key; break;
		case BUTT_9: return key; break;

		default: return key; break;

	}
}

void returnCodeKey(){
	COORD pos = {0,0};
	while (true) {
		setNewCursorCOORD(pos);
		short key =_getch();
		cout << "\rКод нажатой клавиши: ";
		cout << hex << "hex: " << key << dec << " int: " << key;
	}
}

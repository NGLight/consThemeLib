//Переписать coorposition чтобы получать только координаты
//добавить ускорение, если держать более 10 нажатий
#pragma once
#include <ctime>
#include <string>
#include <math.h>
//#include "nglFigures.h"
#include "nglKeys.h"

void drawLineStruct(struct pointCoord p1, struct pointCoord p2);
//void drawLine(int x1,int y1, int x2, int y2);
//////////////////////////snake//////////////////////////

short waitKey()
{
	short key=0;
    if (_kbhit()){
		switch(key = _getch()){
			case BUTT_LEFT:		return key; break;
			case BUTT_RIGHT:	return key; break;
			case BUTT_UP:		return key; break;
			case BUTT_DOWN:		return key; break;
			case BUTT_ENTER:	return key; break;
			case BUTT_SPACE:	return key; break;
			case BUTT_ESC:		return key; break;
		}
	}
	_kbhit();
	return key;
}

struct pointCOORDSnake{
	short X;
	short Y;
};

void drawPointSnake(int x_0, int y_0, unsigned short R=255, unsigned short G=255, unsigned short B=255){
	x_0 = (x_0*10);
	y_0 = (y_0*10);
	//y_0 = (y_0*10*(-1) + 400);
	SET_HANDLE;
	double x, y, r;

	for (r=3; r>0; r--)
		for (double n = 0, dn = 1/r; n < 2*3.14; n += dn){
			x = x_0 + (r-1)*cos(n);
			y = y_0 + (r-1)*sin(n);
			//cout << dn;
			SetPixel(hdc, x, y, RGB(R, G, B));
		}
}


void snake(){
	showCursor(false);
	//!КНОПКА СТАРТ
	//!БАГ ПРИ СТАРТЕ
	//!ОГРАНИЧИТЬ ИГРОВОЕ МОЛЕ
	//!ПРОВЕРКА НА СТОЛКНОВЕНИЕ С РАМКОЙ ИЛИ БЕСКОНЕЧНОЕ ПОЛЕ
	//!ОЧКИ В ВЕРХНЕМ УГЛУ
	//!АНИМАЦИЯ ГЕЙМ ОВЕРА
	//!сделать из несчастной змеюки вектор =/
	//!спавним змеюку на рандомные коорды

	size_t snakeSaze = 4, MAX_SIZE = 200;

	pointCOORDSnake *Snake = new pointCOORDSnake[MAX_SIZE];

	//отрисовка первоначальной змейки
	for (int i=0; i < snakeSaze; i++){
		Snake[i].X = 50 + i; Snake[i].Y = 30;
		drawPointSnake(Snake[i].X, Snake[i].Y, 0, 255, 255);
	}

	short key{};
	short dir = 3;
	short speed = 100;

	//НЯМКИ
	size_t countNymok = 10;
	pointCOORDSnake *Eat = new pointCOORDSnake[countNymok];
	bool superNymka = false;
	short superNymkaHealth = 0;
	struct pointCOORDSnake superEat;

	for (int i=0, x, y; i < countNymok; i++){
		Eat[i].X  = random(0,128);
		Eat[i].Y  = random(0,72);
		drawPointSnake(Eat[i].X, Eat[i].Y, 255,30,50);
	}

	for(int i=0; true; i++){

		//буффер опрашиваем всегда
		//но меняем путь только если была нажата клавиша
		key = waitKey();

		switch (key){
			case BUTT_UP: if (dir != 2) dir=1; break;
			case BUTT_DOWN: if (dir != 1) dir=2; break;
			case BUTT_RIGHT: if (dir != 4) dir=3; break;
			case BUTT_LEFT: if (dir != 3) dir=4; break;
			case BUTT_ESC: return;
		}

		//путь проходим всегда
		switch (dir){
			case 1: Snake[0].Y--; break;
			case 2: Snake[0].Y++; break;
			case 3: Snake[0].X++; break;
			case 4: Snake[0].X--; break;
		}

		//проверка на встречу с хвостом
		for (int i=1; i<snakeSaze; i++)
			if (Snake[0].X == Snake[i].X && Snake[0].Y == Snake[i].Y){
					//cout << "Game over!";
					dir =0;
			}


		//наследование змейки
		//вообще-то достаточно переносить только хвост и голову
		//ПЕРЕДЕЛАТЬ
		for (int i=snakeSaze; i > 0; i--)
			Snake[i] = Snake[i-1];

		//проверка на встречу с нямкой
		for (int i=0; i < countNymok; i++){
 			if (Snake[0].X == Eat[i].X && Snake[0].Y == Eat[i].Y){
				snakeSaze++;
				Eat[i].X  = random(0,128);
				Eat[i].Y  = random(0,72);
				drawPointSnake(Eat[i].X, Eat[i].Y, 255,30,50);
				break;
			}
		}

		//создаем СУПЕРНЯМКУ
		if (!superNymka && random(0,300) == 1){
				superNymka = true;
				superNymkaHealth = 100;
				superEat.X  = random(0,128);
				superEat.Y  = random(0,72);
				drawPointSnake(superEat.X, superEat.Y, 30,255,30);
		}
		//у СУПЕРНЯМКИ закончились жизни, удаляем СУПЕРНЯМКУ :(
		if (superNymka && superNymkaHealth <= 0){
				superNymka = false;
				drawPointSnake(superEat.X, superEat.Y, 0,0,0);
			}
		//проверка на встречу с СУПЕРНЯМКОЙ
        if (superNymka == true && (Snake[0].X == superEat.X) && (Snake[0].Y == superEat.Y)){
			superNymka = false;
			snakeSaze += 10;
        }

		//отрисовка змиюки
		drawPointSnake(Snake[0].X, Snake[0].Y, 0, 255, 255);
		drawPointSnake(Snake[snakeSaze].X, Snake[snakeSaze].Y, 0, 0, 0);

		//отрисовка СУПЕРНЯМКИ
		if (superNymka == true && i%2 == 1){
			drawPointSnake(superEat.X, superEat.Y, 30,255,30);
			superNymkaHealth--;
		}
		else if (superNymka == true && i%2 == 0){
			drawPointSnake(superEat.X, superEat.Y, 255,255,30);
			superNymkaHealth--;
		}

		//скорость змеюки
		if (snakeSaze < 90) speed = 100 - snakeSaze;

		//Справочная инфа
		//if (superNymka) setNewCursorCOORD({0, 34}); cout << "\r superNymkaHealth " << superNymkaHealth;
		//setNewCursorCOORD({0, 36}); cout << "\r key " << key;
		//setNewCursorCOORD({0, 37}); cout << "\r dir " << dir;
		//setNewCursorCOORD({0, 35}); cout << "\rHVOST (" << Snake[snakeSaze].X*10 << ", " << Snake[snakeSaze].Y*10 << ")";
		//setNewCursorCOORD({0, 38}); cout << "\rGOLOVA (" << Snake[0].X*10 << ", " << Snake[0].Y*10 << ")";

		Sleep(speed);
	}
//}
}


/*
struct lineCOORD{
	short x1;
	short y1;

	short x2;
	short y2;

	lineCOORD(){
		x1=x2=0;
		y1=y2=0;
	}
};
*/
//////////////////////////////////////////////////////////////////////////////////////
/*
void drawTest(){
	struct lineCOORD line_1;
	struct lineCOORD line_2;
	struct lineCOORD line_3;
	struct lineCOORD line_4;

	short n = 1;
	short key;
	bool pnt_one = true ;
	bool draw_line = false;

	while(key = getKeys()){
	if (!draw_line){
		drawPointSnake(line_1.x1,line_1.y1,0,0,0);
		drawPointSnake(line_1.x2,line_1.y2,0,0,0);
		drawPointSnake(line_3.x1,line_3.y1,0,0,0);
		drawPointSnake(line_3.x2,line_3.y2,0,0,0);
	}
	else{
		drawLine(line_1.x1,line_1.y1,  line_1.x2,line_1.y2, 0);
		drawLine(line_2.x1,line_2.y1,  line_2.x2,line_2.y2, 0);
		drawLine(line_3.x1,line_3.y1,  line_3.x2,line_3.y2, 0);
		drawLine(line_4.x1,line_4.y1,  line_4.x2,line_4.y2, 0);
	}

		switch(key){
			case BUTT_UP:
				if (pnt_one) line_1.y2-=n;
				else line_3.y2-=n;
			break;
			case BUTT_DOWN:
				if (pnt_one) line_1.y2+=n;
				else line_3.y2+=n;
			break;
			case BUTT_LEFT:
				if (pnt_one) line_1.x2+=n;
				else line_3.x2-=n;
			break;
			case BUTT_RIGHT:
				if (pnt_one) line_1.x2+=n;
				else line_3.x2+=n;
			break;
			case BUTT_SPACE:
				if (pnt_one) pnt_one = false;
				else pnt_one = true;
			break;
			case BUTT_ENTER:
				if (draw_line) draw_line = false;
				else draw_line = true;
			break;
		}
	if (key >= 49 && key <= 57){
		cout << n;
		n = key - 48;
	}

	line_1.x1 = line_1.x2; line_1.y1 = line_3.y2;
	line_3.x1 = line_3.x2; line_3.y1 = line_1.y2;

	line_2.x1 = line_1.x2; line_2.y1 = line_1.y2;
	line_2.x2 = line_3.x1; line_2.y2 = line_3.y1;
	line_4.x1 = line_3.x2; line_4.y1 = line_3.y2;
	line_4.x2 = line_1.x1; line_4.y2 = line_1.y1;

	//setNewCursorCOORD({0,38});
	//cout << "\r( " << line_1.x2 << ", " << line_1.y2 << ")";
	//setNewCursorCOORD({0,39});
	cout << "\r( " << line_3.x2 << ", " << line_3.y2 << ")";

	if (!draw_line){
		drawPointSnake(line_1.x1,line_1.y1);
		drawPointSnake(line_1.x2,line_1.y2);
		drawPointSnake(line_3.x1,line_3.y1);
		drawPointSnake(line_3.x2,line_3.y2);
	}
	else {
		drawLine(line_1.x1,line_1.y1,  line_1.x2,line_1.y2);
		drawLine(line_2.x1,line_2.y1,  line_2.x2,line_2.y2);
		drawLine(line_3.x1,line_3.y1,  line_3.x2,line_3.y2);
		drawLine(line_4.x1,line_4.y1,  line_4.x2,line_4.y2);
	}
	}
}
*/
/*
struct pointCoord{
	short x;
	short y;
};
*/
/*
void drawRamkaButton(string butt[], int cnt, COORD nullPos){
	//замеряем рамку

	int R{}, G{}, B{};
	struct pointCoord p1;
	struct pointCoord p2;
	struct pointCoord p3;
	struct pointCoord p4;

	int lenght = cnt;
	int height = 4;

	for (int i=0; i<cnt; i++)
		lenght += butt[i].length()*9;


	int x0 = nullPos.X*9 - 9;
	int y0 = nullPos.Y*20 - height;

	p1.x = x0;
	p1.y = y0;

	p2.x = x0 + lenght + 18;
	p2.y = y0;

	p3.x = p2.x;
	p3.y = y0 + 20 + height;
	p4.x = p1.x;
	p4.y = p3.y;


	drawLine(p1.x,p1.y, p2.x,p2.y);
	drawLine(p2.x,p2.y, p3.x,p3.y);
	drawLine(p3.x,p3.y, p4.x,p4.y);
	drawLine(p4.x,p4.y, p1.x,p1.y);
	int tmp = abs(p1.x - p2.x) / 2 + p1.x - 5;

	drawLine(tmp,p1.y, tmp,p3.y);

}
*/

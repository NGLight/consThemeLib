#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#define _WIN32_WINNT 	0x0500
#include <windows.h>
//Мои либы и функции
#include "nglRandom.h"		//рандом чисел и символов
#include "nglCursor.h"		//управление курсором
#include "nglKeys.h"		//возвращает коды клавиш содежит дефайн с основными клв
#include "nglPixels.h"		//выводит любое изображение по пиксельно в консоль
#include "nglColors.h"		//цвета для шрифтов в консоли
#include "nglMenu.h"		//коризонтальное и вертикальное меню
#include "nglTables.h"		//вывод таблицы с результатами
#include "nglFigures.h"		//рисование фигур в консоли
#include "nglSett.h"        //полноэкранный режим и все такое прочее
#include "nglExp.h"			//эксперементальные функции

//*** МАКРОСЫ ***//
//HWND и HDC для графики
#define SET_HANDLE	    void* hConsole = GetStdHandle(STD_OUTPUT_HANDLE); \
						 HWND hwnd = GetConsoleWindow(); \
						 HDC hdc = GetDC(hwnd);

#define FULL_SCREEN     setlocale (LC_ALL,"Rus");\
                         ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

#define EXIT_0		    END_CHAPTER \
                         WT; cout << "\t Нажмите "; RD; cout << "любую"; WT; cout << " клавишу для выхода... \n"; \
                         showCursor(false); cin.get(); GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT,0);

#define START_REBOOT	setlocale (LC_ALL,"Rus");\
						 bool toRebootMain = true; while (toRebootMain){ \
						 showCursor(true); \
						 ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);


#define EXIT_REBOOT		END_CHAPTER \
						 WT; cout << "\t Нажмите "; CN; cout << "ПРОБЕЛ"; WT; cout << " для перезапуска или "; \
						 RD; cout << "любую другую"; WT; cout << " клавишу для выхода... \n"; \
						 showCursor(false); \
						 toRebootMain = (getKeys() == 0x20) ? (true) : (false); \
						 if (!toRebootMain) { GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT,0);} \
						 else system("cls"); \
						 }

#define FOR(I) 		    for (int i=0; i < I; i++)
#define CLR_LINE	    FOR(8) cout << "."; cout << "\r";


#define TEST_CIN		if (cin.bad() || cin.fail()){ \
						cout << "\t Упс, что-то пошло не так.." << endl; \
						exit(-1);}

//#define FOR(I,C) for (int i=0; i < I; i++) cout << C;
#define END_CHAPTER 	RD; cout << endl; for (int i=0; i < 75; i++, cout << "_"); cout << endl;



using namespace std;



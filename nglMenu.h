#pragma once
#include "nglColors.h"
#include "nglTables.h"
#include "nglExp.h"

#define CNT_LINES_REDRAW 10 //количество строк для отчистки для быстрого обновления экрана
#define FOR(UPPERBOUND,VALUE) for(int I = 0; I<int(UPPERBOUND); I++, cout << char(VALUE)) //ленивая заднциа

/*
* ПОДТВЕРЖДЕНИЕ ВЫХОДА
* ДОБАВИТЬ ПУНКТ КНОПКА-СТРОКА
* ДОБАВИТЬ ВЫПАДАЮЩИЙ СПИСОК
* ДОБАВИТЬ СКРОЛИНГ МЕНЮ
* ПЕРЕДЕЛАТЬ ПУНКТ КНОПКА-ГОРИЗРНТАЛЬНАЯ
* ПЕРЕДЕЛЕАТЬ ПУНКТ ВВОДА
* ПЕРЕДЕЛАТЬ ГЛАВНОЕ МЕНЮ, НА ВХОД ФУНКЦИИ
* ПЕРЕПИСАТЬ ОТЧИСТКУ МЕНЮ
* ДОБАВИТЬ ВЫХОД ЧЕРЕЗ ESC В КАЖДОМ ПУНКИТЕ МЕНЮ
*/


//------------------- ОСНОВНЫЕ -------------------//
//void drawEscButton();
int drawButton(string butt[], int countButt, int selecButt = 0); //рисуем горизонтальные кнопочки
int drawMenu(string butt[], int countButt, int selecPoint = 0); //рисуем обычное вертикальное меню
int drawSettingsMenu(string butt[], int countButt, bool* settPointint, int selecPoint, bool onlyOneSett); //рисуем меню с выбором настроек
int drawInputInt(string menuPoint, int selectPoint);
//------------------- СЛУЖЕБНЫЕ -------------------//
void redrawMenu(); //функция быстрой "перерисовки" экана, на самом деле область замещается пробелами, однако это работает НА МНОГО быстрее system(cls)
void redrawLine();
void drawFrame(int length, int height);
//void drawEscButton(){}

/*
int drawSlider(){

}
*/

///////////////////////// МЕНЮ /////////////////////////
int drawButton(string butt[], int countButt, int selecButt){
	//горизонтальное меню
	showCursor(false);
	CN;

    ///

    //узнаем максимальную длину пункта меню
	//чтоб выделенеи было одинаковым
	/*
	int maxSymb=0;
	for (int i=0; i < countButt; i++){
		if (butt[i].length() > maxSymb)
			maxSymb = butt[i].length();
	}
	*/

	//первая отрисовка
	cout << "\t|";
	for (int i=0; i < countButt; i++, cout << "|"){
		if (i == selecButt){
            HG; cout << "<" << butt[i] << ">"; CN;
            //for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
            //cout << ">"; CN;
        }
		else{
            cout << " " << butt[i] << " ";
            //for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
            //cout << " ";
        }
	}
    //перерисовка до тех пора пока пункт не выполнен
	for (int key = getKeys(); key != BUTT_ENTER; key = getKeys()){

		if (key == BUTT_RIGHT && selecButt < countButt-1)
			selecButt++;
		else if (key == BUTT_LEFT && selecButt > 0)
			selecButt--;

		CN; cout << "\r\t|";
		for (int i=0; i < countButt; i++, cout << "|"){
			if (i == selecButt) {
                HG; cout << "<" << butt[i] << ">"; CN;
                //for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
                //cout << ">"; CN;
            }
			else {
                cout << " " << butt[i] << " ";
                //for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
                //cout << " ";
            }
		}
	}

	///
	cout << endl;
	showCursor(true);
	return selecButt;
}

int drawMenu(string butt[], int countButt, int selecPoint){
	//зацикленное вертикальное меню
	showCursor(false);
	COORD pos;
	CN;
	redrawMenu();
	//узнаем максимальную длину пункта меню
	int maxSymb=0;
	for (int i=0; i < countButt; i++){
		if (butt[i].length() > maxSymb)
			maxSymb = butt[i].length();
	}
	drawFrame(maxSymb, countButt);

	//отрисовываем первоночальное меню
	cout << endl;
	for (int i=0; i < countButt; i++, cout << endl){
	    cout << "\t";
		if (i == selecPoint){
			HG; cout << "<" << butt[i] << ">"; CN;
		}
		else {
			cout << " " << butt[i] << " ";
		}
	}
	//ожидаем кнопку перерисовываем меню и ждем кн выхода
	for (int key = getKeys(); key != BUTT_ENTER; key = getKeys()){

        if (key == BUTT_ESC) return -1;

		if (key == BUTT_UP && selecPoint >= 0){
			if (selecPoint == 0)
				selecPoint = countButt-1;
             else
				selecPoint--;
			}
		else if (key == BUTT_DOWN && selecPoint <= countButt-1){
			if (selecPoint == countButt-1)
				selecPoint = 0;
			else
				selecPoint++;
		}

		returnCursorCOORD(pos);
		pos.Y -= countButt;
		setNewCursorCOORD(pos);

		//перерисовываем меню
		for (int i=0; i < countButt; i++, cout << endl){
            cout << "\t";
			if (i == selecPoint){
				HG; cout << "<" << butt[i] << ">"; CN;
			}
			else {
				cout << " " << butt[i] << " ";
			}
		}
	}
    /////
	showCursor(true);
	CN;
	return selecPoint;
}


int drawSettingsMenu(string butt[], int countButt, bool* settPoint, int selecPoint, bool onlyOneSett){
	//круговое вертикальное меню
	//reDrawMenu отчищает экран
	//ИМЕЕТ ДВА РЕЖИМА
	//onlyOneSett true ТОЛЬКО ОДНА НАСТРОЙКА ИЗ ВСЕХ МОЖЕТ БЫТЬ ВЫБРАНА
	//onlyOneSett false МОЖНО ВЫБРАТЬ ВСЕ НАСТРОЙКИ РАЗОМ
	showCursor(false);
	COORD pos;
	redrawMenu();

    //узнаем максимальную длину пункта меню
	int maxSymb=0;
	for (int i=0; i < countButt; i++){
		if (butt[i].length() > maxSymb)
			maxSymb = butt[i].length();
	}
    drawFrame(maxSymb+3, countButt);
	///

	CN;
	//отрисовываем первоночальное меню
	cout << endl;
	char symbPoint;
	for (int i=0; i < countButt; i++, cout << "\n"){
		if (i == selecPoint){
			HG;
			cout << "\t<";
			symbPoint = (settPoint[i]) ? (31) : (32);
			if (i != countButt-1)
				cout << "[" << symbPoint << "]" << butt[i] << ">";
			else
				cout << butt[i] << ">";
			CN;
		}
		else {
			cout << "\t ";
			symbPoint = (settPoint[i]) ? (31) : (32);
			if (i != countButt-1)
				cout << "[" << symbPoint << "]" << butt[i] << " ";
			else
			cout << butt[i] << " ";
		}
	}

	//ожидаем кнопку перерисовываем меню и ждем кн выхода
	for (int key = getKeys(); key != BUTT_ENTER || selecPoint != countButt-1; key = getKeys()){
       if (key == BUTT_ESC) return -1;
		if (key == BUTT_UP && selecPoint >= 0){
			if (selecPoint == 0)
				selecPoint = countButt-1;
             else
				selecPoint--;
			}
		else if (key == BUTT_DOWN && selecPoint <= countButt-1){
			if (selecPoint == countButt-1)
				selecPoint = 0;
			else
				selecPoint++;
		}
		//если выбранных пунктов может быть много
		if (key == BUTT_ENTER && onlyOneSett == false)
			settPoint[selecPoint] = (settPoint[selecPoint]) ? (false) : (true);
		//если выбранный пункт может быть только один
		else if (key == BUTT_ENTER && onlyOneSett == true){
			for (int i=0; i < countButt; i++)
				settPoint[i] = false;
			settPoint[selecPoint] = (settPoint[selecPoint]) ? (false) : (true);
			}

		returnCursorCOORD(pos);
		pos.Y -= countButt;
		setNewCursorCOORD(pos);

		//перерисовываем меню
		for (int i=0; i < countButt; i++, cout << "\n"){
			if (i == selecPoint){
                HG;
				symbPoint = (settPoint[i]) ? (31) : (32);
				if (i != countButt-1){
					 cout << "\t<" << "[" << symbPoint << "]" << butt[i] << ">";
				}
				else{
					cout << "\t<" << butt[i] << ">";
				}
				CN;
			}
			else {
				symbPoint = (settPoint[i]) ? (31) : (32);
				if (i != countButt-1){
					cout << "\t " << "[" << symbPoint << "]" << butt[i] << " ";
					}
				else{
					cout << "\t " <<  butt[i] << " ";
				}
			}
		}
	}


    /////
	showCursor(true);
	CN;
	return selecPoint;
}


int drawInputMenu(string butt[], string value[], int countButt, int selecPoint=0){
	//зацикленное вертикальное меню
	showCursor(false);
	COORD pos;
	redrawMenu();

	CN;
	//отрисовываем первоночальное меню
	cout << endl;
	for (int i=0; i < countButt; i++, cout << "\n"){
		if (i == selecPoint){
			HG; cout << "\t<" << butt[i];
			if (value[i].length())
                cout << ":     " << value[i];
            cout << ">";
            CN;
		}
		else {
			cout << "\t " << butt[i];
            if (value[i].length())
                cout << ":     " << value[i];
            cout << " ";
		}
	}
	//ожидаем кнопку перерисовываем меню и ждем кн выхода
	for (int key = getKeys(); key != BUTT_ENTER; key = getKeys()){
        if (key == BUTT_ESC) return -1;
		if (key == BUTT_UP && selecPoint >= 0){
			if (selecPoint == 0)
				selecPoint = countButt-1;
             else
				selecPoint--;
			}
		else if (key == BUTT_DOWN && selecPoint <= countButt-1){
			if (selecPoint == countButt-1)
				selecPoint = 0;
			else
				selecPoint++;
		}

		returnCursorCOORD(pos);
		pos.Y -= countButt;
		setNewCursorCOORD(pos);

		//перерисовываем меню
		for (int i=0; i < countButt; i++, cout << "\n"){
			if (i == selecPoint){
				HG; cout << "\t<" << butt[i];
                if (value[i].length())
                cout << ":     " << value[i];
            cout << ">";
            CN;
			}
			else {
				cout << "\t " << butt[i];
                if (value[i].length())
                cout << ":     " << value[i];
            cout << " ";
			}
		}
	}


	///
	showCursor(true);
	CN;
	return selecPoint;
}

int drawInputInt(string menuPoint, int selectPoint, int curValue){
    /*
    * ДОБАВИТЬ ОГРАНИЧЕНИЯ ПО КОЛИЧЕСТВУ ЦИФР
    * маленький баг с вводом двух нулей подряд
    */
	int a;
	//спускаемся на высоту выбранного пункта меню
	COORD pos, posEnter;
	pos.Y = 1 + selectPoint;
	//pos.X = 8 + menuPoint.length() + 7;
	setNewCursorCOORD(pos);
	redrawLine();
	RD;
    cout << "\t" << menuPoint << ": ";
	showCursor(true);
	returnCursorCOORD(pos);
	cout << curValue;

	int i = 1;
	int tmp = curValue;

	int minus = curValue+1;  //нарекаю сей костыль ГИППЕРКОСТЫЛЕМ
	//а в чем же его суть? спросит меня незадачливый читатель...
	//А ВСЕ ДЕЛО В АТТЦЦКОМ МИНУС НУЛЕ!!!!

	for (short key = getKeys(); key != BUTT_ENTER; i++, key = getKeys()){
        if (key == BUTT_ESC) return curValue;

        if (key > 47 && key < 58){
            cout << (key-48);
            tmp *= 10;
            tmp += (key-48);
        }

        if (key == '-') {
            minus *= -1;
            tmp *= -1;
            cout << "\t\t\t\t\t\r";
            setNewCursorCOORD(pos);
        }

        if (key == BUTT_BACKSPACE && i >= 1){
            tmp /= 10;
            i--;
            cout << "\t\t\t\t\t\r";
            setNewCursorCOORD(pos);
        }
        //обнуляем строку
        cout << "\t\t\t\t\t\r";
        setNewCursorCOORD(pos);
        if (minus < 0) cout << "-";
        cout << abs(tmp);
	}




	showCursor(false);
	CN;
    return tmp;
}


double drawInputDouble(string menuPoint, int selectPoint, double curValue){
    //для подробных комментариев см функцию drawInputInt
    /*
    * ПРИДУМАТЬ СПОСОБ ВВОДА ТОЧКИ
    * ДОБАВИТЬ ОГРАНИЧЕНИЯ ПО КОЛИЧЕСТВУ ЦИФР
    * маленький баг с вводом двух нулей подряд
    */
	double b;
	COORD pos, posEnter;
	pos.Y = 1 + selectPoint;
	setNewCursorCOORD(pos);
	redrawLine();
	RD;
    cout << "\t" << menuPoint << ": ";
	showCursor(true);
	returnCursorCOORD(pos);
	cout << curValue;

	int i = 1;
	int tmp = curValue;

	int minus = curValue+1;  //см функцию drawInputInt

	for (short key = getKeys(); key != BUTT_ENTER; i++, key = getKeys()){
        if (key == BUTT_ESC) return curValue;

        if (key > 47 && key < 58){
            cout << (key-48);
            tmp *= 10;
            tmp += (key-48);
        }

        if (key == '-') {
            minus *= -1;
            tmp *= -1;
            //redrawLine();
            cout << "\t\t\t\t\t\r";
            setNewCursorCOORD(pos);
        }

        if (key == BUTT_BACKSPACE && i >= 1){
            tmp /= 10;
            i--;
            //redrawLine();
            cout << "\t\t\t\t\t\r";
            setNewCursorCOORD(pos);
        }
        //обнуляем строку
        //redrawLine();
        //setNewCursorCOORD(pos);
        cout << "\t\t\t\t\t\r";
        setNewCursorCOORD(pos);
        if (minus < 0) cout << "-";
        cout << abs(tmp);
	}




	showCursor(false);
	CN;
    return tmp;
}

void redrawMenu(){
	COORD pos = {0,0};
	setNewCursorCOORD(pos);
	for (int i=0; i<CNT_LINES_REDRAW; i++, cout << "\t\t\t\t\t\r\n");
	pos.X = 0; pos.Y = 0;
	setNewCursorCOORD(pos);
}

void redrawLine(){
	COORD pos;
	returnCursorCOORD(pos);
	//FOR(20,32);
	for (int i=0; i < 3; i++) cout << "          ";
	//cout << "\t\t\t\t\t\r";
	setNewCursorCOORD(pos);
}


void exitMenu(){
    //setNewCursorCOORD(pos);
    ///
    int cntButt = 2;
    string butt[cntButt];
    butt[0] = {"    Yes    "};
    butt[1] = {"    No   "};
    drawButton(butt, cntButt);

}

void drawFrame(int length, int height){
//функция отрисовывает вокруг меню прямоугольник, не более того
	COORD pos;
	returnCursorCOORD(pos);
    /*
	218 + 196 - 194 + 196 - 191 +
	179 ¦		179 ¦		179 ¦
	195 + 196 - 197 + 196 - 180 +
	179 ¦		179 ¦		179 ¦
	192 + 196 - 193 + 196 - 217 +
	*/
	//32 ' '
	//10 '\n'
    setlocale (LC_ALL,"C");
    FOR(7,32); FOR(1,218); FOR(length+2,196); FOR(1,191);
    FOR(height+1, 10);
    FOR(7,32); FOR(1,192); FOR(length+2,196); FOR(1,217);
    setlocale (LC_ALL,"Rus");
    setNewCursorCOORD(pos);
}

void drawMessageBox(){
    //функция вывода текстового сообщения в меню
    //выводит и стирает за собой текстовые сообщения
}

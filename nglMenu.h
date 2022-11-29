#pragma once
#include "nglColors.h"
#include "nglTables.h"
#include "nglExp.h"

#define CNT_LINES_REDRAW 10 //���������� ����� ��� �������� ��� �������� ���������� ������
#define FOR(UPPERBOUND,VALUE) for(int I = 0; I<int(UPPERBOUND); I++, cout << char(VALUE)) //������� �������

/*
* ������������� ������
* �������� ����� ������-������
* �������� ���������� ������
* �������� �������� ����
* ���������� ����� ������-��������������
* ����������� ����� �����
* ���������� ������� ����, �� ���� �������
* ���������� �������� ����
* �������� ����� ����� ESC � ������ ������� ����
*/


//------------------- �������� -------------------//
//void drawEscButton();
int drawButton(string butt[], int countButt, int selecButt = 0); //������ �������������� ��������
int drawMenu(string butt[], int countButt, int selecPoint = 0); //������ ������� ������������ ����
int drawSettingsMenu(string butt[], int countButt, bool* settPointint, int selecPoint, bool onlyOneSett); //������ ���� � ������� ��������
int drawInputInt(string menuPoint, int selectPoint);
//------------------- ��������� -------------------//
void redrawMenu(); //������� ������� "�����������" �����, �� ����� ���� ������� ���������� ���������, ������ ��� �������� �� ����� ������� system(cls)
void redrawLine();
void drawFrame(int length, int height);
//void drawEscButton(){}

/*
int drawSlider(){

}
*/

///////////////////////// ���� /////////////////////////
int drawButton(string butt[], int countButt, int selecButt){
	//�������������� ����
	showCursor(false);
	CN;

    ///

    //������ ������������ ����� ������ ����
	//���� ��������� ���� ����������
	/*
	int maxSymb=0;
	for (int i=0; i < countButt; i++){
		if (butt[i].length() > maxSymb)
			maxSymb = butt[i].length();
	}
	*/

	//������ ���������
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
    //����������� �� ��� ���� ���� ����� �� ��������
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
	//����������� ������������ ����
	showCursor(false);
	COORD pos;
	CN;
	redrawMenu();
	//������ ������������ ����� ������ ����
	int maxSymb=0;
	for (int i=0; i < countButt; i++){
		if (butt[i].length() > maxSymb)
			maxSymb = butt[i].length();
	}
	drawFrame(maxSymb, countButt);

	//������������ �������������� ����
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
	//������� ������ �������������� ���� � ���� �� ������
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

		//�������������� ����
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
	//�������� ������������ ����
	//reDrawMenu �������� �����
	//����� ��� ������
	//onlyOneSett true ������ ���� ��������� �� ���� ����� ���� �������
	//onlyOneSett false ����� ������� ��� ��������� �����
	showCursor(false);
	COORD pos;
	redrawMenu();

    //������ ������������ ����� ������ ����
	int maxSymb=0;
	for (int i=0; i < countButt; i++){
		if (butt[i].length() > maxSymb)
			maxSymb = butt[i].length();
	}
    drawFrame(maxSymb+3, countButt);
	///

	CN;
	//������������ �������������� ����
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

	//������� ������ �������������� ���� � ���� �� ������
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
		//���� ��������� ������� ����� ���� �����
		if (key == BUTT_ENTER && onlyOneSett == false)
			settPoint[selecPoint] = (settPoint[selecPoint]) ? (false) : (true);
		//���� ��������� ����� ����� ���� ������ ����
		else if (key == BUTT_ENTER && onlyOneSett == true){
			for (int i=0; i < countButt; i++)
				settPoint[i] = false;
			settPoint[selecPoint] = (settPoint[selecPoint]) ? (false) : (true);
			}

		returnCursorCOORD(pos);
		pos.Y -= countButt;
		setNewCursorCOORD(pos);

		//�������������� ����
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
	//����������� ������������ ����
	showCursor(false);
	COORD pos;
	redrawMenu();

	CN;
	//������������ �������������� ����
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
	//������� ������ �������������� ���� � ���� �� ������
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

		//�������������� ����
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
    * �������� ����������� �� ���������� ����
    * ��������� ��� � ������ ���� ����� ������
    */
	int a;
	//���������� �� ������ ���������� ������ ����
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

	int minus = curValue+1;  //������� ��� ������� ��������������
	//� � ��� �� ��� ����? ������� ���� ������������ ��������...
	//� ��� ���� � �������� ����� ����!!!!

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
        //�������� ������
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
    //��� ��������� ������������ �� ������� drawInputInt
    /*
    * ��������� ������ ����� �����
    * �������� ����������� �� ���������� ����
    * ��������� ��� � ������ ���� ����� ������
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

	int minus = curValue+1;  //�� ������� drawInputInt

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
        //�������� ������
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
//������� ������������ ������ ���� �������������, �� ����� ����
	COORD pos;
	returnCursorCOORD(pos);
    /*
	218 + 196 - 194 + 196 - 191 +
	179 �		179 �		179 �
	195 + 196 - 197 + 196 - 180 +
	179 �		179 �		179 �
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
    //������� ������ ���������� ��������� � ����
    //������� � ������� �� ����� ��������� ���������
}

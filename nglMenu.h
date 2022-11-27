#pragma once
#include "nglColors.h"
#include "nglTables.h"
#include "nglExp.h"

#define CNT_LINES_REDRAW 10 //���������� ����� ��� �������� ��� �������� ���������� ������

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
// ������� int drawSettingsMenu(string butt[], int countButt, bool* settPointint, int selecPoint, bool onlyOneSett); //������ ���� � ������� ��������
//------------------- ��������� -------------------//
void redrawMenu(); //������� ������� "�����������" �����, �� ����� ���� ������� ���������� ���������, ������ ��� �������� ������� system(cls)
void drawFrame(int length, int height);
//void drawEscButton(){}

/*
int drawSlider(){

}
*/

///////////////////////// ���� /////////////////////////
int drawButton(string butt[], int countButt, int selecButt){
	//�������������� ����
	setlocale (LC_ALL,"Rus");
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
            //for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
		}
		else {
			cout << " " << butt[i] << " ";
			//for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
			//cout << " ";
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
				//for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
				//cout << ">"; CN;
			}
			else {
				cout << " " << butt[i] << " ";
				//for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
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
	setlocale (LC_ALL,"Rus");
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
			//��������� ������� ��������� ��� ����������� ���������
			//for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
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
				cout << "\t<";
				symbPoint = (settPoint[i]) ? (31) : (32);
				if (i != countButt-1){
					cout << "[" << symbPoint << "]" << butt[i] << ">";
					//for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
				}
				else{
					cout << butt[i] << ">";
					//��������� ������� ��������� ��� ����������� ���������
					//for (int j = butt[i].length(); j < maxSymb+3; j++, cout << " ");
				}
				CN;
			}
			else {
				cout << "\t ";
				symbPoint = (settPoint[i]) ? (31) : (32);
				if (i != countButt-1){
					cout << "[" << symbPoint << "]" << butt[i] << " ";
					//for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
					}
				else{
					cout << butt[i] << " ";
					//for (int j = butt[i].length(); j < maxSymb+3; j++, cout << " ");
				}
			}
		}
	}


    /////
	showCursor(true);
	CN;
	return selecPoint;
}


int drawInputMenu(string butt[],int countButt, int selecPoint=0){
	//����������� ������������ ����
	setlocale (LC_ALL,"Rus");
	showCursor(false);
	COORD pos;
	redrawMenu();

	CN;
	//������������ �������������� ����
	cout << endl;
	for (int i=0; i < countButt; i++, cout << "\n"){
		if (i == selecPoint){
			HG; cout << "\t<" << butt[i] << " "; CN;
			//��������� ������� ��������� ��� ����������� ���������
			//for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
		}
		else {
			cout << "\t " << butt[i] << " ";
		}
	}
	//������� ������ �������������� ���� � ���� �� ������
	for (int key = getKeys(); key != BUTT_ENTER; key = getKeys()){
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
				HG; cout << "\t<" << butt[i] << ">"; CN;
				//for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
			}
			else {
				cout << "\t " << butt[i] << " ";
				//for (int j = butt[i].length(); j < maxSymb; j++, cout << " ");
			}
		}
	}


	///
	showCursor(true);
	CN;
	return selecPoint;
}

double drawInputTable(string lable, string MessageOfError, bool error = false){
//� ����� ��������� ���������� ������� ��� ����� ���

	/*
	* ������ �������� �� POS.Y POS.X � �������� ������������� ��������
	*
	*/


	setlocale (LC_ALL,"Rus");
	showCursor(false);
	redrawMenu();
	double tmp;
	COORD pos;

	//����� �������� ����������
	setColor(White);
	cout << "\n\t" << lable << "\n";

	//�������� ��� ����� ����������
	short countLine = 1, countRow = 1;
	short sizeRow[] = {20};
	drawBasicTable(countLine, countRow, sizeRow);

	//��� �������� ����������
	string lableType;
	lableType = {" double "};
	pos = {31, 3};
	setNewCursorCOORD(pos);
	cout << lableType;

	//������� ��������� �� ������ ���� ����� ����� ����
	if (error){
		pos = {9, 5};
		setNewCursorCOORD(pos);
		setColor(Red);
		cout << MessageOfError;
	}

	//���������� ������ � ��������
	setColor(Red);
	pos = {9,3};
	setNewCursorCOORD(pos);
	showCursor(true);
	setColor(Red);
	cin >> tmp;

	if (cin.bad() || cin.fail()){
		cin.clear();
		exit(-1);
	}

	showCursor(true);
	setColor(Red);
	return tmp;
}

int drawInputTable_int(string lable, string MessageOfError, bool error = false){
//� ����� ��������� ���������� ������� ��� ����� ���
	setlocale (LC_ALL,"Rus");
	showCursor(false);
	redrawMenu();
	double tmp;
	COORD pos;

	//����� �������� ����������
	setColor(White);
	cout << "\n\t" << lable << "\n";

	//�������� ��� ����� ����������
	short countLine = 1, countRow = 1;
	short sizeRow[] = {20};
	drawBasicTable(countLine, countRow, sizeRow);

	//��� �������� ����������
	string lableType;
	lableType = {" int "};
	pos = {31, 3};
	setNewCursorCOORD(pos);
	cout << lableType;

	//������� ��������� �� ������ ���� ����� ����� ����
	if (error){
		pos = {9, 5};
		setNewCursorCOORD(pos);
		setColor(Red);
		cout << MessageOfError;
	}

	//���������� ������ � ��������
	setColor(Red);
	pos = {9,3};
	setNewCursorCOORD(pos);
	showCursor(true);
	setColor(Red);
	cin >> tmp;

	if (cin.bad() || cin.fail()){
		cin.clear();
		exit(-1);
	}

	showCursor(true);
	setColor(Red);
	return tmp;
}

void redrawMenu(){
	//showCursor(false);
	COORD pos = {0,0};
	setNewCursorCOORD(pos);
	for (int i=0; i<CNT_LINES_REDRAW; i++, cout << "\t\t\t\t\t\r\n");
	pos.X = 0; pos.Y = 0;
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


//������� ������������ ������ ���� �������������, �� ����� ����
#define FOR(UPPERBOUND,VALUE) for(int I = 0; I<int(UPPERBOUND); I++, cout << char(VALUE))
void drawFrame(int length, int height){
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


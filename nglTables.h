#pragma once

///////////////////////// ТАБЛИЦЫ /////////////////////////
#define FOR(UPPERBOUND,VALUE) for(int I = 0; I<int(UPPERBOUND); I++, cout << char(VALUE))
void drawBasicTable(short countLine, short countRow, short sizeRow[]){
	showCursor(false);
	COORD pos;
	int x_0=0; int y_0=0;
	if (x_0 || y_0){
		pos.X += x_0;
		pos.Y += y_0;
		setNewCursorCOORD(pos);
	}
	setlocale (LC_ALL,"C"); //на время отрисовки таблицы возвращаем локаль в С ибо символы
    setColor(White);
	/*
	218 + 196 - 194 + 196 - 191 +
	179 ¦		179 ¦		179 ¦
	195 + 196 - 197 + 196 - 180 +
	179 ¦		179 ¦		179 ¦
	192 + 196 - 193 + 196 - 217 +
	*/
	cout << "\t";
	FOR(1,218);
	for (int j=0; j < countRow; j++){
		FOR(sizeRow[j], 196);
		if (j !=  countRow-1)
			FOR(1,194);
		else
			FOR(1,191);
	}
	cout << "\n\t";
	//конец шапки
	FOR(1,179);
	for (int j=0; j < countRow; j++){
		FOR(sizeRow[j], ' ');
		if (j !=  countRow-1)
			FOR(1,179);
		else
			FOR(1,179);
	}
	cout << "\n\t";
	for (int i=0; i < countLine; i++){
		if (i != countLine -1){
			FOR(1,195);
			for (int j=0; j < countRow; j++){
				FOR(sizeRow[j], 196);
				if (j !=  countRow-1)
					FOR(1,197);
				else
					FOR(1,180);
			}
			cout << "\n\t";
			FOR(1,179);
			for (int j=0; j < countRow; j++){
				FOR(sizeRow[j], ' ');
				if (j !=  countRow-1)
					FOR(1,179);
				else
					FOR(1,179);
			}
			cout << "\n\t";
		}
		else {
			FOR(1,192);
			for (int j=0; j < countRow; j++){
				FOR(sizeRow[j], 196);
			if (j !=  countRow-1)
				FOR(1,193);
			else
				FOR(1,217);
			}
		cout << "\n\t";
		}
	}
	//возвращаем локаль в Rus ибо русский
	setlocale(LC_ALL, "Rus");
}

void fillTable (short countLine, short countRow, short sizeRow[], int x_0=0, int y_0=0){
	setlocale (LC_ALL,"Rus");
	int test = 1;
	//возвращаем курсор в начало таблицы
	COORD pos, pos_0;
	returnCursorCOORD(pos);
	pos_0 = pos;
	pos.X += 1;
	pos.Y -= countLine*2;
	setNewCursorCOORD(pos);

	for (int i=0; i < countLine; i++, pos.X = pos_0.X+1, pos.Y += 2, setNewCursorCOORD(pos)){
		for (int j=0; j < countRow; j++){
			cout << j;
			pos.X += sizeRow[j]+1;
			setNewCursorCOORD(pos);
		}
	}
		/*
			//вывод до троеточияxev
			if (sizeRow[j] < 4 && sizeRow[j] < tmp.length())
				cout << "!";

			else if (sizeRow[j] >= 4 && sizeRow[j] < tmp.length()){
				for (int l=0; l < sizeRow[j]-3; l++)
					cout << tmp[l];
				cout << "...";
			}
			else
				cout << tmp;
			y += sizeRow[j]+1;
		*/

	//ВЫВОДИМ КООРДЫ КОЛОНОК ДЛЯ КУРСОРА И ЗНАЧЕНИЯ +1 ПО X/Y
}


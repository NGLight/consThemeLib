#pragma once
#include <time.h>
#include <iostream>
using namespace std;


bool random();
int random(int min, int max);
double random(double min, double max);
char random_char();
///////////////////////// РАНДОМ /////////////////////////
bool random(){
	srand(time(NULL) + rand());
	bool min = false;
	bool max = true;
	bool n = min + rand()%(max - min + 1);
	return n;
}

int random(int min, int max){
	srand(time(NULL) + rand());
	int n = min + rand()%(max - min + 1);
	return n;
}

double random(double min, double max){
	srand(time(NULL) + rand());
	double n = (double)rand()/(double) RAND_MAX*(max-min)+min;
	return n;
}

char random_capital(){
	string tmpString={"ABCDEFGHIJKLMNOPRSTUVWXYZ"};
	srand(time(NULL) + rand());
	int lengthString = tmpString.length();
	char c = tmpString[random(0, lengthString-1)];
	return c;
}

char random_letter(){
	string tmpString={"abcdefghijklmnoprstuvwxyz"};
	srand(time(NULL) + rand());
	int lengthString = tmpString.length();
	char c = tmpString[random(0, lengthString-1)];
	return c;
}

//возвращает одну случайную букву
char random_char(){
	char c;
	srand(time(NULL) + rand());
	int tmp = random(1,2);
	if (tmp == 1) c = random(65, 90);
	else c = random(97, 122);
	return c;
}


//возвращает одну случайную букву
char random_vowel(){
	char c;
	int i = random(0,11);
	srand(time(NULL) + rand());
	string tmpString = {"AaEeIiOoUuYy"};
	c = tmpString[i];
	return c;
}

char rendom_symbol(){
	char c;
	srand(time(NULL) + rand());
	c = random (1,7);
	switch (c){
		case 1: c = ','; break;
		case 2: c = '.'; break;
		case 3: c = ';'; break;
		case 4: c = ':'; break;
		case 5: c = '-'; break;
		case 6: c = '?'; break;
		case 7: c = '!'; break;
	}
	return c;
}

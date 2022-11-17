#pragma once
#define SET_HANDLE	 void* hConsole = GetStdHandle(STD_OUTPUT_HANDLE); \
						HWND hwnd = GetConsoleWindow(); \
						HDC hdc = GetDC(hwnd);


void drawPic(string fileName, int x_0=0, int y_0=0, double scale = 1){
	SET_HANDLE;
	COORD pos;
	if (!x_0 || !y_0){
        returnCursorCOORD(pos);
        x_0 = pos.X;
        y_0 = pos.Y;
	}
	// c_str() возвращает string строку как const char* (в стили С)
	//ибо ifstream отказывается работать со стрингом
	fileName = "C:/Users/Flynn/Desktop/Proga/pic/" + fileName;

	ifstream fin (fileName.c_str());
	if (!fin.is_open()){
		cout << "Проверь картинку в каталоге" << endl;
		exit(-1);
	}
	//читаем размер картинкии, размер записан в первых двух числах файла.h
	int height, width;
	fin >> height >> width;

	unsigned int pic[height][width];
	for (int i=0; i <height; i++)
        for (int j=0; j <width; j++)
            pic[height][width] = 0;
	for (int i=0; i < height; i++)
		for (int j=width; j > 0; j--)
			fin >> hex >> pic[i][j];

	unsigned char R{}, G{}, B{};
	for (int i=0; i < width; i++)
		for (int j=height; j > 0; j--){

			R = (unsigned char)(pic[i][j] / 0x10000);
			G = (unsigned char)(pic[i][j] / 0x100) % 0x100;
			B = (unsigned char)(pic[i][j] % 0x10000);

			if (R || G || B)
				SetPixel(hdc, int(i*scale) + x_0, int(j*scale) + y_0, RGB(R, G, B));

		}

	ReleaseDC(hwnd, hdc);
	fin.close();

}

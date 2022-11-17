#pragma once
#include "nglExp.h"

///////////////////////// ФИГУРЫ /////////////////////////
void drawCircle(double r){
	SET_HANDLE;
	r *= 10;
	int y_0 = 400;
	int x_0 = 1000;
	double x, y;
	char R = 0;
	char G = 200;
	char B = 255;

	for (double n = 0, dn = 1/r; n < 2*3.14; n += dn){
		x = x_0 + (r-1)*cos(n);
		y = y_0 + (r-1)*sin(n);
		//cout << dn;
		SetPixel(hdc, x, y, RGB(R, G, B));
	}
}

void drawPoint(int x_0, int y_0, unsigned short R=255, unsigned short G=255, unsigned short B=255){
	//x_0 = (x_0*10);
	//y_0 = (y_0*10);
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

void drawTEST(double k, double b){
	SET_HANDLE;
	int y_0 = int((b*10)*(-1) + 400);
	int x_0 = 1000;

	double x, y, r;
	char R = 255;
	char G = 30;
	char B = 30;
	for (r=3; r>0; r--)
		for (double n = 0, dn = 1/r; n < 2*3.14; n += dn){
			x = x_0 + (r-1)*cos(n);
			y = y_0 + (r-1)*sin(n);
			//cout << dn;
			SetPixel(hdc, x, y, RGB(R, G, B));
		}
	R = 30;
	G = 255;
	B = 30;
	y_0 = 400;
	x_0 = int(b*10*(-1) / k) + 1000;
	for (r=3; r>0; r--)
		for (double n = 0, dn = 1/r; n < 2*3.14; n += dn){
			x = x_0 + (r-1)*cos(n);
			y = y_0 + (r-1)*sin(n);
			//cout << dn;
			SetPixel(hdc, x, y, RGB(R, G, B));
		}
}

void drawLine(int x1,int y1, int x2, int y2){
	//алгоритм Брезенхема
	SET_HANDLE;
	char col = 255;
    int x, y, xend, yend, s, dx, dy, d, inc1, inc2;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    if (dx > dy)
    {
        inc1 = 2*dy;
        inc2 = 2*(dy - dx);
        d = 2*dy - dx;
        if (x1 < x2){
            x = x1; y = y1; xend = x2;
            if (y1 < y2) s = 1;
            else s = -1;
        }
        else{
            x = x2;
            y = y2;
            xend = x1;
            if (y1 > y2)s = 1;
            else s = -1;
        }
        SetPixel(hdc, x, y, RGB(col, col, col));
        while (x < xend){
            x++;
            if (d > 0)
            {
                y+=s;
                d+=inc2;
            }
            else
                d+=inc1;
           SetPixel(hdc, x, y, RGB(col, col, col));
        }
    }
    else{
        inc1 = 2*dx;
        inc2 = 2*(dx - dy);
        d = 2*dx - dy;
        if (y1 < y2){
            y = y1; x = x1; yend = y2;
            if (x1 < x2) s = 1;
            else s = -1;
        }
        else{
            y = y2;
            x = x2;
            yend = y1;
            if (x1 > x2)s = 1;
            else s = -1;
        }
       SetPixel(hdc, x, y, RGB(col, col, col));
        while (y < yend){
            y++;
            if (d > 0){
                x+=s;
                d+=inc2;
            }
            else
                d+=inc1;
           SetPixel(hdc, x, y, RGB(col, col, col));
        }
    }
}
/*
void drawLineStruct(struct pointCoord pt1, struct pointCoord pt2){

	int x1 = pt1.x;
	int y1 = pt1.y;

	int x2 = pt2.x;
	int y2 = pt2.y;

	char col = 255;
	//алгоритм Брезенхема
	SET_HANDLE;
    int x, y, xend, yend, s, dx, dy, d, inc1, inc2;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    if (dx > dy)
    {
        inc1 = 2*dy;
        inc2 = 2*(dy - dx);
        d = 2*dy - dx;
        if (x1 < x2){
            x = x1; y = y1; xend = x2;
            if (y1 < y2) s = 1;
            else s = -1;
        }
        else{
            x = x2;
            y = y2;
            xend = x1;
            if (y1 > y2)s = 1;
            else s = -1;
        }
        SetPixel(hdc, x, y, RGB(col, col, col));
        while (x < xend){
            x++;
            if (d > 0)
            {
                y+=s;
                d+=inc2;
            }
            else
                d+=inc1;
           SetPixel(hdc, x, y, RGB(col, col, col));
        }
    }
    else{
        inc1 = 2*dx;
        inc2 = 2*(dx - dy);
        d = 2*dx - dy;
        if (y1 < y2){
            y = y1; x = x1; yend = y2;
            if (x1 < x2) s = 1;
            else s = -1;
        }
        else{
            y = y2;
            x = x2;
            yend = y1;
            if (x1 > x2)s = 1;
            else s = -1;
        }
       SetPixel(hdc, x, y, RGB(col, col, col));
        while (y < yend){
            y++;
            if (d > 0){
                x+=s;
                d+=inc2;
            }
            else
                d+=inc1;
           SetPixel(hdc, x, y, RGB(col, col, col));
        }
    }
}
*/

void drawAxes(){
	//ось x
	drawLine(1000,300,1000,500);
	drawLine(1000,300,995,310);
	drawLine(1000,300,1005,310);
	//ось y
	drawLine(900,400,1100,400);
	drawLine(1100,400,1090,405);
	drawLine(1100,400,1090,395);

}

void drawLine_2(double k,double b){
	SET_HANDLE;

	int x1, x2, y1, y2;
	x1 = 1000;
	y1 = int((b*10)*(-1) + 400);

	x2 = int(b*10*(-1) / k) + 1000;
	y2 = 400;

//	x1 = int(b*10*(-1) / k) + 900;
//	y2 = int((b*(-1)*10) + 500);
//
//	y1 = int((b*(-1)*10) + 300);
//	x2 = int(b*10*(-1) / k) + 1100;

//	if (y_0 > 0 && x_0 > 0){
//		x1 = int(b*10*(-1) / k) + 900;
//		y1 = 300;
//
//		x2 = int(b*10*(-1) / k) + 1100;
//		y2 = 500;
//	}

	char R = 30;
	char G = 100;
	char B = 255;

    int x, y, xend, yend, s, dx, dy, d, inc1, inc2;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    if (dx > dy)
    {
        inc1 = 2*dy;
        inc2 = 2*(dy - dx);
        d = 2*dy - dx;
        if (x1 < x2){
            x = x1; y = y1; xend = x2;
            if (y1 < y2) s = 1;
            else s = -1;
        }
        else{
            x = x2;
            y = y2;
            xend = x1;
            if (y1 > y2)s = 1;
            else s = -1;
        }
        SetPixel(hdc, x, y, RGB(R, G, B));
        while (x < xend){
            x++;
            if (d > 0)
            {
                y+=s;
                d+=inc2;
            }
            else
                d+=inc1;
           SetPixel(hdc, x, y, RGB(R, G, B));
        }
    }
    else{
        inc1 = 2*dx;
        inc2 = 2*(dx - dy);
        d = 2*dx - dy;
        if (y1 < y2){
            y = y1; x = x1; yend = y2;
            if (x1 < x2) s = 1;
            else s = -1;
        }
        else{
            y = y2;
            x = x2;
            yend = y1;
            if (x1 > x2)s = 1;
            else s = -1;
        }
       SetPixel(hdc, x, y, RGB(R, G, B));
        while (y < yend){
            y++;
            if (d > 0){
                x+=s;
                d+=inc2;
            }
            else
                d+=inc1;
           SetPixel(hdc, x, y, RGB(R, G, B));
        }
    }
    //уже лень комментить...
	double r;
	R = 30; G = 70; B = 255;
	for (r=3; r>0; r--)
		for (double n = 0, dn = 1/r; n < 2*3.14; n += dn){
			x = x1 + (r-1)*cos(n);
			y = y1 + (r-1)*sin(n);
			SetPixel(hdc, x, y, RGB(R, G, B));
		}
	for (r=3; r>0; r--)
		for (double n = 0, dn = 1/r; n < 2*3.14; n += dn){
			x = x2 + (r-1)*cos(n);
			y = y2 + (r-1)*sin(n);
			SetPixel(hdc, x, y, RGB(R, G, B));
		}
}


/*
RGB2HSV (unsigned int &hue, unsigned char &sat, unsigned char &val,

unsigned char r, unsigned char g, unsigned char b)

/*

* 0 <= r,g,b <= 255 - значения красного, зеленого, синего

*

*

* Выход:

* 0 <= hue <= 360 градусов - оттенок.

* 0 <= sat <= 255 - Saturation - насыщенность

* 0 <= val <= 255 - Value - яркость

*

  {
    double h, rc, gc, bc, dmax;
    unsigned char s, v;
	unsigned char minc, maxc;

    maxc = (r > g) ? ((r > b) ? r : b) : ((g > b)? g : b);
    minc = (r < g) ? ((r < b) ? r : b) : ((g < b)? g : b);

    s = 0; // Насыщенность
    if (maxc){
         s = (maxc - minc) * 255 / maxc;
      }

    sat = s;
    val = maxc;

    if (!s){ // Ахроматический цвет
        hue = UNDEFINED_HUE;
      }
    else
      { // Хроматический цвет

        dmax = maxc - minc;

        rc = (maxc - r) / dmax; /* rc - удаленность *

        gc = (maxc - g) / dmax; /* цвета от красного *

        bc = (maxc - b) / dmax;

        if (r == maxc)

          { // Цвет между желтым и пурпурным

            h = bc - gc;

          }

        else if (g == maxc)

          { // Цвет между голубым и желтым

            h = 2 + rc - bc;

          }

        else

          { // Цвет между пурпурным и голубым

            h = 4 + gc - rc;

          }

        h *= 60.0;

        if (h < 0.0)

          {

             h += 360.0;

          }

        hue = h;

        if (hue == 360)

          {

              hue = 0;

          }

      } // if (!s)

  } // RGB 2 HSV
  */

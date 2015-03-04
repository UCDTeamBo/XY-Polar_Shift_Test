// Testing_R_Value.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

//#include "houghClass.h"
#include <cmath>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#define DEG2RAD 0.017453293f
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 1;
	int y = 1;

	int center_x = 50;
	int center_y = 50;

	int _img_w = 2 * center_x;
	int _img_h = 2 * center_y;

	double hough_h = ((sqrt(2.0) * (double)(2*(center_y)>2*(center_x) ? 2*(center_y) : 2*(center_x))) / 2.0);
	double _accu_h = hough_h * 2.0; // -r -> +r
	double _accu_w = 180;

	for (int t = 0; t < 180; t++)
	{
		double r = (((double)x - center_x) * cos((double)t * DEG2RAD)) + (((double)y - center_y) * sin((double)t * DEG2RAD));
		//_accu[(int)((round(r + hough_h) * 180.0)) + t]++;
		//cout << "should not be more than 1600 " << r << " Row X: " << y << " Column Y: " << x << endl;
		//cout << "R values: " << r << endl;

		float x1, y1, x2, y2;
		x1 = y1 = x2 = y2 = 0;

		if (t >= 45 && t <= 135)
		{
			//y = (r - x cos(t)) / sin(t)
			x1 = 0;
			y1 = ((double)(r) - ((x1-center_x) * cos(t * DEG2RAD))) / sin(t * DEG2RAD);
			x2 = _img_w - 0;
			y2 = ((double)(r) - ((x2-center_x) * cos(t * DEG2RAD))) / sin(t * DEG2RAD);
		}
		else
		{
			//x = (r - y sin(t)) / cos(t);
			y1 = 0;
			x1 = ((double)(r) - ((y1) * sin(t * DEG2RAD))) / cos(t * DEG2RAD);
			y2 = _img_h - 0;
			x2 = ((double)(r) - ((y2) * sin(t * DEG2RAD))) / cos(t * DEG2RAD);
		}

		//x1 = r*cos(t*DEG2RAD)+(_img_w/2);
		//y1 = r*sin(t*DEG2RAD)-(_img_h/2);

		cout << "X1: " << x1 << " Y1: " << y1 << endl;//" " << " X2: " << x2 << " Y2: " << y2 << endl;

	}

	char input; 

	cin >> input;

	return 0;
}





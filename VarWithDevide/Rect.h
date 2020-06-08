#ifndef RECT_H_INCLUDED
#define RECT_H_INCLUDED
#pragma once

#include <cmath>
#include <vector>
#include <iostream>

#include "Location.h"

class Rect
{
public:
	 Rect();
    Rect(Location leftDown, Location leftUp, Location rightDown, Location rightUp);

	void addLocation(Location location);
	bool checkSituation(Location location);
	void restrucher(Location location);
	//double distance(double A1, double B1, double A2, double B2);
	void devideRoot();

	Location leftUp;
	Location leftDown;
	Location rightUp;
	Location rightDown;
	vector<Location> locations;
	vector<Rect> children;



	//void setHeight(double height);
	//void setWidth(double width);

	//double latitude;
	//double longitude;
};



#endif // RECT_H_INCLUDED

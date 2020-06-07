#pragma once

#include <cmath>
#include <vector>

#include "Location.h"

class Rect
{
public:
	 Rect();
    Rect(Location leftDown, Location leftUp, Location rightDown, Location rightUp);

	void addLocation(Location location);
	bool checkSituation(Location location);
	void restrucher(Location location);

	Location leftUp;
	Location leftDown;
	Location rightUp;
	Location rightDown;
	vector<Location> locations;


	//void setHeight(double height);
	//void setWidth(double width);

	//double latitude;
	//double longitude;
};

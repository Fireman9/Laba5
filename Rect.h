#pragma once

#include <cmath>
#include <vector>

#include "Location.h"

class Rect
{
public:
	Rect(Location&location1, Location&location2, Location&location3, Location&location4);
	double getLatitude();
	double getLongitude();
	//double getHeight();
	//double getWidth();
	void setLatitude(double latitude);
	void setLongitude(double longitude);
	void addLocation(Location location);
	void checkSituation(Location location);
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

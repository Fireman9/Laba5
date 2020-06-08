#pragma once

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Location.h"

class Rect
{
public:
	Rect(Location leftDown, Location leftUp, Location rightDown, Location rightUp);

	void addLocation(Location location);
	bool checkSituation(Location location);
	void restrucher(Location location);
	double distance(double& A1, double& B1, double& A2, double& B2);
	void devideRoot();

	Location leftUp;
	Location leftDown;
	Location rightUp;
	Location rightDown;
	vector<Location> locations;
	vector<Rect> children;
};
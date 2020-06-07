#pragma once

#include <fstream>
#include <iostream>
#include <cmath>

#include "Node.h"

class RTree
{
public:
	RTree();
	void readFile(std::string fileName);
	double distance(double A1, double B1, double A2, double B2);
	bool checkSituated(double A, double B, Rect rect);

private:
	Node* root;
};

#pragma once

#include <fstream>
#include <iostream>
#include <cmath>

//#include "Node.h"
#include "Location.h"
#include "Rect.h"

using namespace std;

class RTree
{
public:
	RTree();
	void readFile(std::string fileName);
	Rect* getRoot();

private:
	Rect* root;
};
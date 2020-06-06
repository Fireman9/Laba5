#pragma once

#include <fstream>
#include <iostream>

#include "Node.h"

class RTree
{
public:
	RTree();
	void readFile(std::string fileName);

private:
	Node* root;
};
#pragma once

#include <vector>

#include "Rect.h"
#include "Location.h"

class Node
{
public:
	Node(Rect* rect, Location* location);
	~Node();
	void addChild(Node* child);
	void removeChildren();
	std::vector<Node*> getChildren();

private:
	std::vector<Node*> children;
	Rect* rect;
	Location* location;
};
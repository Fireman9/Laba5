#include "RTree.h"

RTree::RTree()
{
	this->root = nullptr;
}

void RTree::readFile(std::string fileName)
{
	std::ifstream in(fileName);
	if (in.is_open()) {
		std::string latitude, lontitude, type, subtype, name, street;
		while (in.eof()) {
			std::getline(in, latitude, ';');
			std::getline(in, lontitude, ';');
			std::getline(in, type, ';');
			std::getline(in, subtype, ';');
			std::getline(in, name, ';');
			std::getline(in, street, ';');
			this->root->addChild(new Node(new Rect(std::stod(latitude), std::stod(lontitude), 0, 0),
				new Location(std::stod(latitude), std::stod(lontitude), type, subtype, name, street)));
			if (this->root == nullptr) {
				this->root = new Node(new Rect(std::stod(latitude), std::stod(lontitude), 0, 0));
			}
			if (std::stod(latitude) < this->root->rect->getLatitude()) {
				this->root->rect->setLatitude(std::stod(latitude));
				// TODO
			}
			if (std::stod(lontitude) < this->root->rect->getLongitude()) {
				this->root->rect->setLongitude(std::stod(lontitude));
				// TODO
			}
		}
		in.close();
	}
	else {
		std::cout << "File wasn't opened" << std::endl;
	}
}
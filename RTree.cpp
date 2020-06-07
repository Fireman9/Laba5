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


double RTree::distance(double A1, double B1, double A2, double B2){
double result, a1, b1, a2, b2, delta1, delta2;
double radius = 6367444.65;//radius in meters
//latitude and longitude in radians
a1 = (A1*2*acos(0.0))/180;
b1 = (B1*2*acos(0.0))/180;
a2 = (A2*2*acos(0.0))/180;
b2 = (B2*2*acos(0.0))/180;

delta1 = a2 - a1;
delta2 = b2 - b1;

double squereRoot = sqrt(pow(sin(delta1/2), 2)+cos(a2)*cos(a1)*pow(sin(delta2/2), 2));
result = 2*asin(squereRoot)*radius;

return result;
}

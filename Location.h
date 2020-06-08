#pragma once

#include <string>
using namespace std;

class Location
{
public:
	Location(double latitude, double longitude, std::string type, std::string subtype, std::string name, std::string street);
	double latitude;
	double longitude;
	std::string type;
	std::string subtype;
	std::string name;
	std::string street;
};
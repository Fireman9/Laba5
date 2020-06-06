#pragma once

#include <string>

class Location
{
public:
	Location(double latitude, double longitude, std::string type, std::string subtype, std::string name, std::string street);
	double getLatitude();
	double getLongitude();
	std::string getType();
	std::string getSubtype();
	std::string getName();
	std::string getStreet();
	void setLatitude(double latitude);
	void setLongitude(double longitude);
	void setType(std::string type);
	void setSubtype(std::string subtype);
	void setName(std::string name);
	void setStreet(std::string street);

private:
	double latitude;
	double longitude;
	std::string type;
	std::string subtype;
	std::string name;
	std::string street;
};
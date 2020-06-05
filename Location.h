#pragma once

#include <string>

class Location
{
public:
	Location(int latitude, int longtitude, std::string type, std::string subtype, std::string name, std::string street);
	int getLatitude();
	int getLongtitude();
	std::string geyType();
	std::string geySubtype();
	std::string geyName();
	std::string geyStreet();
	void setLatitude(int latitude);
	void setLongtitude(int longtitude);
	void setType(std::string type);
	void setSubtype(std::string subtype);
	void setName(std::string name);
	void setStreet(std::string street);

private:
	int latitude;
	int longtitude;
	std::string type;
	std::string subtype;
	std::string name;
	std::string street;
};
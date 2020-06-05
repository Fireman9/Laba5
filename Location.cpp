#include "Location.h"

Location::Location(int latitude, int longtitude, std::string type, std::string subtype, std::string name, std::string street)
{
	this->latitude = latitude;
	this->longtitude = longtitude;
	this->type = type;
	this->subtype = subtype;
	this->name = name;
	this->street = street;
}

int Location::getLatitude()
{
	return this->latitude;
}

int Location::getLongtitude()
{
	return this->longtitude;
}

std::string Location::geyType()
{
	return this->type;
}

std::string Location::geySubtype()
{
	return this->subtype;
}

std::string Location::geyName()
{
	return this->name;
}

std::string Location::geyStreet()
{
	return this->street;
}

void Location::setLatitude(int latitude)
{
	this->latitude = latitude;
}

void Location::setLongtitude(int longtitude)
{
	this->longtitude = longtitude;
}

void Location::setType(std::string type)
{
	this->type = type;
}

void Location::setSubtype(std::string subtype)
{
	this->subtype = subtype;
}

void Location::setName(std::string name)
{
	this->name = name;
}

void Location::setStreet(std::string street)
{
	this->street = street;
}
#include "Location.h"

Location::Location(double latitude, double longitude, std::string type, std::string subtype, std::string name, std::string street)
{
	this->latitude = latitude;
	this->longitude = longitude;
	this->type = type;
	this->subtype = subtype;
	this->name = name;
	this->street = street;
}

double Location::getLatitude()
{
	return this->latitude;
}

double Location::getLongitude()
{
	return this->longitude;
}

std::string Location::getType()
{
	return this->type;
}

std::string Location::getSubtype()
{
	return this->subtype;
}

std::string Location::getName()
{
	return this->name;
}

std::string Location::getStreet()
{
	return this->street;
}

void Location::setLatitude(double latitude)
{
	this->latitude = latitude;
}

void Location::setLongitude(double longtitude)
{
	this->longitude = longtitude;
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
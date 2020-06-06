#include "Rect.h"

Rect::Rect(double latitude, double longitude, double height, double width)
{
	this->latitude = latitude;
	this->longitude = longitude;
	this->height = height;
	this->width = width;
}

double Rect::getLatitude()
{
	return this->latitude;
}

double Rect::getLongitude()
{
	return this->longitude;
}

double Rect::getHeight()
{
	return this->height;
}

double Rect::getWidth()
{
	return this->width;
}

void Rect::setLatitude(double latitude)
{
	this->latitude = latitude;
}

void Rect::setLongitude(double longitude)
{
	this->longitude = longitude;
}

void Rect::setHeight(double height)
{
	this->height = height;
}

void Rect::setWidth(double width)
{
	this->width = width;
}

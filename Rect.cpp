#include "Rect.h"

Rect::Rect(int latitude, int longtitude, int height, int width)
{
	this->latitude = latitude;
	this->longtitude = longtitude;
	this->height = height;
	this->width = width;
}

int Rect::getLatitude()
{
	return this->latitude;
}

int Rect::getLongtitude()
{
	return this->longtitude;
}

int Rect::getHeight()
{
	return this->height;
}

int Rect::getWidth()
{
	return this->width;
}

void Rect::setLatitude(int latitude)
{
	this->latitude = latitude;
}

void Rect::setLongtitude(int longtitude)
{
	this->longtitude = longtitude;
}

void Rect::setHeight(int height)
{
	this->height = height;
}

void Rect::setWidth(int width)
{
	this->width = width;
}

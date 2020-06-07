#include "Rect.h"

Rect::Rect(Location&leftDown, Location&leftUp, Location&rightDown, Location&rightUp)
{
       this->leftDown = leftDown;
       this->leftUp = leftUp;
       this->rightDown = rightDown;
       this->rigtUp = rightUp;
}

void Rect::restrucher(Location location){
double up = min(this->leftUp.longitude, location.longitude);
double down = max(this->leftDown.longitude, location.longitude);
double left = min(this->leftDown.latitude, location.latitude);
double right = max(this->rightDown.latitude, location.latitude);
this->leftUp.longitude = up;
this->rightUp.longitude = up;
this->leftDown.longitude  = down;
this->rightDown.longitude = down;
this->leftDown.latitude = left;
this->leftUp.latitude = left;
this->rightDown.latitude = right;
this->rightUp.latitude = right;
}

void Rect::checkSituation(Location location){
if(this->leftUp.latitude>=location.latitude&&this->leftUp.longitude>=location.longitude
   &&this->leftDown.longitude<=location.longitude&&this->rightUp.latitude<=location.latitude){
       return true;
   }else{
   return false;
   }
}

void Rect::addLocation(Location location){
if(!checkSituation(location)){
       restrucher();
}
std::locations.push_back(location);
}

double Rect::getLatitude()
{
	return this->latitude;
}

double Rect::getLongitude()
{
	return this->longitude;
}

/*double Rect::getHeight()
{
	return this->height;
}*/

/*double Rect::getWidth()
{
	return this->width;
}*/

void Rect::setLatitude(double latitude)
{
	this->latitude = latitude;
}

void Rect::setLongitude(double longitude)
{
	this->longitude = longitude;
}

/*void Rect::setHeight(double height)
{
	this->height = height;
}

void Rect::setWidth(double width)
{
	this->width = width;
}*/

#pragma once

class Rect 
{
public:
	Rect(double latitude, double longitude, double height, double width);
	double getLatitude();
	double getLongitude();
	double getHeight();
	double getWidth();
	void setLatitude(double latitude);
	void setLongitude(double longitude);
	void setHeight(double height);
	void setWidth(double width);

private:
	double latitude;
	double longitude;
	double height;
	double width;
};
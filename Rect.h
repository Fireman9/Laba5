#pragma once
class Rect 
{
public:
	Rect(int latitude, int longtitude, int height, int width);
	int getLatitude();
	int getLongtitude();
	int getHeight();
	int getWidth();
	void setLatitude(int latitude);
	void setLongtitude(int longtitude);
	void setHeight(int height);
	void setWidth(int width);

private:
	int latitude;
	int longtitude;
	int height;
	int width;
};
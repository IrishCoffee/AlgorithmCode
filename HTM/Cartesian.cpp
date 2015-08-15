#include "Cartesian.h"

Cartesian::Cartesian()
{
	x = 0;
	y = 0;
	z = 0;
}

Cartesian::Cartesian(double ra,double dec)
{
	x = cos(radians(dec)) * cos(radians(ra));
	y = cos(radians(dec)) * sin(radians(ra));
	z = sin(radians(dec));
}

Cartesian::Cartesian(double x,double y,double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Cartesian::radians(double degree)
{
	return degree * M_PI / 180.0;
}

void Cartesian::SetMiddlePoint(Cartesian v1, Cartesian v2)
{
	double modules = sqrt((v1.x + v2.x) * (v1.x + v2.x) + (v1.y + v2.y) * (v1.y + v2.y) + (v1.z + v2.z) * (v1.z + v2.z));
	this->x = (v1.x + v2.x) / modules;
	this->y = (v1.y + v2.y) / modules;
	this->z = (v1.z + v2.z) / modules;
}

void Cartesian::Set(Cartesian newC)
{
	this->x = newC.x;
	this->y = newC.y;
	this->z = newC.z;
	return;
}

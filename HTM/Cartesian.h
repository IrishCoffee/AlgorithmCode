#ifndef CARTESIAN_H
#define CARTESIAN_H

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Cartesian
{
	public:
		double x;
		double y;
		double z;
		Cartesian();
		Cartesian(double ra,double dec);
		Cartesian(double x,double y,double z);
		double radians(double degree);
		void Set(Cartesian newC);
		void SetMiddlePoint(Cartesian v1, Cartesian v2);
};
#endif

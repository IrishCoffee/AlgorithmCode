#ifndef TRIXEL_H
#define TRIXEL_H

#include "Cartesian.h"
#include "Constants.h"

class Trixel
{
	public:
		Trixel();
		long long CartesianToHid(Cartesian c, int depth);
	private:
		Cartesian startVertices[8];
		int startTriangleVertices[8][3];
		double TripleProduct(Cartesian v1, Cartesian v2, Cartesian v3);
		bool Contains(Cartesian p, Cartesian v0, Cartesian v1, Cartesian v2);
		long long startPane(Cartesian &v0, Cartesian &v1, Cartesian &v2, double cx, double cy, double cz);
		void init_startVertices();
};
#endif

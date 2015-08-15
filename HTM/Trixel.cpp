#include "Trixel.h"

void Trixel::init_startVertices()
{
	//V0
	startVertices[0].x = 0.0;
	startVertices[0].y = 0.0;
	startVertices[0].z = 1.0;
	//V1
	startVertices[1].x = 1.0;
	startVertices[1].y = 0.0;
	startVertices[1].z = 0.0;
	//V2
	startVertices[2].x = 0.0;
	startVertices[2].y = 1.0;
	startVertices[2].z = 0.0;
	//V3
	startVertices[3].x = -1.0;
	startVertices[3].y = 0.0;
	startVertices[3].z = 0.0;
	//V4
	startVertices[4].x = 0.0;
	startVertices[4].y = -1.0;
	startVertices[4].z = 0.0;
	//V5
	startVertices[5].x = 0.0;
	startVertices[5].y = 0.0;
	startVertices[5].z = -1.0;

	int startTriangleVertices_tmp[8][3] = {{1,5,2},{2,5,3},{3,5,4},{4,5,1},{1,0,4},{4,0,3},{3,0,2},{2,0,1}};
	memcpy(startTriangleVertices,startTriangleVertices_tmp,sizeof(startTriangleVertices_tmp));
	return;
}

Trixel::Trixel()
{
	init_startVertices();
}

long long Trixel::startPane(Cartesian &v0, Cartesian &v1, Cartesian &v2, double cx, double cy, double cz)
{
	long long baseID = 0;
	if(cx > 0 && cy >= 0)
		baseID = (cz >= 0) ? N3 : S0;
	else if(cx <= 0 && cy > 0)
		baseID = (cz >= 0) ? N2 : S1;
	else if(cx < 0 && cy <= 0)
		baseID = (cz >= 0) ? N1 : S2;
	else if(cx >= 0 && cy < 0)
		baseID = (cz >= 0) ? N0 : S3;
	else
		baseID = (cz >= 0) ? N3 : S0;

	int tmp_base = baseID - 8;
	v0 = startVertices[startTriangleVertices[tmp_base][0]];
	v1 = startVertices[startTriangleVertices[tmp_base][1]];
	v2 = startVertices[startTriangleVertices[tmp_base][2]];

	return baseID;

}

double Trixel::TripleProduct(Cartesian p, Cartesian v1, Cartesian v2)
{
	return p.x * v1.y * v2.z + p.y * v1.z * v2.x + p.z * v1.x * v2.y - p.z * v1.y * v2.x - p.y * v1.x * v2.z - p.x * v1.z * v2.y;
}

bool Trixel::Contains(Cartesian p, Cartesian v1, Cartesian v2, Cartesian v3)
{
	/* if (v1 X v2) * P < epsilon then false
	 * same for v2 X v3 and V3 X v1
	 * else return true
	 */
	if(TripleProduct(p,v1,v2) < -DblTolerance)
		return false;
	if(TripleProduct(p,v2,v3) < -DblTolerance)
		return false;
	if(TripleProduct(p,v3,v1) < -DblTolerance)
		return false;
	return true;
}


long long Trixel::CartesianToHid(Cartesian c, int depth)
{
	Cartesian v0,v1,v2;
	Cartesian w0,w1,w2;
	long long topID = startPane(v0,v1,v2,c.x,c.y,c.z);
	long long hid = topID;
	while(depth-- > 0)
	{
		hid <<= 2;
		w0.SetMiddlePoint(v1,v2);
		w1.SetMiddlePoint(v0,v2);
		w2.SetMiddlePoint(v0,v1);
		if(Contains(c,v0,w2,w1))
		{
			hid |= 0;
			v1.Set(w2);
			v2.Set(w1);
		}
		else if(Contains(c,v1,w0,w2))
		{
			hid |= 1;
			v0.Set(v1);
			v1.Set(w0);
			v2.Set(w2);
		}
		else if(Contains(c,v2,w1,w0))
		{
			hid |= 2;
			v0.Set(v2);
			v1.Set(w1);
			v2.Set(w0);
		}
		else
		{
			hid |= 3;
			v0.Set(w0);
			v1.Set(w1);
			v2.Set(w2);
		}
	}

	return hid;
}



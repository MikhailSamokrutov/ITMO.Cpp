#pragma once
#include "Lab10_D.h"

using namespace std;

class Triangle
{
public:
	// ����������
	Triangle(Dot& d1, Dot& d2, Dot& d3) /*: dt1(&d1), dt2(&d2), dt3(&d3)*/ 
	{
		dt1 = new Dot(d1);
		dt2 = new Dot(d2);
		dt3 = new Dot(d3);
	};

	// ���������
	Triangle(Dot* d1 = nullptr, Dot* d2 = nullptr, Dot* d3 = nullptr) :
		dt1(d1), dt2(d2), dt3(d3) {};

	void printTriangle();

private:
	Dot *dt1, *dt2, *dt3;

	double getTriangleArea() const;
};
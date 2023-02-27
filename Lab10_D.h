using namespace std;

#pragma once

class Dot
{
public:
	Dot();
	Dot(double x, double y);
	double distanceTo(Dot point);

private:
	double x;
	double y;
};

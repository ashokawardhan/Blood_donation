#include <iostream>
#include <cstdio>
#include <cmath>

#define R double 

using namespace std;

namespace {
	double x;
	double y;
	double z;
	double theta;
	double h;
	double phi;
	double r;
}

void XY_to_P(const R &x, const R &y, const R &z, R &r, R &theta, R &phi)
{
	r = (double) sqrt(x*x + y*y + z*z);
	theta = acos(z/r);
	phi = atan(y/x);
}

void P_to_XY(const R &r, const R &theta, const R &phi, R &x, R &y, R &z)
{
	x = r*sin(theta)*cos(phi);
	y = r*sin(theta)*sin(phi);
	z = r*cos(theta);
}

void XY_to_C(const R &x, const R &y, const R &z, R &r, R &theta, R &h)
{
	r = (double) sqrt(x*x + y*y);
	h = z;
	theta = acos(z/r);
}

void C_to_XY(R &r, R &theta, R &h, R &x, R &y, R &z)
{
	h = z;
	x = r*cos(theta);
	y = r*sin(theta);
}

void P_to_C(R &r0, R &theta0, R &phi0, R &r, R &theta, R &h)
{
	P_to_XY(r0, theta0, phi0, x, y, z);
	XY_to_C(x, y, z, r, theta, h);
}

void C_to_P(R &r, R &theta, R &h, R &r0, R &theta0, R &phi0)
{
	C_to_XY(r, theta, h, x, y, z);
	XY_to_P(x, y, z, r0, theta0, phi0);
}

void printXY()
{
	cout << "CARTESIAN" << endl;
	cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

void printC()
{
	cout << "CYLINDRICAL" << endl;
	cout << "R = " << r << " THETA = " << theta << " H = " << h << endl;
}

void printP()
{
	cout << "POLAR" << endl;
	cout << "R = " << r << " THETA = " << theta << " PHI = " << phi<< endl;
}

int main()
{
	x = y = z = 1;
	XY_to_P(x, y, z, r, theta, phi);
	printP();
	P_to_XY(r, theta, phi, x, y, z);
	printXY();
	XY_to_C(x, y, z, r, theta, h);
	printC();
	C_to_XY(r, theta, h, x, y, z);
	printXY();

	return 0;
}

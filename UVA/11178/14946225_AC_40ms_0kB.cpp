#pragma once
#include<iostream>
#include<cmath>
using namespace std;
const double eps = 1e-10;
typedef struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}
	
}Vector;
Point ReadPoint()
{
	Point temp;
	cin >> temp.x >> temp.y;
	return temp;
}
Vector operator+(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator-(Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator-(Vector a) { return Vector(-a.x, -a.y); }
Vector operator*(Vector a, double b) { return Vector(a.x*b, a.y*b); }
Vector operator/(Vector a, double b) { return Vector(a.x / b, a.y / b); }
int dcmp(double a)
{
	if (fabs(a) < eps)	return 0;
	else return a > 0 ? 1 : -1;
}
bool operator<(const Vector& a,const Vector& b) { return a.x < b.x || (a.x == b.x&&a.y < b.y); }
bool operator==(const Vector& a,const Vector& b) { return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0; }
double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
double Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
double Length(Vector a) { return sqrt(Dot(a, a)); }
double Angle(Vector a, Vector b) { return acos(Dot(a, b) / Length(a) / Length(b)); }
Vector Rotate(Vector a, double rad) { return Vector(a.x*cos(rad) - a.y*sin(rad), a.x*sin(rad) + a.y*cos(rad)); }
double GetArea(Vector a, Vector b) { return fabs(Cross(a, b)); }
double GetArea(Point a, Point b, Point c) { return GetArea(a - b, a - c); }
double PolygonArea(Point *P, int n)
{
	double area = 0;
	for (int i = 1; i < n - 1; i++)
		area += Cross(P[i] - P[0], P[i + 1] - P[0]);
	return area / 2;
}
Point GetLineIntersection_Vector(Point A, Vector a, Point B, Vector b)
{
	Vector u = A - B;
	return A + a * Cross(b, u) / Cross(a, b);
}//TRUE
Point GetLineIntersection_Point(Point A, Point B, Point C, Point D)
{
	Vector a = A - B;
	Vector b = C - D;
	return GetLineIntersection_Vector(A, a, C, b);
}
bool SegmentProperIntersection(Point A, Point B, Point C, Point D)
{
	double a = Cross(B - A, C - A), b = Cross(B - A, D - A);
	double c = Cross(D - C, A - C), d = Cross(D - C, B - C);
	return dcmp(a)*dcmp(b) < 0 && dcmp(c)*dcmp(d) < 0;
}
double PointToLineDistance(Point A, Point B, Point C) { return fabs(Cross(C - B, A - B)) / Length(C - B); }
double PointToSegmentDistance(Point A, Point B, Point C)
{
	if (B == C)return Length(A - B);
	Vector v1 = A - B, v2 = C - B, v3 = A - C;
	if (dcmp(Dot(v1, v2) < 0))	return Length(v1);
	else if (dcmp(Dot(v2, v3) > 0)) return Length(v3);
	else return PointToLineDistance(A, B, C);
}
Point PointToLineProjection(Point A, Point B, Point C) { return B + (C - B) / Length(C - B)*Dot(C - B, A - B) / Length(C - B); }
bool PointOnSegment(Point A, Point B, Point C)
{
	Vector v1 = A - B, v2 = A - C, v3 = C - B;
	return dcmp(Cross(v1,v2))==0&&dcmp(Dot(v1, v3))< 0;
}
Point A, B, C;
Point D, E, F;
Point GetD(const Point a,const Point b,const Point c)
{
	Vector v1 = a - b, v2 = a - c, v3 = c - b;
	Vector c1, c2;
	c1 = Rotate(v3,Angle(v3, v1) / 3);
	c2 = Rotate(-v3, -Angle(-v3, v2) / 3);
	return Point(GetLineIntersection_Vector(b, c1, c, c2));
}
int main()
{
	int kase;
	cin >> kase;
	while (kase--)
	{
		A = ReadPoint();
		B = ReadPoint();
		C = ReadPoint();
		D = GetD(A, B, C);
		E = GetD(B, C, A);
		F = GetD(C, A, B);
		printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", D.x, D.y, E.x, E.y, F.x, F.y);
	}
	return 0;
}
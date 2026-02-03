#pragma once

#include <string>

class Vector3D {
	double X;
	double Y;
	double Z;
public:
	Vector3D(double x = 0, double y = 0, double z = 0);

	Vector3D operator-(const Vector3D& other)const;

	Vector3D operator+(const Vector3D& other)const;

	Vector3D operator*(double other)const;

	Vector3D CrossProduct(const Vector3D& other) const;

	double DotProduct(const Vector3D& other) const;

	double getX()const;

	double getY() const;

	double getZ()const;
};

class Segment3D {
	Vector3D start;
	Vector3D end;
public:
	Segment3D(const Vector3D& s, const Vector3D& e);

	Vector3D getStart() const;

	Vector3D getEnd() const;
};

bool Intersect(const Segment3D& segment1, const Segment3D& segment2, Vector3D& intersection_point);

Vector3D getPoint(const std::string& text);


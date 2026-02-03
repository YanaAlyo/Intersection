#include "Geometry.h"
#include <iostream>
#include <cmath>
#include <limits>

	Vector3D::Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

	Vector3D Vector3D::operator-(const Vector3D& other)const {
		return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
	}

	Vector3D Vector3D::operator+(const Vector3D& other)const {
		return Vector3D(X + other.X, Y + other.Y, Z + other.Z);
	}

	Vector3D Vector3D::operator*(double other)const {
		return Vector3D(X * other, Y * other, Z * other);
	}

	Vector3D Vector3D::CrossProduct(const Vector3D& other) const {
		return Vector3D(Y * other.Z - other.Y * Z, other.X * Z - X * other.Z, X * other.Y - other.X * Y);
	}

	double Vector3D::DotProduct(const Vector3D& other) const {
		return X * other.X + Y * other.Y + Z * other.Z;
	}

	double Vector3D::getX()const {
		return X;
	}

	double Vector3D::getY() const {
		return Y;
	}

	double Vector3D::getZ()const {
		return Z;
	}



	Segment3D::Segment3D(const Vector3D& s, const Vector3D& e) : start(s), end(e) {}

	Vector3D Segment3D::getStart() const {
		return start;
	}

	Vector3D Segment3D::getEnd() const {
		return end;
	}


 bool Intersect(const Segment3D& segment1, const Segment3D& segment2, Vector3D& intersection_point) {
	const Vector3D r = segment2.getStart() - segment1.getStart();
	const Vector3D v1 = segment1.getEnd() - segment1.getStart();
	const Vector3D v2 = segment2.getEnd() - segment2.getStart();

	const Vector3D v3 = v1.CrossProduct(v2);
	double q = v3.DotProduct(v3);

	const double eps = 0.0000001;

	if (std::abs(v3.DotProduct(r)) < eps && q > eps) {//лежат в одной пл-ти, не паралл, не наклад-ся друг на друга.
		double t = r.CrossProduct(v2).DotProduct(v3) / (q);
		double u = r.CrossProduct(v1).DotProduct(v3) / (q);

		if (t <= 1 && t >= 0 && u <= 1 && u >= 0) {
			intersection_point = segment1.getStart() + v1 * t;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

	

}

Vector3D getPoint(const std::string& text) {
	double x, y, z;

	while (true) {
		std::cout << "Введите " << text << " отрезка: ";
		if (std::cin >> x >> y >> z)
			return Vector3D(x, y, z);
		else {
			std::cout << "Ошибка ввода! Используйте только числа и пробелы (например: 1 2.3 0)\n";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}
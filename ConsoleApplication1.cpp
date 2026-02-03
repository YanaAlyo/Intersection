#include "Geometry.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	
	Vector3D v1_start = getPoint("начало 1-го");
	Vector3D v1_end = getPoint("конец 1-го");

	Vector3D v2_start = getPoint("начало 2-го");
	Vector3D v2_end = getPoint("конец 2-го");

	Segment3D segment1(v1_start, v1_end);
	Segment3D segment2(v2_start, v2_end);

	Vector3D intersection_point;
	if (Intersect(segment1, segment2, intersection_point)) {
		std::cout << "\nТочка пересечения отрезков: " << intersection_point.getX() << " "
			<< intersection_point.getY() << " "
			<< intersection_point.getZ();
	}
	else
		std::cout << "\nОтрезки не пересекаются.";
}
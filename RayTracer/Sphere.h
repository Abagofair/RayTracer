#pragma once

#include "Vector3.h"

class Sphere {
private:
	Vector3<int> _centerPosition;
	float _radius;

public:
	Sphere(int x, int y, int z, float radius);

	float GetRadius() const;
	const Vector3<int>& GetCenterPosition() const;
};
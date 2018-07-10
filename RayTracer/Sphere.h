#pragma once

#include "Vector3.h"

class Sphere {
private:
	Vector3<float> _centerPosition;
	float _radius;

public:
	Sphere(float x, float y, float z, float radius);

	float GetRadius() const;
	const Vector3<float>& GetCenterPosition() const;

	float CalculateIntersectDiscriminant(const Vector3<float>& origin, const Vector3<float>& direction);
};
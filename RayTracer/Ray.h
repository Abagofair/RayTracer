#pragma once

#include "Vector3.h"

class Ray {
private:
	Vector3<float> _origin;
	Vector3<float> _direction;

public:
	Ray();
	Ray(const Vector3<float>& origin, const Vector3<float>& direction);

	const Vector3<float>& GetOrigin() const;
	const Vector3<float>& GetDirection() const;
};
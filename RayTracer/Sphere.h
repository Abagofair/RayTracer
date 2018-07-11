#pragma once

class Ray;

#include "Surface.h"
#include "Vector3.h"
#include <math.h>

class Sphere : public Surface {
private:
	float _radius;

public:
	Sphere(float x, float y, float z, float radius);

	virtual bool Hit(const Ray& ray, Vector2<float>& hitResult);

	float GetRadius() const;

	float CalculateIntersectDiscriminant(const Vector3<float>& origin, const Vector3<float>& direction);
	float CalculateFirstIntersectPoint(const Vector3<float>& origin, const Vector3<float>& direction);
};
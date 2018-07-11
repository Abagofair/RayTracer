#pragma once

#include "Ray.h"
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
};
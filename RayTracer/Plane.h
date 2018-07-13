#pragma once

#include "Surface.h"

class Plane : public Surface {
private:
	Vector3<float> _normal;
public:
	Plane(float x, float y, float z, Vector3<float> normal, RGB color, float phongExponent);
	virtual bool Hit(const Ray& ray, Vector2<float>& hitResult);
	const Vector3<float>& GetNormal() const;
};
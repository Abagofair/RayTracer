#include "stdafx.h"
#include "Sphere.h"

Sphere::Sphere(int x, int y, int z, float radius)
{
	_centerPosition = Vector3<int>();
	_centerPosition.SetX(x); _centerPosition.SetY(y); _centerPosition.SetZ(z);
	_radius = radius;
}

float Sphere::GetRadius() const
{
	return _radius;
}

const Vector3<int>& Sphere::GetCenterPosition() const
{
	return _centerPosition;
}

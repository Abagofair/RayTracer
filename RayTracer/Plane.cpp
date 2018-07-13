#include "Plane.h"

Plane::Plane(float x, float y, float z, Vector3<float> normal, RGB color, float phongExponent)
{
	SetLocation(Vector3<float>(x, y, z));
	SetMaterial(Material(color, phongExponent));
	_normal = normal;
}

bool Plane::Hit(const Ray & ray, Vector2<float>& hitResult)
{
	float dot = ray.GetDirection().DotProduct(_normal);
	bool hit = false;
	if (dot != 0)
	{
		float numerator = (GetLocation() - ray.GetOrigin()).DotProduct(_normal);
		float d = numerator / dot;
		hitResult.SetX(d);
		hit = true;
	}
	return hit;
}

const Vector3<float>& Plane::GetNormal() const
{
	return _normal;
}

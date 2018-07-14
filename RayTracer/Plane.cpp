#include "Plane.h"
#include <stdio.h>
Plane::Plane(float x, float y, float z, Vector3<float> normal, RGB color, float phongExponent)
{
	SetLocation(Vector3<float>(x, y, z));
	SetMaterial(Material(color, phongExponent));
	_normal = normal;
}

bool Plane::Hit(const Ray & ray, Vector2<float>& hitResult)
{
	Vector3<float> rayDir = ray.GetDirection();
	float denominator = _normal.DotProduct(rayDir.Normalize());
	bool hit = false;
	float t = -1.f;
	if (denominator > 1e-6)
	{
		Vector3<float> p = GetLocation() - ray.GetOrigin();
		float numerator = _normal.DotProduct(p.Normalize());
		t = numerator / denominator;

		if (t >= 0.f)
		{
			hit = true;
			hitResult.SetX(t);
		}
	}
	return hit;
}

const Vector3<float>& Plane::GetNormal() const
{
	return _normal;
}

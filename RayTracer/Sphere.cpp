//#include "stdafx.h"
#include "Sphere.h"

Sphere::Sphere(float x, float y, float z, float radius, RGB color)
{
	SetLocation(Vector3<float>(x, y, z));
	_radius = radius;
	SetMaterial(Material(color));
}

bool Sphere::Hit(const Ray& ray, Vector2<float>& hitResult)
{
	bool hit = false;
	//calculate discriminant
	const Vector3<float>& origin = ray.GetOrigin();
	const Vector3<float>& dir = ray.GetDirection();
	Vector3<float> viewCenter = origin - GetLocation();
	float discriminant = 
		dir.DotProduct(viewCenter) * dir.DotProduct(viewCenter) -
		dir.DotProduct(dir) * (viewCenter.DotProduct(viewCenter) - (_radius * _radius));
	//calculate intersection points if discriminant >= 0 (there is at least 1 intersection with the sphere)
	if (discriminant >= 0)
	{
		hit = true;
		float numerator = -1 * dir.DotProduct(viewCenter) + sqrtf(discriminant);
		float denominator = dir.DotProduct(dir);
		float hitOffset = numerator / denominator;
		hitResult.SetX(hitOffset);

		if (discriminant >= 1)
		{
			numerator = -1 * dir.DotProduct(viewCenter) - sqrtf(discriminant);
			hitOffset = numerator / denominator;
			hitResult.SetY(hitOffset);
		}
	}

	return hit;
}

float Sphere::GetRadius() const
{
	return _radius;
}

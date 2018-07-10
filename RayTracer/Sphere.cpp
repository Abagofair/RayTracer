//#include "stdafx.h"
#include "Sphere.h"

Sphere::Sphere(float x, float y, float z, float radius)
{
	_centerPosition = Vector3<float>();
	_centerPosition.SetX(x); _centerPosition.SetY(y); _centerPosition.SetZ(z);
	_radius = radius;
}

float Sphere::GetRadius() const
{
	return _radius;
}

const Vector3<float>& Sphere::GetCenterPosition() const
{
	return _centerPosition;
}

float Sphere::CalculateIntersectDiscriminant(const Vector3<float>& origin, const Vector3<float>& direction)
{
	Vector3<float> viewCenter = origin - _centerPosition;
	float term1 = direction.DotProduct(viewCenter) * direction.DotProduct(viewCenter);
	float term2 = direction.DotProduct(direction);
	float term3 = viewCenter.DotProduct(viewCenter);
	float discriminant = term1 - term2 * (term3 - (_radius * _radius));
	return discriminant;
}

float Sphere::CalculateFirstIntersectPoint(const Vector3<float>& origin, const Vector3<float>& direction)
{
	float discriminant = CalculateIntersectDiscriminant(origin, direction);
	Vector3<float> viewCenter = origin - _centerPosition;
	float upper = -1 * direction.DotProduct(viewCenter) + sqrtf(discriminant);
	float lower = direction.DotProduct(direction);
	return upper / lower;
}

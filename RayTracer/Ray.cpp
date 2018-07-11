#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(const Vector3<float>& origin, const Vector3<float>& direction)
{
	_origin.SetX(origin.GetX()); _origin.SetY(origin.GetY()); _origin.SetZ(origin.GetZ());
	_direction.SetX(direction.GetX()); _direction.SetY(direction.GetY()); _direction.SetZ(direction.GetZ());
}

const Vector3<float>& Ray::GetOrigin() const
{
	return _origin;
}

const Vector3<float>& Ray::GetDirection() const
{
	return _direction;
}

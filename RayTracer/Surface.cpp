#include "Surface.h"

bool Surface::Hit(const Ray & ray, Vector2<float>& hitResult)
{
	return false;
}

const Vector3<float>& Surface::GetLocation() const
{
	return _location;
}

void Surface::SetLocation(const Vector3<float>& vec)
{
	_location.SetX(vec.GetX()); _location.SetY(vec.GetY()); _location.SetZ(vec.GetZ());
}

void Surface::SetLocation(float x, float y, float z)
{
	_location.SetX(x); _location.SetY(y); _location.SetZ(z);
}

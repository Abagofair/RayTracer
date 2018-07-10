#include "PointLight.h"

PointLight::PointLight()
{
}

PointLight::PointLight(float x, float y, float z, float intensity)
{
	_position = Vector3<float>(x, y, z);
	_intensity = intensity;
}

const Vector3<float>& PointLight::GetPosition() const
{
	return _position;
}

float PointLight::GetIntensity()
{
	return _intensity;
}

#pragma once

#include "Vector3.h"

class PointLight {
private:
	Vector3<float> _position;
	float _intensity;

public:
	PointLight();
	PointLight(float x, float y, float z, float intensity);

	const Vector3<float>& GetPosition() const;
	float GetIntensity();
};
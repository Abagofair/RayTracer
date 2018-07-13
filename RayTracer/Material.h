#pragma once

#include "RGB.h"

class Material {
private:
	RGB _color;
	float _phongExponent;

public:
	Material();
	Material(RGB rgb, float phongExponent);
	const RGB& GetColor() const;
	void SetColor(RGB rgb);
	float GetPhongExponent();
	void SetPhongExponent(float phongExponent);
};
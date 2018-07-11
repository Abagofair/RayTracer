#pragma once

#include "RGB.h"

class Material {
private:
	RGB _color;

public:
	Material();
	Material(RGB rgb);
	const RGB& GetColor() const;
	void SetColor(RGB rgb);
};
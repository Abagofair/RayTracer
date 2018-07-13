#include "Material.h"

Material::Material()
{
}

Material::Material(RGB rgb, float phongExponent)
{
	_color.SetRed(rgb.GetRed()); _color.SetGreen(rgb.GetGreen()); _color.SetBlue(rgb.GetBlue());
	_phongExponent = phongExponent;
}

const RGB & Material::GetColor() const
{
	return _color;
}

void Material::SetColor(RGB rgb)
{
	_color.SetRed(rgb.GetRed()); _color.SetGreen(rgb.GetGreen()); _color.SetBlue(rgb.GetBlue());
}

float Material::GetPhongExponent()
{
	return _phongExponent;
}

void Material::SetPhongExponent(float phongExponent)
{
	_phongExponent = phongExponent;
}

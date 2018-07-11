#include "Material.h"

Material::Material()
{
}

Material::Material(RGB rgb)
{
	_color.SetRed(rgb.GetRed()); _color.SetGreen(rgb.GetGreen()); _color.SetBlue(rgb.GetBlue());
}

const RGB & Material::GetColor() const
{
	return _color;
}

void Material::SetColor(RGB rgb)
{
	_color.SetRed(rgb.GetRed()); _color.SetGreen(rgb.GetGreen()); _color.SetBlue(rgb.GetBlue());
}

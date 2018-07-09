#include "stdafx.h"
#include "RGB.h"

RGB::RGB(char r, char g, char b) : _r(r), _g(g), _b(b)
{
}

char RGB::GetRed()
{
	return _r;
}

char RGB::GetGreen()
{
	return _g;
}

char RGB::GetBlue()
{
	return _b;
}

void RGB::SetRed(char r)
{
	_r = r;
}

void RGB::SetGreen(char g)
{
	_g = g;
}

void RGB::SetBlue(char b)
{
	_b = b;
}

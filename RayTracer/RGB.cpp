//#include "stdafx.h"
#include "RGB.h"

RGB::RGB() {}

RGB::RGB(int r, int g, int b) : _r(r), _g(g), _b(b)
{
}

int RGB::GetRed()
{
	return _r;
}

int RGB::GetGreen()
{
	return _g;
}

int RGB::GetBlue()
{
	return _b;
}

void RGB::SetRed(int r)
{
	_r = r;
}

void RGB::SetGreen(int g)
{
	_g = g;
}

void RGB::SetBlue(int b)
{
	_b = b;
}

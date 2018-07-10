#pragma once

template <class T>
class Vector2 {
private:
	T _x;
	T _y;

public:
	Vector2() {};
	Vector2(T x, T y) : _x(x), _y(y) {}

	T GetX() const
	{
		return _x;
	}

	T GetY() const
	{
		return _y;
	}

	void SetX(T x)
	{
		_x = x;
	}

	void SetY(T y)
	{
		_y = y;
	}
};
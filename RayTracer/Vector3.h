#pragma once

#include <math.h>

template <class T>
class Vector3 {
private:
	T _x;
	T _y;
	T _z;

public:
	Vector3() {};
	Vector3(T x, T y, T z) : _x(x), _y(y), _z(z) {}

	T GetX() const
	{
		return _x;
	}

	T GetY() const
	{
		return _y;
	}

	T GetZ() const
	{
		return _z;
	}

	void SetX(T x)
	{
		_x = x;
	}
	void SetY(T y)
	{
		_y = y;
	}
	void SetZ(T z)
	{
		_z = z;
	}

	float Length()
	{
		return sqrtf((GetX() * GetX()) + (GetY() * GetY()) + (GetZ() * GetZ()));
	}

	Vector3<T> Normalize()
	{
		Vector3<T> v;
		float len = Length();
		if (len > 0)
		{
			v.SetX(GetX() / len);
			v.SetY(GetY() / len);
			v.SetZ(GetZ() / len);
		}
		else
		{
			v.SetX(0.f);
			v.SetY(0.f);
			v.SetZ(0.f);
		}
		return v;
	}

	float DotProduct(const Vector3<T>& vector) const
	{
		return GetX() * vector.GetX() + GetY() * vector.GetY() + GetZ() * vector.GetZ();
	}

	Vector3<T> CrossProduct(const Vector3<T>& vector)
	{
		Vector3<T> v;
		v.SetX(GetY() * vector.GetZ() - GetZ() * vector.GetY());
		v.SetY(GetZ() * vector.GetX() - GetX() * vector.GetZ());
		v.SetZ(GetX() * vector.GetY() - GetY() * vector.GetX());
		return v;
	}

	friend bool operator==(const Vector3<T> &v1, const Vector3<T> &v2)
	{
		return v1.GetX() == v2.GetX() && v1.GetY() == v2.GetY() && v1.GetZ() == v2.GetZ();
	}

	friend Vector3<T> operator+(const Vector3<T> &v1, const Vector3<T> &v2)
	{
		Vector3<T> v;
		v.SetX(v1.GetX() + v2.GetX());
		v.SetY(v1.GetY() + v2.GetY());
		v.SetZ(v1.GetZ() + v2.GetZ());
		return v;
	}

	friend Vector3<T> operator-(const Vector3<T> &v1, const Vector3<T> &v2)
	{
		Vector3<T> v;
		v.SetX(v1.GetX() - v2.GetX());
		v.SetY(v1.GetY() - v2.GetY());
		v.SetZ(v1.GetZ() - v2.GetZ());
		return v;
	}

	friend Vector3<T> operator*(const Vector3<T> &v1, float scalar)
	{
		Vector3<T> v;
		v.SetX(v1.GetX() * scalar);
		v.SetY(v1.GetY() * scalar);
		v.SetZ(v1.GetZ() * scalar);
		return v;
	}

	static Vector3<T> ConstructVector(const Vector3<T> &startPoint, const Vector3<T> &endPoint)
	{
		Vector3<T> v;
		v.SetX(endPoint.GetX() - startPoint.GetX());
		v.SetY(endPoint.GetY() - startPoint.GetY());
		v.SetZ(endPoint.GetZ() - startPoint.GetZ());
		return v;
	}
};

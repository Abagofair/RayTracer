#include "stdafx.h"
#include "Vector3.h"

template <typename T>
Vector3<T>::Vector3()
{
}

template <typename T>
Vector3<T>::Vector3(T x, T y, T z) : _x(x), _y(y), _z(z)
{
}

template <typename T>
T Vector3<T>::GetX()
{
	return _x;
}

template <typename T>
T Vector3<T>::GetY()
{
	return _y;
}

template <typename T>
T Vector3<T>::GetZ()
{
	return _z;
}

template <typename T>
void Vector3<T>::SetX(T x)
{
	_x = x;
}

template <typename T>
void Vector3<T>::SetY(T y)
{
	_y = y;
}

template <typename T>
void Vector3<T>::SetZ(T z)
{
	_z = z;
}

template<class T>
float Vector3<T>::DotProduct(const Vector3<T>& vector)
{
	return this->GetX * vector.GetX() + this->GetY() * vector.GetY() + this->GetZ() * vector.GetZ();
}

template<class T>
Vector3<T> Vector3<T>::CrossProduct(const Vector3<T>& vector)
{
	return Vector3<T>();
}

template <typename T>
bool operator==(const Vector3<T>& v1, const Vector3<T>& v2)
{
	return v1.GetX() == v2.GetX() && v1.GetY() == v2.GetY() && v1.GetZ() && v2.GetZ();
}

template <typename T>
Vector3<T> operator+(const Vector3<T>& v1, const Vector3<T>& v2)
{
	Vector3<T> v;
	v.SetX(v1.GetX() + v2.GetX());
	v.SetY(v1.GetY() + v2.GetY());
	v.SetZ(v1.GetZ() + v2.GetZ());
	return v;
}

template <typename T>
Vector3<T> operator-(const Vector3<T>& v1, const Vector3<T>& v2)
{
	Vector3<T> v;
	v.SetX(v1.GetX() - v2.GetX());
	v.SetY(v1.GetY() - v2.GetY());
	v.SetZ(v1.GetZ() - v2.GetZ());
	return v;
}

template <typename T>
Vector3<T> operator*(const Vector3<T>& v1, float scalar)
{
	Vector3<T> v;
	v.SetX(v1.GetX() * scalar);
	v.SetY(v1.GetY() * scalar);
	v.SetZ(v1.GetZ() * scalar);
	return v;
}

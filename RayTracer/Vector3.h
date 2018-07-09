#pragma once

template <class T>
class Vector3 {
private:
	T _x;
	T _y;
	T _z;

public:
	Vector3();
	Vector3(T x, T y, T z);

	T GetX();
	T GetY();
	T GetZ();

	void SetX(T x);
	void SetY(T y);
	void SetZ(T z);

	float DotProduct(const Vector3<T>&);
	Vector3<T> CrossProduct(const Vector3<T>&);

	friend bool operator==(const Vector3<T> &v1, const Vector3<T> &v2);
	friend Vector3<T> operator+(const Vector3<T> &v1, const Vector3<T> &v2);
	friend Vector3<T> operator-(const Vector3<T> &v1, const Vector3<T> &v2);
	friend Vector3<T> operator*(const Vector3<T> &v1, float scalar);
};

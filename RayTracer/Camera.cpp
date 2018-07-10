//#include "stdafx.h"
#include "Camera.h"

Camera::Camera(const Vector3<float>& pos, int d)
{
	_viewPoint = Vector3<float>();
	_viewPoint.SetX(pos.GetX()); _viewPoint.SetY(pos.GetY()); _viewPoint.SetY(pos.GetY());
	_focalDistance = d;

	//construct orthonormal basis
	//take viewpoint and create new point 5 units behind it in the y direction, then construct first w basis
	Vector3<float> wEndPos(_viewPoint.GetX(), _viewPoint.GetY() - 5.f, _viewPoint.GetZ());
	_w = (wEndPos - _viewPoint).Normalize();
	//same is done for v
	Vector3<float> vEndPos(_viewPoint.GetX(), _viewPoint.GetY(), _viewPoint.GetZ() + 5.f);
	Vector3<float> temp = vEndPos - _viewPoint;
	_v = temp.CrossProduct(_w).Normalize();
	//take cross product of w and v and get u
	_u = _w.CrossProduct(_v).Normalize();
}

Camera::Camera(float x, float y, float z, int d)
{
	_viewPoint = Vector3<float>();
	_viewPoint.SetX(x); _viewPoint.SetY(y); _viewPoint.SetZ(z);
	_focalDistance = d;

	//construct orthonormal basis
	//take viewpoint and create new point 5 units behind it in the y direction, then construct first w basis
	Vector3<float> wEndPos(_viewPoint.GetX(), _viewPoint.GetY() - 5.f, _viewPoint.GetZ());
	_w = (wEndPos - _viewPoint).Normalize();
	//same is done for v
	Vector3<float> vEndPos(_viewPoint.GetX(), _viewPoint.GetY(), _viewPoint.GetZ() + 5.f);
	//Vector3<float> temp = vEndPos - _viewPoint;
	_v = (vEndPos - _viewPoint).Normalize();
	//take cross product of w and v and get u
	_u = _w.CrossProduct(_v).Normalize() * -1;
}

const Vector3<float>& Camera::GetPosition() const
{
	return _viewPoint;
}

void Camera::SetPosition(const Vector3<float>& pos)
{
	_viewPoint.SetX(pos.GetX()); _viewPoint.SetY(pos.GetY()); _viewPoint.SetY(pos.GetY());
}

const Vector3<float>& Camera::GetU() const
{
	return _u;
}

const Vector3<float>& Camera::GetV() const
{
	return _v;
}

const Vector3<float>& Camera::GetW() const
{
	return _w;
}

float Camera::GetFocalDistance()
{
	return _focalDistance;
}

Vector2<float> Camera::ImagePlanePoint(int i, int j, int width, int height)
{
	float r = _u.GetY();
	float t = _v.GetZ();
	float l = -1 * r;
	float b = -1 * t;
	//float u = l + ((r - l)*(i + 0.5) / width);
	//float v = b + ((t - b)*(j + 0.5) / height);
	float u = (-1) + (((1 - (-1))*(i+0.5)) / width);
	float v = (-1) + (((1 - (-1))*(j+0.5)) / height);
	return Vector2<float>(u, v);
}

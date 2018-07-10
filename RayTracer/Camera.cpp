#include "stdafx.h"
#include "Camera.h"

Camera::Camera(const Vector3<int>& pos, int d)
{
	_viewPoint = Vector3<int>();
	_viewPoint.SetX(pos.GetX()); _viewPoint.SetY(pos.GetY()); _viewPoint.SetY(pos.GetY());
	_focalDistance = d;

	//construct orthonormal basis
	
}

Camera::Camera(int x, int y, int z, int d)
{
	_viewPoint = Vector3<int>();
	_viewPoint.SetX(x); _viewPoint.SetY(y); _viewPoint.SetZ(z);
	_focalDistance = d;
}

const Vector3<int>& Camera::GetPosition() const
{
	return _viewPoint;
}

void Camera::SetPosition(const Vector3<int>& pos)
{
	_viewPoint.SetX(pos.GetX()); _viewPoint.SetY(pos.GetY()); _viewPoint.SetY(pos.GetY());
}

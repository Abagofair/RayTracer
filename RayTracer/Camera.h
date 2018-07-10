#pragma once

#include "Vector3.h"

class Camera {
private:
	Vector3<float> _u;
	Vector3<float> _v;
	Vector3<float> _w;
	Vector3<int> _viewPoint;
	int _focalDistance;

public:
	Camera(const Vector3<int> &pos, int d);
	Camera(int x, int y, int z, int d);

	const Vector3<int>& GetPosition() const;
	void SetPosition(const Vector3<int> &pos);
};
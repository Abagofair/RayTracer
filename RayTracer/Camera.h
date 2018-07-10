#pragma once

#include "Vector3.h"
#include "Vector2.h"

class Camera {
private:
	Vector3<float> _u;
	Vector3<float> _v;
	Vector3<float> _w;
	Vector3<float> _viewPoint;
	int _focalDistance;

public:
	Camera(const Vector3<float> &pos, int d);
	Camera(float x, float y, float z, int d);

	const Vector3<float>& GetPosition() const;
	void SetPosition(const Vector3<float> &pos);

	const Vector3<float>& GetU() const;
	const Vector3<float>& GetV() const;
	const Vector3<float>& GetW() const;

	float GetFocalDistance();

	Vector2<float> ImagePlanePoint(int i, int j, int width, int height);
};
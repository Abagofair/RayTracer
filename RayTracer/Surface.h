#pragma once

#include "Material.h"
#include "Ray.h"
#include "Vector2.h"
#include "Vector3.h"

class Surface {
private:
	Vector3<float> _location;
	Material _material;
public:
	virtual bool Hit(const Ray& ray, Vector2<float>& hitResult);

	const Vector3<float>& GetLocation() const;
	void SetLocation(const Vector3<float>& vec);
	void SetLocation(float x, float y, float z);

	const Material& GetMaterial() const;
	void SetMaterial(const Material& material);
};
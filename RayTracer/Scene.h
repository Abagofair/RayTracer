#pragma once

//#include "Sphere.h"
class Surface;
class Camera;
class PointLight;
#include <vector>

class Scene {
private:
	std::vector<Surface*> _surfaces;
	std::vector<PointLight*> _lights;
	Camera* _mainCamera;

public:
	Scene(Camera* camera);
	~Scene();

	void AddSurface(Surface* surface);
	const std::vector<Surface*>& GetSurfaces() const;

	void AddLight(PointLight* light);
	const std::vector<PointLight*>& GetLights() const;

	//void AddLight(PointLight* light);
	Camera* GetCamera();
};
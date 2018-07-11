#pragma once

//#include "Sphere.h"
class Surface;
class Camera;

#include <vector>

class Scene {
private:
	std::vector<Surface*> _scene;
	Camera* _mainCamera;

public:
	Scene(Camera* camera);
	~Scene();

	void AddObject(Surface* sphere);
	const std::vector<Surface*>& GetScene() const;
};
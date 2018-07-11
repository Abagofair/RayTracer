#pragma once

//#include "Sphere.h"
class Sphere;
class Camera;

#include <vector>

class Scene {
private:
	std::vector<Sphere*> _scene;
	Camera* _mainCamera;

public:
	Scene(Camera* camera);
	~Scene();

	void AddObject(Sphere* sphere);
	const std::vector<Sphere*>& GetScene() const;
};
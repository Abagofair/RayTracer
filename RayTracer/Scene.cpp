#include "stdafx.h"
#include "Scene.h"

Scene::Scene(Camera* camera)
{
	_mainCamera = camera;
}

Scene::~Scene()
{
}

void Scene::AddObject(Sphere * sphere)
{
	_scene.push_back(sphere);
}

const std::vector<Sphere*>& Scene::GetScene() const
{
	return _scene;
}

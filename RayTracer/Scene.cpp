#include "stdafx.h"
#include "Scene.h"

Scene::Scene(Camera* camera)
{
	_mainCamera = camera;
}

Scene::~Scene()
{
}

void Scene::AddObject(Surface * sphere)
{
	_scene.push_back(sphere);
}

const std::vector<Surface*>& Scene::GetScene() const
{
	return _scene;
}

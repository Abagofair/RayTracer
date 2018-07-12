#include "stdafx.h"
#include "Scene.h"

Scene::Scene(Camera* camera)
{
	_mainCamera = camera;
}

Scene::~Scene()
{
}



void Scene::AddSurface(Surface* surface)
{
	_surfaces.push_back(surface);
}

const std::vector<Surface*>& Scene::GetSurfaces() const
{
	return _surfaces;
}

void Scene::AddLight(PointLight * light)
{
	_lights.push_back(light);
}

const std::vector<PointLight*>& Scene::GetLights() const
{
	return _lights;
}

Camera* Scene::GetCamera()
{
	return _mainCamera;
}

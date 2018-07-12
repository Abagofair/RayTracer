// RayTracer.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include "Vector3.h"
#include "Scene.h"
#include "Camera.h"
#include "Sphere.h"
#include "RGB.h"
#include "PointLight.h"
#include "easyppm.h"
#include "Ray.h"

RGB Shade(const Ray& viewRay, const Vector2<float> hitResult, Surface* surface, Scene* scene)
{
	Vector3<float> intersect = viewRay.GetDirection() * hitResult.GetX();
	Vector3<float> intersectNormal = (intersect - surface->GetLocation()).Normalize();
	Vector3<float> viewPointVec = (scene->GetCamera()->GetPosition() - (intersect - surface->GetLocation())).Normalize();
	RGB color = surface->GetMaterial().GetColor();
	Vector3<float> lightSourceVec;
	Vector3<float> halfVec;

	//light superposition
	float rSum = 0.f; float gSum = 0.f; float bSum = 0.f;
	for (auto light : scene->GetLights())
	{
		lightSourceVec = (light->GetPosition() - (intersect - surface->GetLocation())).Normalize();
		halfVec = (viewPointVec + lightSourceVec).Normalize();
		float dot1 = intersectNormal.DotProduct(lightSourceVec);
		float dot2 = intersectNormal.DotProduct(halfVec);
		rSum += color.GetRed() * light->GetIntensity() * std::max(0.f, dot1) +
			powf(color.GetRed() * light->GetIntensity() * std::max(0.f, dot2), 10000);
		gSum += color.GetGreen() * light->GetIntensity() * std::max(0.f, dot1) +
			powf(color.GetGreen() * light->GetIntensity() * std::max(0.f, dot2), 10000);
		bSum += color.GetBlue() * light->GetIntensity() * std::max(0.f, dot1) +
			powf(color.GetBlue() * light->GetIntensity() * std::max(0.f, dot2), 10000);
	}

	//float angle = dot / (intersectNormal.Length() * lightSource.Length()); no need to calculate the cosine if u use unit vectors
	int r = color.GetRed() * 0.5 + rSum;
	int g = color.GetGreen() * 0.5 + gSum;
	int b = color.GetBlue() * 0.5 + bSum;

	return RGB(r, g, b);
}

int main()
{
	const int imageWidth = 800;
	const int imageHeight = 800;
	RGB *pixels = new RGB [imageHeight * imageWidth];

	/*for (int i = 0; i < imageWidth; ++i)
	{
		for (int j = 0; j < imageHeight; ++j)
		{
			pixels[i + imageWidth * j] = RGB(0, 0, 0);
		}
	}*/

	Camera* camera = new Camera(0.f, 0.f, 0.f, 1);
	PointLight* pointLight = new PointLight(0.f, 10.f, -10.f, 1.f);
	PointLight* pointLight2 = new PointLight(15.f, 25.f, -10.f, 1.f);
	Sphere* sphere = new Sphere(5.f, 10.f, 0.f, 2.5f, RGB(96, 96, 96));
	Sphere* sphere2 = new Sphere(-5.f, 15.f, 0.f, 2.5f, RGB(96, 96, 96));
	Scene scene(camera);
	scene.AddSurface(sphere);
	scene.AddSurface(sphere2);
	scene.AddLight(pointLight);
	scene.AddLight(pointLight2);
	int count = 0;

	for (int i = 0; i < imageWidth; ++i)
	{
		for (int j = 0; j < imageHeight; ++j)
		{
			//construct ray
			Vector2<float> imgPlanePoint = camera->ImagePlanePoint(i, j, imageWidth, imageHeight);
			Vector3<float> origin(camera->GetPosition().GetX(), camera->GetPosition().GetY(), camera->GetPosition().GetZ());
			Vector3<float> direction = 
				(camera->GetW() * (-1 * camera->GetFocalDistance())) +
				(camera->GetU() * imgPlanePoint.GetX()) + 
				(camera->GetV() * imgPlanePoint.GetY());
			Ray ray(origin, direction);
			Vector2<float> hitResult;

			for (auto obj : scene.GetSurfaces())
			{
				if (obj->Hit(ray, hitResult))
				{
					
					++count;
					//printf("i %i and j %i\n", i, j);
					pixels[i + imageWidth * j] = Shade(ray, hitResult, obj, &scene);
				}
				else
				{
					pixels[i + imageWidth * j] = RGB(255, 255, 255);
				}
			}
		}
	}

	printf("count %i\n", count);
	PPM ppm = easyppm_create(imageWidth, imageHeight, IMAGETYPE_PPM);
	easyppm_clear(&ppm, easyppm_rgb(0, 0, 0));
	for (int i = 0; i < imageWidth; ++i)
	{
		for (int j = 0; j < imageHeight; ++j)
		{
			easyppm_set(&ppm, i, j, easyppm_rgb(pixels[i + imageWidth * j].GetRed(), pixels[i + imageWidth * j].GetGreen(), pixels[i + imageWidth * j].GetBlue()));
		}
	}
	easyppm_write(&ppm, "image.ppm");
	easyppm_destroy(&ppm);
    return 0;
}


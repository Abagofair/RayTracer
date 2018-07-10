// RayTracer.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "Vector3.h"
#include "Scene.h"
#include "Camera.h"
#include "Sphere.h"
#include "RGB.h"
#include "PointLight.h"
#include "easyppm.h"

int main()
{
	const int imageWidth = 800;
	const int imageHeight = 800;
	RGB *pixels = new RGB [imageHeight * imageWidth];

	for (int i = 0; i < imageWidth; ++i)
	{
		for (int j = 0; j < imageHeight; ++j)
		{
			pixels[i + imageWidth * j] = RGB(0, 0, 0);
		}
	}

	Camera* camera = new Camera(0.f, 0.f, 0.f, 1);
	PointLight* pointLight = new PointLight(0.f, 25.f, 10.f, 1.f);
	Sphere* sphere = new Sphere(0.f, 20.f, 0.f, 8.f);
	Scene scene(camera);
	scene.AddObject(sphere);
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

			for (auto obj : scene.GetScene())
			{
				float d = obj->CalculateIntersectDiscriminant(origin, direction);
				if (d >= 0)
				{
					float dirOffset = obj->CalculateFirstIntersectPoint(origin, direction);
					Vector3<float> intersect = direction * dirOffset;
					Vector3<float> intersectNormal = (intersect - obj->GetCenterPosition()).Normalize();
					Vector3<float> lightSource = (pointLight->GetPosition() - (intersect - obj->GetCenterPosition()));
					float dot = intersectNormal.DotProduct(lightSource);
					float angle = dot / (intersectNormal.Length() * lightSource.Length());
					int r = 96 * pointLight->GetIntensity() * std::max(0.f, angle);
					int g = 96 * pointLight->GetIntensity() * std::max(0.f, angle);
					int b = 96 * pointLight->GetIntensity() * std::max(0.f, angle);
					++count;
					//printf("i %i and j %i\n", i, j);
					pixels[i + imageWidth * j].SetRed(r);
					pixels[i + imageWidth * j].SetGreen(g);
					pixels[i + imageWidth * j].SetBlue(b);
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


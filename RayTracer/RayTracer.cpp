// RayTracer.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "Vector3.h"
#include "Scene.h"
#include "Camera.h"
#include "Sphere.h"
#include "RGB.h"
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
					++count;
					//printf("i %i and j %i\n", i, j);
					pixels[i + imageWidth * j].SetRed(255);
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


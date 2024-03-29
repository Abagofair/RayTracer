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
#include "Plane.h"

float Lambert(int color, PointLight* light, const Vector3<float>& intersectNormal, const Vector3<float>& lightSourceVector)
{
	return (color * light->GetIntensity() * std::max(0.f, intersectNormal.DotProduct(lightSourceVector)));
}

float BlinnPhong(int color, PointLight* light, float phongExponent, const Vector3<float>& intersectNormal, const Vector3<float>& halfVec)
{
	float ph = powf(std::max(0.f, intersectNormal.DotProduct(halfVec)), phongExponent);
	return color * light->GetIntensity() * ph;
}

RGB Shade(const Ray& viewRay, const Vector2<float>& hitResult, Surface* surface, Scene* scene)
{
	Vector3<float> intersect = viewRay.GetOrigin() + viewRay.GetDirection() * hitResult.GetX();
	Vector3<float> intersectNormal = (intersect - surface->GetLocation()).Normalize();
	//Vector3<float> viewPointVec = (scene->GetCamera()->GetPosition() - (intersect - surface->GetLocation())).Normalize();
	Vector3<float> viewPointVec = (scene->GetCamera()->GetPosition() - intersect).Normalize();
	RGB color = surface->GetMaterial().GetColor();
	Vector3<float> lightSourceVec;
	Vector3<float> halfVec;

	//light superposition
	float rSum = 0.f; float gSum = 0.f; float bSum = 0.f;
	for (auto light : scene->GetLights())
	{
		//lightSourceVec = (light->GetPosition() - (intersect - surface->GetLocation())).Normalize();
		lightSourceVec = (light->GetPosition() - intersect).Normalize();
		halfVec = (viewPointVec + lightSourceVec).Normalize();

		rSum += Lambert(color.GetRed(), light, intersectNormal, lightSourceVec) +
			BlinnPhong(color.GetRed(), light, surface->GetMaterial().GetPhongExponent(), intersectNormal, halfVec);

		gSum += Lambert(color.GetGreen(), light, intersectNormal, lightSourceVec) +
			BlinnPhong(color.GetGreen(), light, surface->GetMaterial().GetPhongExponent(), intersectNormal, halfVec);

		bSum += Lambert(color.GetBlue(), light, intersectNormal, lightSourceVec) +
			BlinnPhong(color.GetBlue(), light, surface->GetMaterial().GetPhongExponent(), intersectNormal, halfVec);
	}
	//(135, 206, 235) skyblue
	//float angle = dot / (intersectNormal.Length() * lightSource.Length()); no need to calculate the cosine if u use unit vectors
	int r = (color.GetRed() * 0.3f + rSum) > 255 ? 255 : color.GetRed() * 0.3f + rSum;
	int g = (color.GetGreen() * 0.3f + gSum) > 255 ? 255 : color.GetGreen() * 0.3f + gSum;
	int b = (color.GetBlue() * 0.3f + bSum) > 255 ? 255 : color.GetBlue() * 0.3f + bSum;

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

	Camera* camera = new Camera(0.f, 0.f, 0.f, 500);
	PointLight* pointLight1 = new PointLight(0.f, 5.f, -2.f, 0.5f);
	//PointLight* pointLight2 = new PointLight(5.f, 0.f, 0.f, 0.5f);
	//PointLight* pointLight3 = new PointLight(0.f, 0.f, 0.f, 0.5f);
	Sphere* sphere = new Sphere(5.f, 10.f, 0.f, 2.5f, RGB(96, 0, 96), 1000);
	Sphere* sphere2 = new Sphere(0.f, 15.f, 0.f, 2.5f, RGB(0, 96, 96), 100);
	Sphere* sphere3 = new Sphere(-7.5f, 20.f, 0.f, 2.5f, RGB(96, 96, 96), 10);
	Vector3<float> p1 = Vector3<float>(1.f, 0.f, -.01f);
	Vector3<float> p2 = Vector3<float>(1.f, 5.f, -.01f);
	Vector3<float> p3 = Vector3<float>(-1.f, 0.f, -.01f);
	Vector3<float> p1p2 = p1 - p2;
	Vector3<float> p1p3 = p1 - p3;
	Vector3<float> planeNormal = p1p3.CrossProduct(p1p2).Normalize();
	Plane* plane = new Plane(0.f, 0.f, -.01f, planeNormal, RGB(96, 96, 96), 1);
	Scene scene(camera);
	scene.AddSurface(plane);
	scene.AddSurface(sphere3);
	scene.AddSurface(sphere2);
	scene.AddSurface(sphere);
	//scene.AddSurface(plane);
	//scene.AddSurface(sphere3);
	scene.AddLight(pointLight1);
	//scene.AddLight(pointLight2);
	//scene.AddLight(pointLight3);
	int count = 0;

	for (int i = 0; i < imageHeight; ++i)
	{
		for (int j = 0; j < imageWidth; ++j)
		{
			//construct ray
			Vector2<float> imgPlanePoint = camera->ImagePlanePoint(i, j, imageWidth, imageHeight);
			Vector3<float> origin(camera->GetPosition().GetX(), camera->GetPosition().GetY(), camera->GetPosition().GetZ());
			Vector3<float> direction = 
				(camera->GetW() * (-1 * camera->GetFocalDistance())) +
				(camera->GetU() * imgPlanePoint.GetY()) + 
				(camera->GetV() * imgPlanePoint.GetX());
			Ray ray(origin, direction);
			Vector2<float> hitResult;
			bool hit = false;
			float min = 999999999.f;
			Surface* objToRender = NULL;
			for (auto obj : scene.GetSurfaces())
			{
				if (obj->Hit(ray, hitResult))
				{
					++count;
					hit = true;
					if (min > hitResult.GetX())
					{
						min = hitResult.GetX();
						objToRender = obj;
					}
					//pixels[i + imageWidth * j] = Shade(ray, hitResult, obj, &scene);
				}
			}

			if (hit)
			{
				pixels[i + imageWidth * j] = Shade(ray, hitResult, objToRender, &scene);
			}
			else
			{
				pixels[i + imageWidth * j] = RGB(0, 0, 0);
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


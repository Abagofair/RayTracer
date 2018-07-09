#include "stdafx.h"
#include "CppUnitTest.h"
#include "../RayTracer/Vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(VectorAddition)
		{
			Vector3<float> expected(4, 4, 4);
			Vector3<float> left(2, 2, 2);
			Vector3<float> right(2, 2, 2);

			Vector3<float> actual = left + right;
			Assert::AreEqual(actual, expected);
		}
	};
}
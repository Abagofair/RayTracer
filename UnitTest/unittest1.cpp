#include "stdafx.h"
#include "CppUnitTest.h"
#include "../RayTracer/Vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		

	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(VectorEquality)
		{
			Logger::WriteMessage("Overloaded VectorEquality Test");
			Vector3<float> left(2.f, 3.f, 4.f);
			Vector3<float> right1(2.f, 3.f, 4.f);
			Vector3<float> right2(2.f, 3.f, 5.f);
			bool actual1 = left == right1;
			bool actual2 = left == right2;

			Assert::AreEqual(true, actual1);
			Assert::AreEqual(false, actual2);
		}

		TEST_METHOD(VectorAddition)
		{
			Logger::WriteMessage("Overloaded VectorAddition Test");
			Vector3<float> expected(4.f, 6.f, 8.f);
			Vector3<float> left(2.f, 3.f, 4.f);
			Vector3<float> right(2.f, 3.f, 4.f);
			Vector3<float> actual = left + right;

			Assert::AreEqual(expected.GetX(), actual.GetX());
			Assert::AreEqual(expected.GetY(), actual.GetY());
			Assert::AreEqual(expected.GetZ(), actual.GetZ());
		}

		TEST_METHOD(VectorSubtraction)
		{
			Logger::WriteMessage("Overloaded VectorSubtraction Test");
			Vector3<float> expected(1.f, 1.f, 1.f);
			Vector3<float> left(2.f, 3.f, 4.f);
			Vector3<float> right(1.f, 2.f, 3.f);
			Vector3<float> actual = left - right;

			Assert::AreEqual(expected.GetX(), actual.GetX());
			Assert::AreEqual(expected.GetY(), actual.GetY());
			Assert::AreEqual(expected.GetZ(), actual.GetZ());
		}

		TEST_METHOD(VectorScalarMult)
		{
			Logger::WriteMessage("Overloaded VectorScalar Multiplication Test");
			Vector3<float> expected(10.f, 15.f, 20.f);
			Vector3<float> left(2.f, 3.f, 4.f);
			float scalar = 5.f;
			Vector3<float> actual = left * scalar;

			Assert::AreEqual(expected.GetX(), actual.GetX());
			Assert::AreEqual(expected.GetY(), actual.GetY());
			Assert::AreEqual(expected.GetZ(), actual.GetZ());
		}

		TEST_METHOD(VectorDotProd)
		{
			Logger::WriteMessage("Vector dot product Test");
			float expected = 20.f;
			Vector3<float> left(2.f, 3.f, 4.f);
			Vector3<float> right(1.f, 2.f, 3.f);
			float actual = left.DotProduct(right);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VectorCrossProduct)
		{
			Logger::WriteMessage("Vector cross product Test");
			Vector3<float> expected(-3.f, 6.f, -3.f);
			Vector3<float> left(2.f, 3.f, 4.f);
			Vector3<float> right(5.f, 6.f, 7.f);
			Vector3<float> actual = left.CrossProduct(right);

			Assert::AreEqual(expected.GetX(), actual.GetX());
			Assert::AreEqual(expected.GetY(), actual.GetY());
			Assert::AreEqual(expected.GetZ(), actual.GetZ());
		}

		TEST_METHOD(VectorLength)
		{
			Logger::WriteMessage("Vector length Test");
			float expected = 6.f;
			Vector3<float> left(2.f, 4.f, 4.f);
			float actual = left.Length();

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VectorUnit)
		{
			Logger::WriteMessage("Vector normalize Test");
			float expected = 1.f;
			Vector3<float> left(2.f, 4.f, 4.f);
			float actual = left.Normalize().Length();

			Assert::AreEqual(expected, actual);
		}
	};
}
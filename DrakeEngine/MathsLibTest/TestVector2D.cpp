#include "pch.h"
#include "CppUnitTest.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathsLibTest
{
	TEST_CLASS(Vector2D_UnitTest)
	{
		TEST_CLASS_INITIALIZE(testInit) {
			srand((unsigned int)time(nullptr));
		}

		Vector2D rVector2D() {
			return Vector2D(
				(double)((rand() % 10000) + 1000) - 5000,
				(double)((rand() % 10000) + 1000) - 5000
			);
		}

		Vector2D tVector2D(Vector2D a_other) {
			return Vector2D(a_other[0], a_other[1]);
		}
		
	public:

		TEST_METHOD(add) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			Vector2D result = test + test1;
			Vector2D aresult = atest + atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
		}

		TEST_METHOD(addEquals) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			test += test1;
			atest += atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(subtract) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			Vector2D result = test - test1;
			Vector2D aresult = atest - atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
		}
		
		TEST_METHOD(subtractEquals) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			test -= test1;
			atest -= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyScalar) {
			Vector2D test = rVector2D();

			Vector2D atest = tVector2D(test);

			test = test * 1.5f;
			atest = atest * 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyEqualsScalar) {
			Vector2D test = rVector2D();

			Vector2D atest = tVector2D(test);

			test  *= 1.5f;
			atest *= 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(multiply) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			test = test * test1;
			atest = atest * atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyEquals) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			test *= test1;
			atest *= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(divideScalar) {
			Vector2D test = rVector2D();

			Vector2D atest = tVector2D(test);

			test = test / 1.5f;
			atest = atest / 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(divideEqualsScalar) {
			Vector2D test = rVector2D();

			Vector2D atest = tVector2D(test);

			test  /= 1.5f;
			atest /= 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(divide) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			test = test / test1;
			atest = atest / atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(divideEquals) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			test  /= test1;
			atest /= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
		}

		TEST_METHOD(equalTo) {
			Vector2D test = rVector2D();

			Vector2D atest = tVector2D(test);

			Assert::AreEqual(test[0], atest[0]);
			Assert::AreEqual(test[1], atest[1]);
		}

		TEST_METHOD(notEqualTo) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();
			
			Assert::AreNotEqual(test[0], test1[0]);
			Assert::AreNotEqual(test[1], test1[1]);
		}

		TEST_METHOD(ConstructorsSquareBrackets) {
			Vector2D test(4.0f, 5.0f);
			Assert::AreEqual(test[0], 4.0f);
			Assert::AreEqual(test[1], 5.0f);
		}

		TEST_METHOD(ConstructorsSquareBrackets_Large) {
			Vector2D test(40000.0f, 50000.0f);
			Assert::AreEqual(test[0], 40000.0f);
			Assert::AreEqual(test[1], 50000.0f);
		}

		TEST_METHOD(ConstructorsSquareBrackets_Small) {
			Vector2D test(0.00001f, 0.00001f);
			Assert::AreEqual(test[0], 0.00001f);
			Assert::AreEqual(test[1], 0.00001f);
		}

		TEST_METHOD(magnitudeSq) {
			Vector2D test = rVector2D();
			Vector2D tester = tVector2D(test);
			Assert::IsTrue(abs(tester.magnitudeSq() - test.magnitudeSq()) < FLT_EPSILON);
		}

		TEST_METHOD(magnitude) {
			Vector2D test = rVector2D();
			Vector2D tester = tVector2D(test);
			Assert::IsTrue(abs(tester.magnitude() - test.magnitude()) < FLT_EPSILON);
		}

		TEST_METHOD(distanceSq) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			Assert::IsTrue(abs(atest.distanceSq(atest1) - test.distanceSq(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(distance) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();

			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			Assert::IsTrue(abs(atest.distance(atest1) - test.distance(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(crossProduct) {
			Vector2D test = rVector2D();
			Vector2D test1 = tVector2D(test);

			Assert::AreEqual(test.crossProduct(test, test1)[0], test1.crossProduct(test1, test)[0]);
			Assert::AreEqual(test.crossProduct(test, test1)[1], test1.crossProduct(test1, test)[1]);
		}

		TEST_METHOD(dotProduct) {
			Vector2D test = rVector2D();
			Vector2D test1 = rVector2D();
			
			Vector2D atest = tVector2D(test);
			Vector2D atest1 = tVector2D(test1);

			Assert::IsTrue(abs(atest.dotProduct(atest, atest1) - test.dotProduct(test, test1)) < FLT_EPSILON);
		}

		TEST_METHOD(normalise) {
			Vector2D test = rVector2D();

			Vector2D normalised = test.normalise();
			test = test.normalise();

			Assert::AreEqual(normalised[0], test[0]);
			Assert::AreEqual(normalised[1], test[1]);

			float expectedMag = 1.0f;
			
			Assert::IsTrue(abs(expectedMag - test.magnitudeSq()) < FLT_EPSILON);
			Assert::IsTrue(abs(expectedMag - normalised.magnitudeSq()) < FLT_EPSILON);
		}
	};
}

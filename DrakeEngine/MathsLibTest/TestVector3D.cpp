#include "pch.h"
#include "CppUnitTest.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathsLibTest
{
	TEST_CLASS(Vector3D_UnitTest)
	{
		TEST_CLASS_INITIALIZE(testInit) {
			srand((unsigned int)time(nullptr));
		}

		Vector3D rVector3D() {
			return Vector3D(
				(double)((rand() % 10000) + 1000) - 5000,
				(double)((rand() % 10000) + 1000) - 5000,
				(double)((rand() % 10000) + 1000) - 5000
			);
		}

		Vector3D tVector3D(Vector3D a_other) {
			return Vector3D(a_other[0], a_other[1], a_other[2]);
		}

	public:
		TEST_METHOD(add) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			Vector3D result = test + test1;
			Vector3D aresult = atest + atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
		}

		TEST_METHOD(addEquals) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			test += test1;
			atest += atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(subtract) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			Vector3D result = test - test1;
			Vector3D aresult = atest - atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
		}

		TEST_METHOD(subtractEquals) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			test -= test1;
			atest -= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyScalar) {
			Vector3D test = rVector3D();

			Vector3D atest = tVector3D(test);

			test = test * 1.5f;
			atest = atest * 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyEqualsScalar) {
			Vector3D test = rVector3D();

			Vector3D atest = tVector3D(test);

			test *= 1.5f;
			atest *= 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(multiply) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			test = test * test1;
			atest = atest * atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyEquals) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			test *= test1;
			atest *= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(divideScalar) {
			Vector3D test = rVector3D();

			Vector3D atest = tVector3D(test);

			test = test / 1.5f;
			atest = atest / 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(divideEqualsScalar) {
			Vector3D test = rVector3D();

			Vector3D atest = tVector3D(test);

			test /= 1.5f;
			atest /= 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(divide) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			test = test / test1;
			atest = atest / atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(divideEquals) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			test /= test1;
			atest /= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(equalTo) {
			Vector3D test = rVector3D();

			Vector3D atest = tVector3D(test);

			Assert::AreEqual(test[0], atest[0]);
			Assert::AreEqual(test[1], atest[1]);
			Assert::AreEqual(test[2], atest[2]);
		}

		TEST_METHOD(notEqualTo) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Assert::AreNotEqual(test[0], test1[0]);
			Assert::AreNotEqual(test[1], test1[1]);
			Assert::AreNotEqual(test[2], test1[2]);
		}

		TEST_METHOD(ConstructorsSquareBrackets) {
			Vector3D test(4.0f, 5.0f, 6.0f);
			Assert::AreEqual(test[0], 4.0f);
			Assert::AreEqual(test[1], 5.0f);
			Assert::AreEqual(test[2], 6.0f);
		}

		TEST_METHOD(ConstructorsSquareBrackets_Large) {
			Vector3D test(40000.0f, 50000.0f, 60000.0f);
			Assert::AreEqual(test[0], 40000.0f);
			Assert::AreEqual(test[1], 50000.0f);
			Assert::AreEqual(test[2], 60000.0f);
		}

		TEST_METHOD(ConstructorsSquareBrackets_Small) {
			Vector3D test(0.00001f, 0.00001f, 0.00001f);
			Assert::AreEqual(test[0], 0.00001f);
			Assert::AreEqual(test[1], 0.00001f);
			Assert::AreEqual(test[2], 0.00001f);
		}

		TEST_METHOD(magnitude) {
			Vector3D test = rVector3D();
			Vector3D tester = tVector3D(test);
			Assert::IsTrue(abs(tester.magnitude() - test.magnitude()) < FLT_EPSILON);
		}

		TEST_METHOD(magnitudeSq) {
			Vector3D test = rVector3D();
			Vector3D tester = tVector3D(test);
			Assert::IsTrue(abs(tester.magnitudeSq() - test.magnitudeSq()) < FLT_EPSILON);
		}

		TEST_METHOD(distance) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			Assert::IsTrue(abs(atest.distance(atest1) - test.distance(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(distanceSq) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			Assert::IsTrue(abs(atest.distanceSq(atest1) - test.distanceSq(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(dotProduct) {
			Vector3D test = rVector3D();
			Vector3D test1 = rVector3D();

			Vector3D atest = tVector3D(test);
			Vector3D atest1 = tVector3D(test1);

			Assert::IsTrue(abs(atest.dotProduct(atest, atest1) - test.dotProduct(test, test1)) < FLT_EPSILON);
		}

		TEST_METHOD(crossProduct) {
			Vector3D test = rVector3D();
			Vector3D test1 = tVector3D(test);

			Assert::AreEqual(test.crossProduct(test, test1)[0], test1.crossProduct(test1, test)[0]);
			Assert::AreEqual(test.crossProduct(test, test1)[1], test1.crossProduct(test1, test)[1]);
			Assert::AreEqual(test.crossProduct(test, test1)[2], test1.crossProduct(test1, test)[2]);
		}

		TEST_METHOD(normalise) {
			Vector3D test = rVector3D();

			Vector3D normalised = test.normalise();
			test = test.normalise();

			Assert::AreEqual(normalised[0], test[0]);
			Assert::AreEqual(normalised[1], test[1]);

			float expectedMag = 1.0f;

			Assert::IsTrue(abs(expectedMag - test.magnitudeSq()) < FLT_EPSILON);
			Assert::IsTrue(abs(expectedMag - normalised.magnitudeSq()) < FLT_EPSILON);
		}
	};
}
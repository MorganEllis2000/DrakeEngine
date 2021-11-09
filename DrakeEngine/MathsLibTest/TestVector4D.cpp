#include "pch.h"
#include "CppUnitTest.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathsLibTest
{
	TEST_CLASS(Vector4D_UnitTest)
	{
		TEST_CLASS_INITIALIZE(testInit) {
			srand((unsigned int)time(nullptr));
		}

		Vector4D rVector4D() {
			return Vector4D(
				(double)((rand() % 10000) + 1000) - 5000,
				(double)((rand() % 10000) + 1000) - 5000,
				(double)((rand() % 10000) + 1000) - 5000,
				(double)((rand() % 10000) + 1000) - 5000
			);
		}

		Vector4D tVector4D(Vector4D a_other) {
			return Vector4D(a_other[0], a_other[1], a_other[2], a_other[3]);
		}

	public:
		TEST_METHOD(add) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			Vector4D result = test + test1;
			Vector4D aresult = atest + atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[3] - aresult[3]) < FLT_EPSILON);
		}

		TEST_METHOD(addEquals) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			test += test1;
			atest += atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}

		TEST_METHOD(subtract) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			Vector4D result = test - test1;
			Vector4D aresult = atest - atest1;

			Assert::IsTrue(abs(result[0] - aresult[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[1] - aresult[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[2] - aresult[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(result[3] - aresult[3]) < FLT_EPSILON);
		}

		TEST_METHOD(subtractEquals) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			test -= test1;
			atest -= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}
				
		TEST_METHOD(multiply) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			test = test * test1;
			atest = atest * atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyEquals) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			test *= test1;
			atest *= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}
		
		TEST_METHOD(multiplyScalar) {
			Vector4D test = rVector4D();

			Vector4D atest = tVector4D(test);

			test = test * 1.5f;
			atest = atest * 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyEqualsScalar) {
			Vector4D test = rVector4D();

			Vector4D atest = tVector4D(test);

			test *= 1.5f;
			atest *= 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}

		TEST_METHOD(divideScalar) {
			Vector4D test = rVector4D();

			Vector4D atest = tVector4D(test);

			test = test / 1.5f;
			atest = atest / 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}

		TEST_METHOD(divideEqualsScalar) {
			Vector4D test = rVector4D();

			Vector4D atest = tVector4D(test);

			test /= 1.5f;
			atest /= 1.5;;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}

		TEST_METHOD(divide) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			test = test / test1;
			atest = atest / atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}

		TEST_METHOD(divideEquals) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			test /= test1;
			atest /= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[3] - atest[3]) < FLT_EPSILON);
		}

		
		TEST_METHOD(equalTo) {
			Vector4D test = rVector4D();

			Vector4D atest = tVector4D(test);

			Assert::AreEqual(test[0], atest[0]);
			Assert::AreEqual(test[1], atest[1]);
			Assert::AreEqual(test[2], atest[2]);
			Assert::AreEqual(test[3], atest[3]);
		}

		TEST_METHOD(notEqualTo) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Assert::AreNotEqual(test[0], test1[0]);
			Assert::AreNotEqual(test[1], test1[1]);
			Assert::AreNotEqual(test[2], test1[2]);
			Assert::AreNotEqual(test[3], test1[3]);
		}

		TEST_METHOD(ConstructorsSquareBrackets) {
			Vector4D test(4.0f, 5.0f, 6.0f, 7.0f);
			Assert::AreEqual(test[0], 4.0f);
			Assert::AreEqual(test[1], 5.0f);
			Assert::AreEqual(test[2], 6.0f);
			Assert::AreEqual(test[3], 7.0f);
		}

		TEST_METHOD(ConstructorsSquareBrackets_Large) {
			Vector4D test(40000.0f, 50000.0f, 60000.0f, 70000.0f);
			Assert::AreEqual(test[0], 40000.0f);
			Assert::AreEqual(test[1], 50000.0f);
			Assert::AreEqual(test[2], 60000.0f);
			Assert::AreEqual(test[3], 70000.0f);
		}

		TEST_METHOD(ConstructorsSquareBrackets_Small) {
			Vector4D test(0.00001f, 0.00001f, 0.00001f, 0.00001f);
			Assert::AreEqual(test[0], 0.00001f);
			Assert::AreEqual(test[1], 0.00001f);
			Assert::AreEqual(test[2], 0.00001f);
			Assert::AreEqual(test[3], 0.00001f);
		}

		
		TEST_METHOD(magnitude) {
			Vector4D test = rVector4D();
			Vector4D tester = tVector4D(test);
			Assert::IsTrue(abs(tester.magnitude() - test.magnitude()) < FLT_EPSILON);
		}

		TEST_METHOD(magnitudeSq) {
			Vector4D test = rVector4D();
			Vector4D tester = tVector4D(test);
			Assert::IsTrue(abs(tester.magnitudeSq() - test.magnitudeSq()) < FLT_EPSILON);
		}

		/*
		TEST_METHOD(distance) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			Assert::IsTrue(abs(atest.distance(atest1) - test.distance(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(distanceSq) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			Assert::IsTrue(abs(atest.distanceSq(atest1) - test.distanceSq(test1)) < FLT_EPSILON);
		}

		TEST_METHOD(dotProduct) {
			Vector4D test = rVector4D();
			Vector4D test1 = rVector4D();

			Vector4D atest = tVector4D(test);
			Vector4D atest1 = tVector4D(test1);

			Assert::IsTrue(abs(atest.dotProduct(atest, atest1) - test.dotProduct(test, test1)) < FLT_EPSILON);
		}

		TEST_METHOD(crossProduct) {
			Vector4D test = rVector4D();
			Vector4D test1 = tVector4D(test);

			Assert::AreEqual(test.crossProduct(test, test1)[0], test1.crossProduct(test1, test)[0]);
			Assert::AreEqual(test.crossProduct(test, test1)[1], test1.crossProduct(test1, test)[1]);
			Assert::AreEqual(test.crossProduct(test, test1)[2], test1.crossProduct(test1, test)[2]);
		}

		TEST_METHOD(normalise) {
			Vector4D test = rVector4D();

			Vector4D normalised = test.normalise();
			test = test.normalise();

			Assert::AreEqual(normalised[0], test[0]);
			Assert::AreEqual(normalised[1], test[1]);

			float expectedMag = 1.0f;

			Assert::IsTrue(abs(expectedMag - test.magnitudeSq()) < FLT_EPSILON);
			Assert::IsTrue(abs(expectedMag - normalised.magnitudeSq()) < FLT_EPSILON);
		}
		*/
	};
}
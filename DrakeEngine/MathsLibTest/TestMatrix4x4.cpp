#include "pch.h"
#include "CppUnitTest.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathsLibTest
{
	TEST_CLASS(Matrix4x4_UnitTest)
	{
		TEST_CLASS_INITIALIZE(testInit) {
			srand((unsigned int)time(nullptr));
		}

		Matrix4x4 rMatrix4x4() {
			return Matrix4x4(
				(double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000,
				(double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000,
				(double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000,
				(double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000
			);
		}

		Matrix4x4 tMatrix4x4(Matrix4x4 a_other) {
			return Matrix4x4(a_other[0], a_other[1], a_other[2], a_other[3], a_other[4], a_other[5], a_other[6], a_other[7], a_other[8],
							 a_other[9], a_other[10], a_other[11], a_other[12], a_other[13], a_other[14], a_other[15]);
		}

		float rTheta = ((rand() % 10000) + 1000) - 5000;

	public:
		TEST_METHOD(add) {
			Matrix4x4 test = rMatrix4x4();
			Matrix4x4 test1 = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);
			Matrix4x4 atest1 = tMatrix4x4(test1);

			Matrix4x4 result = test + test1;
			Matrix4x4 aresult = atest + atest1;

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(result[i] - aresult[i]) < FLT_EPSILON);
			}

		}

		TEST_METHOD(addEquals) {
			Matrix4x4 test = rMatrix4x4();
			Matrix4x4 test1 = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);
			Matrix4x4 atest1 = tMatrix4x4(test1);

			test += test1;
			atest += atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(subtract) {
			Matrix4x4 test = rMatrix4x4();
			Matrix4x4 test1 = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);
			Matrix4x4 atest1 = tMatrix4x4(test1);

			Matrix4x4 result = test - test1;
			Matrix4x4 aresult = atest - atest1;

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(result[i] - aresult[i]) < FLT_EPSILON);
			}

		}

		TEST_METHOD(subtractEquals) {
			Matrix4x4 test = rMatrix4x4();
			Matrix4x4 test1 = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);
			Matrix4x4 atest1 = tMatrix4x4(test1);

			test -= test1;
			atest -= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyScalar) {
			Matrix4x4 test = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);

			test = test * 1.5f;
			atest = atest * 1.5;;

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(multiplyEqualsScalar) {
			Matrix4x4 test = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);

			test *= 1.5f;
			atest *= 1.5;;

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(multiply) {
			Matrix4x4 test = rMatrix4x4();
			Matrix4x4 test1 = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);
			Matrix4x4 atest1 = tMatrix4x4(test1);

			test = test * test1;
			atest = atest * atest1;

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(multiplyEquals) {
			Matrix4x4 test = rMatrix4x4();
			Matrix4x4 test1 = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);
			Matrix4x4 atest1 = tMatrix4x4(test1);

			test *= test1;
			atest *= atest1;

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(equalTo) {
			Matrix4x4 test = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);

			for (int i = 0; i < 16; i++) {
				Assert::AreEqual(test[0], atest[0]);
			}
		}

		TEST_METHOD(notEqualTo) {
			Matrix4x4 test = rMatrix4x4();
			Matrix4x4 test1 = rMatrix4x4();

			for (int i = 0; i < 16; i++) {
				Assert::AreNotEqual(test[i], test1[i]);
			}
		}

		TEST_METHOD(ConstructorsSquareBrackets) {
			Matrix4x4 test( 4.0, 4.0, 4.0, 4.0,
							4.0, 4.0, 4.0, 4.0,
							4.0, 4.0, 4.0, 4.0,
							4.0, 4.0, 4.0, 4.0);

			for (int i = 0; i < 16; ++i) {
				Assert::AreEqual(test[i], 4.0);
			}
		}

		TEST_METHOD(ConstructorsSquareBrackets_Large) {
			Matrix4x4 test( 40000.0, 40000.0, 40000.0, 40000.0,
							40000.0, 40000.0, 40000.0, 40000.0,
							40000.0, 40000.0, 40000.0, 40000.0,
							40000.0, 40000.0, 40000.0, 40000.0);

			for (int i = 0; i < 16; ++i) {
				Assert::AreEqual(test[i], 40000.0);
			}
		}

		TEST_METHOD(ConstructorsSquareBrackets_Small) {
			Matrix4x4 test( 0.00001, 0.00001, 0.00001, 0.00001,
							0.00001, 0.00001, 0.00001, 0.00001,
							0.00001, 0.00001, 0.00001, 0.00001,
							0.00001, 0.00001, 0.00001, 0.00001);
			for (int i = 0; i < 16; ++i) {
				Assert::AreEqual(test[i], 0.00001);
			}
		}

		TEST_METHOD(identity) {
			Matrix4x4 test = rMatrix4x4();

			test.Identity();

			Assert::AreEqual(test[0], 1.0);
			Assert::AreEqual(test[1], 0.0);
			Assert::AreEqual(test[2], 0.0);
			Assert::AreEqual(test[3], 0.0);
			Assert::AreEqual(test[4], 0.0);
			Assert::AreEqual(test[5], 1.0);
			Assert::AreEqual(test[6], 0.0);
			Assert::AreEqual(test[7], 0.0);
			Assert::AreEqual(test[8], 0.0);
			Assert::AreEqual(test[9], 0.0);
			Assert::AreEqual(test[10], 1.0);
			Assert::AreEqual(test[11], 0.0);
			Assert::AreEqual(test[12], 0.0);
			Assert::AreEqual(test[13], 0.0);
			Assert::AreEqual(test[14], 0.0);
			Assert::AreEqual(test[15], 1.0);
		}

		TEST_METHOD(det3x3) {
			Matrix4x4 test = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);

			test.det4x4();
			atest.det4x4();

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(transpose) {
			Matrix4x4 test = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);

			atest.Transpose();

			Assert::AreEqual(test[0], atest[0]);
			Assert::AreEqual(test[1], atest[4]);
			Assert::AreEqual(test[2], atest[8]);
			Assert::AreEqual(test[3], atest[12]);
			Assert::AreEqual(test[4], atest[1]);
			Assert::AreEqual(test[5], atest[5]);
			Assert::AreEqual(test[6], atest[9]);
			Assert::AreEqual(test[7], atest[13]);
			Assert::AreEqual(test[8], atest[2]);
			Assert::AreEqual(test[9], atest[6]);
			Assert::AreEqual(test[10], atest[10]);
			Assert::AreEqual(test[11], atest[14]);
			Assert::AreEqual(test[12], atest[3]);
			Assert::AreEqual(test[13], atest[7]);
			Assert::AreEqual(test[14], atest[11]);
			Assert::AreEqual(test[15], atest[15]);
		}

		TEST_METHOD(inverse) {
			Matrix4x4 test = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);

			test.Inverse();
			atest.Inverse();

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(RotateX) {
			Matrix4x4 test = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);
			float theta = rTheta;
			test.RotateX(theta);
			atest.RotateX(theta);

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(RotateY) {
			Matrix4x4 test = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);
			float theta = rTheta;
			test.RotateY(theta);
			atest.RotateY(theta);

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(RotateZ) {
			Matrix4x4 test = rMatrix4x4();

			Matrix4x4 atest = tMatrix4x4(test);
			float theta = rTheta;
			test.RotateZ(theta);
			atest.RotateZ(theta);

			for (int i = 0; i < 16; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

	};
}
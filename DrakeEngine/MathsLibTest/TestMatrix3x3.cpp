#include "pch.h"
#include "CppUnitTest.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathsLibTest
{
	TEST_CLASS(Matrix3x3_UnitTest)
	{
		TEST_CLASS_INITIALIZE(testInit) {
			srand((unsigned int)time(nullptr));
		}

		Matrix3x3 rMatrix3x3() {
			return Matrix3x3(
							(double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, 
							(double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, 
							(double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000, (double)((rand() % 10000) + 1000) - 5000
			);
		}

		Matrix3x3 tMatrix3x3(Matrix3x3 a_other) {
			return Matrix3x3(a_other[0], a_other[1], a_other[2], a_other[3], a_other[4], a_other[5], a_other[6], a_other[7], a_other[8]);
		}

		float rTheta = ((rand() % 10000) + 1000) - 5000;

	public:
		TEST_METHOD(add) {
			Matrix3x3 test = rMatrix3x3();
			Matrix3x3 test1 = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);
			Matrix3x3 atest1 = tMatrix3x3(test1);

			Matrix3x3 result = test + test1;
			Matrix3x3 aresult = atest + atest1;

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(result[i] - aresult[i]) < FLT_EPSILON);
			}
		
		}

		TEST_METHOD(addEquals) {
			Matrix3x3 test = rMatrix3x3();
			Matrix3x3 test1 = rMatrix3x3();

			Matrix3x3 atest  = tMatrix3x3(test);
			Matrix3x3 atest1 = tMatrix3x3(test1);

			test += test1;
			atest += atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(subtract) {
			Matrix3x3 test = rMatrix3x3();
			Matrix3x3 test1 = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);
			Matrix3x3 atest1 = tMatrix3x3(test1);

			Matrix3x3 result = test - test1;
			Matrix3x3 aresult = atest - atest1;

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(result[i] - aresult[i]) < FLT_EPSILON);
			}

		}

		TEST_METHOD(subtractEquals) {
			Matrix3x3 test = rMatrix3x3();
			Matrix3x3 test1 = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);
			Matrix3x3 atest1 = tMatrix3x3(test1);

			test  -= test1;
			atest -= atest1;

			Assert::IsTrue(abs(test[0] - atest[0]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[1] - atest[1]) < FLT_EPSILON);
			Assert::IsTrue(abs(test[2] - atest[2]) < FLT_EPSILON);
		}

		TEST_METHOD(multiplyScalar) {
			Matrix3x3 test = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);

			test = test * 1.5f;
			atest = atest * 1.5;;

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}	
		}

		TEST_METHOD(multiplyEqualsScalar) {
			Matrix3x3 test = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);

			test *= 1.5f;
			atest *= 1.5;;

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(multiply) {
			Matrix3x3 test = rMatrix3x3();
			Matrix3x3 test1 = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);
			Matrix3x3 atest1 = tMatrix3x3(test1);

			test = test * test1;
			atest = atest * atest1;

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(multiplyEquals) {
			Matrix3x3 test = rMatrix3x3();
			Matrix3x3 test1 = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);
			Matrix3x3 atest1 = tMatrix3x3(test1);

			test *= test1;
			atest *= atest1;

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(equalTo) {
			Matrix3x3 test = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);

			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(test[0], atest[0]);
			}
		}

		TEST_METHOD(notEqualTo) {
			Matrix3x3 test = rMatrix3x3();
			Matrix3x3 test1 = rMatrix3x3();

			for (int i = 0; i < 9; i++) {
				Assert::AreNotEqual(test[i], test1[i]);
			}
		}

		TEST_METHOD(ConstructorsSquareBrackets) {
			Matrix3x3 test(4.0, 4.0, 4.0,
						   4.0, 4.0, 4.0,
						   4.0, 4.0, 4.0);

			for (int i = 0; i < 9; ++i) {
				Assert::AreEqual(test[i], 4.0);
			}
		}

		TEST_METHOD(ConstructorsSquareBrackets_Large) {
			Matrix3x3 test( 40000.0, 40000.0, 40000.0,
							40000.0, 40000.0, 40000.0,
							40000.0, 40000.0, 40000.0);

			for (int i = 0; i < 9; ++i) {
				Assert::AreEqual(test[i], 40000.0);
			}
		}

		TEST_METHOD(ConstructorsSquareBrackets_Small) {
			Matrix3x3 test( 0.00001, 0.00001, 0.00001,
							0.00001, 0.00001, 0.00001,
							0.00001, 0.00001, 0.00001);
			for (int i = 0; i < 9; ++i) {
				Assert::AreEqual(test[i], 0.00001);
			}
		}

		TEST_METHOD(identity) {
			Matrix3x3 test = rMatrix3x3();

			test.Identity();

			Assert::AreEqual(test[0], 1.0);
			Assert::AreEqual(test[1], 0.0);
			Assert::AreEqual(test[2], 0.0);
			Assert::AreEqual(test[3], 0.0);
			Assert::AreEqual(test[4], 1.0);
			Assert::AreEqual(test[5], 0.0);
			Assert::AreEqual(test[6], 0.0);
			Assert::AreEqual(test[7], 0.0);
			Assert::AreEqual(test[8], 1.0);
		}

		TEST_METHOD(det3x3) {
			Matrix3x3 test = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);

			test.det3x3();
			atest.det3x3();

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(transpose) {
			Matrix3x3 test = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);

			atest.Transpose();

			Assert::AreEqual(test[0], atest[0]);
			Assert::AreEqual(test[1], atest[3]);
			Assert::AreEqual(test[2], atest[6]);
			Assert::AreEqual(test[3], atest[1]);
			Assert::AreEqual(test[4], atest[4]);
			Assert::AreEqual(test[5], atest[7]);
			Assert::AreEqual(test[6], atest[2]);
			Assert::AreEqual(test[7], atest[5]);
			Assert::AreEqual(test[8], atest[8]);
		}

		TEST_METHOD(inverse) {
			Matrix3x3 test = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);

			test.Inverse();
			atest.Inverse();

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(RotateX) {
			Matrix3x3 test = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);
			float theta = rTheta;
			test.RotateX(theta);
			atest.RotateX(theta);

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(RotateY) {
			Matrix3x3 test = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);
			float theta = rTheta;
			test.RotateY(theta);
			atest.RotateY(theta);

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

		TEST_METHOD(RotateZ) {
			Matrix3x3 test = rMatrix3x3();

			Matrix3x3 atest = tMatrix3x3(test);
			float theta = rTheta;
			test.RotateZ(theta);
			atest.RotateZ(theta);

			for (int i = 0; i < 9; i++) {
				Assert::IsTrue(abs(test[i] - atest[i]) < FLT_EPSILON);
			}
		}

	};
}
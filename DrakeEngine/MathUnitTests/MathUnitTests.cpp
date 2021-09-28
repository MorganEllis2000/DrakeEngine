#include <cstdlib>
#include <ctime>

#include "pch.h"
#include "CppUnitTest.h"
#include "../DrakeEngine/Math.h"
using namespace Math;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathUnitTests
{
	TEST_CLASS(MathUnitTests)
	{

		TEST_CLASS_INITIALIZE(testInit)
		{
			srand((unsigned int)time(nullptr));
		}

		Vector3D rCvector2() {
			return Vector3D();
		}

	public:
		
		TEST_METHOD(RadToDegTest)
		{
			
		}
	};
}

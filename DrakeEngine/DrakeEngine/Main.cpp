#include <iostream>
#include "Math.h"
#include "Vector3D.h"
#include "Vector2D.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

using namespace std;
using namespace Math;

int main() {
	Vector2D vector2D;
	Vector2D vec(1.5f, 1.5f);
	Vector2D vec1(2.f, 3.f);
	Vector2D vec2(3.f, 6.4f);
	cout << vec2[0] << ", " << vec2[1] << endl;

	float mag = vec2.magnitudeSq();
	vec2 = vec2.normalise();
	cout << vec2[0] << ", " << vec2[1] << endl;
	cout << mag;
	return 0;
}
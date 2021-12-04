#include <iostream>
#include "MathsLibrary.h"

using namespace std;
int main() {
	
	Vector3D vec2(1.f, 2.f, 3.f);
	Vector4D vec1 = Vector4D();
	Vector4D vec(2,3,4,5);
	Matrix4x4 mat(2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0);
	float mag = vec.distanceSq(vec1);
	vec1 = vec * mat;

	for (int i = 0; i < 4; i++) {
		cout << vec1[i] << endl;
	}
	
	vec1 = vec1.normalise();
}
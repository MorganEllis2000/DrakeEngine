#include <iostream>
#include "MathLib.h"

using namespace std;
using namespace Math;

int main() {
	Vector3D vec0 = Vector3D();
	Vector3D vec(1.7f, 1.7f, 2.3f);
	Vector3D vec1(2.f, 3.f, 0.6);
	Vector3D vec2(vec1);

	cout << vec0[0] << ", " << vec0[1] << ", " << vec0[2] << endl;

	//cout << mag << endl;
	
	cout << vec0[0] << ", " << vec0[1] << ", " << vec0[2] << endl;

	return 0;
}
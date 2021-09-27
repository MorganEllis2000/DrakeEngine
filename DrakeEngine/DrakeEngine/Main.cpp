#include <iostream>
#include "Math.h"
using namespace std;
using namespace Math;

int main() {
	
	Vector3D vector;
	vector.x = 3;
	vector.y = 5;
	vector.z = 7;

	Vector3D vector2;
	vector2.x = 10;
	vector2.y = 15;
	vector2.z = 17;

	Vector3D vector3 = cross(vector, vector2);

	cout << RadToDeg(3.21);

	return 0;
}
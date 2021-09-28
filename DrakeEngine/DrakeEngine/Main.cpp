#include <iostream>
#include "Math.h"
#include "Vector3D.h"
#include "Vector2D.h"

using namespace std;
using namespace Math;

int main() {
	Vector2D vector2D;
	
	Vector2D vector(3, 5);

	Vector2D vector2(10, 15);

	Vector2D vector3 = vector2D.crossProduct(vector, vector2);

	cout << vector[0] << endl;
	cout << vector.GetPointer() << endl;
	cout << vector2.GetPointer() << endl;
	cout << vector3.GetPointer() << endl;

	

	return 0;
}
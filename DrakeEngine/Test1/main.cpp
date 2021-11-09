#include <iostream>
#include "MathsLibrary.h"

using namespace std;
int main() {
	
	Vector3D vec2(1.f, 2.f, 3.f);
	Vector4D vec1(2.f, 2.f, 3.f, 4.f);
	Vector4D vec(1.6f, 2.6f, 3.6f, 4.6f);
	float mag = vec.distanceSq(vec1);
	cout << mag << endl;
	cout << vec2.GetPointer() << endl;
	cout << vec[0] << ", " << vec[1] << ", " << vec[2] << ", " << vec[3] <<  endl;
}
#include <iostream>
#include "Math.h"
#include "Vector3D.h"
#include "Vector2D.h"
#include "Matrix3x3.h"

using namespace std;
using namespace Math;

int main() {
	Matrix3x3 matrix3x3;

	//Matrix3x3 mat1(10,1,2,3,4,5,6,7,8);
	Matrix3x3 mat4(0, 1, 2, 3, 4, 5, 6, 7, 8);
	//Matrix3x3 mat1(3,-4,-5,7,-7,8,5,-7,-8);
	Matrix3x3 mat1(3, 0, 2, 2, 0, -2, 0, 1, 1);
	//Matrix3x3 mat1(1,2,3,0,1,4,5,6,0);
	Matrix3x3 mat(1, 0, 0, 0, 0, -1, 0, 0, 1);

	//Matrix3x3 mat3 = mat2 * 3.5f;
	Vector3D vec(8, 4, 16);
	double c = Math::tan(6);
	cout << c << endl;

	matrix3x3.RotateX(3);
	cout << matrix3x3[0] << " " << matrix3x3[1] << " " << matrix3x3[2] << " " << endl;
	cout << matrix3x3[3] << " " << matrix3x3[4] << " " << matrix3x3[5] << " " << endl;
	cout << matrix3x3[6] << " " << matrix3x3[7] << " " << matrix3x3[8] << " " << endl;
	/*
	mat1.Inverse();
	
	cout << mat1[0] << " " << mat1[1] << " " << mat1[2] << " " << endl;
	cout << mat1[3] << " " << mat1[4] << " " << mat1[5] << " " << endl;
	cout << mat1[6] << " " << mat1[7] << " " << mat1[8] << " " << endl;
	*/
	
	return 0;
}
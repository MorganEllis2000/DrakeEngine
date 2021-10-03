#include <iostream>
#include "Math.h"
#include "Vector3D.h"
#include "Vector2D.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

using namespace std;
using namespace Math;

int main() {
	Matrix3x3 matrix3x3;

    Matrix3x3 mat(3,5,4,6,7,9,3,4,5);
	Matrix4x4 mat2(5, 6, 4, 7, 9, 3, 5, 4, 7, 6, 7, 9, 1, 3, 4, 5);
	//Matrix4x4 mat2 = Matrix4x4::Matrix4x4();

	double det = mat.det3x3();
	cout << det << endl;

	cout << mat2[0] << " " << mat2[1] << " " << mat2[2] << " " << mat2[3] << endl;
	cout << mat2[4] << " " << mat2[5] << " " << mat2[6] << " " << mat2[7] << endl;
	cout << mat2[8] << " " << mat2[9] << " " << mat2[10] << " " << mat2[11] << endl;
	cout << mat2[12] << " " << mat2[13] << " " << mat2[14] << " " << mat2[15] << endl;

	mat2.Inverse();

	cout << mat2[0] << " " << mat2[1] << " " << mat2[2] << " " << mat2[3] << endl;
	cout << mat2[4] << " " << mat2[5] << " " << mat2[6] << " " << mat2[7] << endl;
	cout << mat2[8] << " " << mat2[9] << " " << mat2[10] << " " << mat2[11] << endl;
	cout << mat2[12] << " " << mat2[13] << " " << mat2[14] << " " << mat2[15] << endl;
	
	
	return 0;
}


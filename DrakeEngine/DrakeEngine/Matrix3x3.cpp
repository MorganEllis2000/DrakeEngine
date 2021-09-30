#include "Matrix3x3.h"
#include "Math.h"
using namespace Math;

#pragma region Getters and Setters

const Vector3D Matrix3x3::GetRow(const int a_irowNumber) const {
	Vector3D row;

	if (a_irowNumber == 0) {
		row.x = m_matrixValues[0];
		row.y = m_matrixValues[1];
		row.z = m_matrixValues[2];
	} else if (a_irowNumber == 1) {
		row.x = m_matrixValues[3];
		row.y = m_matrixValues[4];
		row.z = m_matrixValues[5];
	} else if (a_irowNumber == 2) {
		row.x = m_matrixValues[6];
		row.y = m_matrixValues[7];
		row.z = m_matrixValues[8];
	}
	
	return row;
}

void Matrix3x3::SetRow(const int a_irowNumber, const Vector3D& a_rowValues) {
	if (a_irowNumber == 0) {
		m_matrixValues[0] = a_rowValues.x;
		m_matrixValues[1] = a_rowValues.y;
		m_matrixValues[2] = a_rowValues.z;
	}else if (a_irowNumber == 1) {
		m_matrixValues[3] = a_rowValues.x;
		m_matrixValues[4] = a_rowValues.y;
		m_matrixValues[5] = a_rowValues.z;
	}else if (a_irowNumber == 2) {
		m_matrixValues[6] = a_rowValues.x;
		m_matrixValues[7] = a_rowValues.y;
		m_matrixValues[8] = a_rowValues.z;
	}
}
#pragma endregion


#pragma region Rotations

const bool Matrix3x3::isRotationMatrix(const Matrix3x3 a_matrix) const {
	Matrix3x3 mat = a_matrix;
	double epsilon = 0.01f; // margin to allow for rounding errors
	if (abs((a_matrix[0] * a_matrix[1] + a_matrix[1] * a_matrix[4] + a_matrix[2] * a_matrix[5])) > epsilon) {
		return false;
	}
	if (abs((a_matrix[0] * a_matrix[6] + a_matrix[1] * a_matrix[7] + a_matrix[2] * a_matrix[8])) > epsilon) {
		return false;
	}
	if (abs((a_matrix[3] * a_matrix[6] + a_matrix[4] * a_matrix[7] + a_matrix[5] * a_matrix[8])) > epsilon) {
		return false;
	}
	if (abs((a_matrix[0] * a_matrix[0] + a_matrix[1] * a_matrix[1] + a_matrix[2] * a_matrix[2])) > epsilon) {
		return false;
	}
	if (abs((a_matrix[3] * a_matrix[3] + a_matrix[4] * a_matrix[4] + a_matrix[5] * a_matrix[5])) > epsilon) {
		return false;
	}
	if (abs((a_matrix[6] * a_matrix[6] + a_matrix[7] * a_matrix[7] + a_matrix[8] * a_matrix[8])) > epsilon) {
		return false;
	}
	double det = mat.det3x3();

	return abs(det - 1) < epsilon;
}

const Matrix3x3 Matrix3x3::RotateX(double a_ftheta) {
	double c = cos(a_ftheta);
	double s = sin(a_ftheta);
	this->m_matrixValues[0] = 1;		this->m_matrixValues[1] = 0;			this->m_matrixValues[2] = 0;
	this->m_matrixValues[3] = 0;		this->m_matrixValues[4] = c;			this->m_matrixValues[5] = -s;
	this->m_matrixValues[6] = 0;		this->m_matrixValues[7] = s;			this->m_matrixValues[8] = c;

	return *this;
}

const Matrix3x3 Matrix3x3::RotateY(double a_ftheta) {
	double c = cos(a_ftheta);
	double s = sin(a_ftheta);
	this->m_matrixValues[0] = c;		this->m_matrixValues[1] = 0;			this->m_matrixValues[2] = s;
	this->m_matrixValues[3] = 0;		this->m_matrixValues[4] = 1;			this->m_matrixValues[5] = 0;
	this->m_matrixValues[6] = -s;		this->m_matrixValues[7] = 0;			this->m_matrixValues[8] = c;

	return *this;
}

const Matrix3x3 Matrix3x3::RotateZ(double a_ftheta) {
	double c = cos(a_ftheta);
	double s = sin(a_ftheta);
	this->m_matrixValues[0] = c;		this->m_matrixValues[1] = -s;			this->m_matrixValues[2] = 0;
	this->m_matrixValues[3] = s;		this->m_matrixValues[4] = c;			this->m_matrixValues[5] = 0;
	this->m_matrixValues[6] = 0;		this->m_matrixValues[7] = 0;			this->m_matrixValues[8] = 1;

	return *this;
}
#pragma endregion


#pragma region Matrix Operations

const Matrix3x3 Matrix3x3::Identity() {

	for (int i = 0; i < 9; i++) {
		if (i % 4 == 0) {
			this->m_matrixValues[i] = 1.f;
		}
		else {
			this->m_matrixValues[i] = 0.f;
		}
	}
	return *this;
}

/*
	Find the determinant of the a square matrix, doing so gives a scalar value that allows
	characterisation of some properties of the matrix and the linear map of the matrix.

	For 3x3 matrixes:
	 ______________________________
	|         |         |         |
	|    A    |    B    |    C    |		 ___________________	  ___________________	   ___________________
	| _______ | _______ |________ |		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|    E    |    F    |	 |    D    |    F    |	  |    D    |    E    |
	|    D    |    E    |    F    | = A	| _______ | _______ | - B| _______ | _______ | + C| _______ | _______ | = A(EI - FH) - B(DI - FG) + C(DH - EG)
	|_________|_________|_________|		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|    H    |    I    |	 |    G    |    I    |	  |    G    |    H    |
	|    G    |    H    |    I    |		|_________|_________|	 |_________|_________|	  |_________|_________|
	|_________|_________|_________|

	 ______________________________
	|         |         |         |
	|    3    |   -4    |   -5    |		 ___________________	  ___________________	   ___________________
	| _______ | _______ |________ |		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|   -7    |    8    |	 |    7    |    8    |	  |    7    |   -7    |
	|    7    |   -7    |    8    | = A	| _______ | _______ | - B| _______ | _______ | + C| _______ | _______ | =
	|_________|_________|_________|		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|   -7    |   -8    |	 |    5    |   -8    |	  |    5    |   -7    |
	|    5    |   -7    |   -8    |		|_________|_________|	 |_________|_________|	  |_________|_________|
	|_________|_________|_________|

	= 3 * ((-7 * -8) - (8 * -7)) - -4 * ((7 * -8) - (8 * 5)) + -5 * ((7 * -7) - (-7 * 5))
	= (3 * 112) - (-4 * -96) + (-5 * -14)
	= 336 - 384 + 70
	= 22
*/
double Matrix3x3::det3x3() {
	double detA = m_matrixValues[0] * ((m_matrixValues[4] * m_matrixValues[8]) - (m_matrixValues[5] * m_matrixValues[7]));
	double detB = m_matrixValues[1] * ((m_matrixValues[3] * m_matrixValues[8]) - (m_matrixValues[5] * m_matrixValues[6]));
	double detC = m_matrixValues[2] * ((m_matrixValues[3] * m_matrixValues[7]) - (m_matrixValues[4] * m_matrixValues[6]));
	return detA - detB + detC;
}

/*
We transpose matrixes as the often give use the another matrix to extrapolate data from. For example a rotation matrix can be transposed to give use the inverse rotation matrix

To transpose a matrix we swap values over the diagonals but the diagonal always stays the same

|---------------|		|---------------|
|	A	B	C	|		|	A	D	G	|
|	D	E	F	| --->  |	B	E	H	|
|	G	H	I	|		|	C	F	I	|
|---------------|		|---------------|

*/
void Matrix3x3::Transpose() {
	Matrix3x3 mat;

	for (int i = 0; i < 9; ++i) {
		mat.m_matrixValues[i] = this->m_matrixValues[i];
	}

	this->m_matrixValues[0] = mat.m_matrixValues[0];
	this->m_matrixValues[1] = mat.m_matrixValues[3];
	this->m_matrixValues[2] = mat.m_matrixValues[6];
	this->m_matrixValues[3] = mat.m_matrixValues[1];
	this->m_matrixValues[4] = mat.m_matrixValues[4];
	this->m_matrixValues[5] = mat.m_matrixValues[7];
	this->m_matrixValues[6] = mat.m_matrixValues[2];
	this->m_matrixValues[7] = mat.m_matrixValues[5];
	this->m_matrixValues[8] = mat.m_matrixValues[8];
}

/*
3, 0, 2		a, b, c		0, 1, 2
2, 0, -2	d, e, f		3, 4, 5
0, 1, 1		g, h, i		6, 7, 8

To calculate the matrix of minors you calculate the value of each value in the matrix using the following method

When you want to calculate the value you do not use any values that are in the row or column you are currently calulating. For example:

To caculate the first value of the matrix we do this

|---------------|		|---------------|
|	A	B	C	|		|	|---------- |
|	D	E	F	| --->  |	|	E	F	| ---> because we want to caluate the value of A we cant use any of the rows or columns that have A in it, which leaves use with
|	G	H	I	|		|	|	H	I	|      E,F,H,I. From this point we do the equatiion (E * I) - (F * H). We repeat this pattern for each element of the array. Below
|---------------|		|---------------|	   is the full exmaple of which grid corrisponds for each element of the array

		|---------------|		|---------------|		|---------------|		|---------------|
		|	|---------- |		|	---------	|		|	--------|	|		|	|	B	C	|
  A-->	|	|	E	F	|  B-->	|	D	|	F	|  C-->	|	D	E	|	| D-->	|	|---------	|
		|	|	H	I	|		|	G	|	I	|		|	G	H	|	|		|	|	H	I	|
		|---------------|		|---------------|		|---------------|		|---------------|

		|---------------|		|---------------|		|---------------|		|---------------|		|---------------|
		|	A	|	C	|		|	A	B	|	|		|	|	B	C	|		|	A	|	C	|		|	A	B	|	|
  E-->	|	----|----	|  F-->	|	--------|	|  G-->	|	|	E	F	|  H-->	|	D	|	F	|  I-->	|	D	E	|	|
		|	G	|	I	|		|	G	H	|	|		|	|--------	|		|	----|----	|		|	---------	|
		|---------------|		|---------------|		|---------------|		|---------------|		|---------------|


To calculate the matrix of cofactors we just make a 3x3 grid that alteranates signs on each value, the first value is always +, the second -, third +, etc.

|---------------|
|	+	-	+	|
|	-	+	-	|
|	+	-	+	|
|---------------|
*/
void Matrix3x3::Inverse() {
	Matrix3x3 mat;
	double det = this->det3x3(); // We need the original determinant of the matrix as its used to multiply our final matrix by 1/det
	for (int i = 0; i < 9; ++i) {
		mat.m_matrixValues[i] = this->m_matrixValues[i];
	}
	// Matrix of Minors

	this->m_matrixValues[0] = ((mat[4] * mat[8]) - (mat[5] * mat[7]));
	this->m_matrixValues[1] = ((mat[3] * mat[8]) - (mat[5] * mat[6]));
	this->m_matrixValues[2] = ((mat[3] * mat[7]) - (mat[4] * mat[6]));
	this->m_matrixValues[3] = ((mat[1] * mat[8]) - (mat[2] * mat[7]));
	this->m_matrixValues[4] = ((mat[0] * mat[8]) - (mat[2] * mat[6]));
	this->m_matrixValues[5] = ((mat[0] * mat[7]) - (mat[1] * mat[6]));
	this->m_matrixValues[6] = ((mat[1] * mat[5]) - (mat[2] * mat[4]));
	this->m_matrixValues[7] = ((mat[0] * mat[5]) - (mat[2] * mat[3]));
	this->m_matrixValues[8] = ((mat[0] * mat[4]) - (mat[1] * mat[3]));

	// Matrix of Cofactors
	this->m_matrixValues[0] = +this->m_matrixValues[0];
	this->m_matrixValues[1] = -this->m_matrixValues[1];
	this->m_matrixValues[2] = +this->m_matrixValues[2];
	this->m_matrixValues[3] = -this->m_matrixValues[3];
	this->m_matrixValues[4] = +this->m_matrixValues[4];
	this->m_matrixValues[5] = -this->m_matrixValues[5];
	this->m_matrixValues[6] = +this->m_matrixValues[6];
	this->m_matrixValues[7] = -this->m_matrixValues[7];
	this->m_matrixValues[8] = +this->m_matrixValues[8];

	this->Transpose();


	for (int i = 0; i < 9; ++i) {
		this->m_matrixValues[i] *= (1.f / det);
	}
}

#pragma endregion


#pragma region Overload Operations

const Matrix3x3 Matrix3x3::operator+(const Matrix3x3& a_rhs) const {
	Matrix3x3 sum;

	for (int i = 0; i < 9; ++i) {
		sum.m_matrixValues[i] = this->m_matrixValues[i] + a_rhs.m_matrixValues[i];
	}

	return sum;
}
Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& a_rhs)
{
	for (int i = 0; i < 9; ++i) {
		this->m_matrixValues[i] += a_rhs[i];
	}

	return *this;
}

const Matrix3x3 Matrix3x3::operator-(const Matrix3x3& a_rhs) const {
	Matrix3x3 dif;

	for (int i = 0; i < 9; ++i) {
		dif.m_matrixValues[i] = this->m_matrixValues[i] - a_rhs.m_matrixValues[i];
	}

	return dif;
}
Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& a_rhs)
{
	for (int i = 0; i < 9; ++i) {
		this->m_matrixValues[i] -= a_rhs[i];
	}

	return *this;
}

const Matrix3x3 Matrix3x3::operator*(const Matrix3x3& a_rhs) const {
	Matrix3x3 mul;

	for (int i = 0; i < 9; ++i) {
		mul.m_matrixValues[i] = this->m_matrixValues[i] * a_rhs.m_matrixValues[i];
	}

	return mul;
}
Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& a_rhs) {
	for (int i = 0; i < 9; ++i) {
		this->m_matrixValues[i] *= a_rhs[i];
	}

	return *this;
}

const Matrix3x3 Matrix3x3::operator*(const double& a_rhs) const {
	Matrix3x3 mul;

	for (int i = 0; i < 9; ++i) {
		mul.m_matrixValues[i] = this->m_matrixValues[i] * a_rhs;
	}

	return mul;
}
Matrix3x3& Matrix3x3::operator*=(const double& a_rhs) {
	for (int i = 0; i < 9; ++i) {
		this->m_matrixValues[i] *= a_rhs;
	}

	return *this;
}

const bool Matrix3x3::operator==(const Matrix3x3& a_rhs) const {
	for (int i = 0; i < 9; ++i) {
		if (this->m_matrixValues[i] == a_rhs.m_matrixValues[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}

const bool Matrix3x3::operator!=(const Matrix3x3& a_rhs) const {
	for (int i = 0; i < 9; ++i) {
		if (this->m_matrixValues[i] != a_rhs.m_matrixValues[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}

const double Matrix3x3::operator[](const int i) const {
	if (i == 0) {
		return m_matrixValues[0];
	}
	else if (i == 1) {
		return m_matrixValues[1];
	}
	else if (i == 2) {
		return m_matrixValues[2];
	}
	else if (i == 3) {
		return m_matrixValues[3];
	}
	else if (i == 4) {
		return m_matrixValues[4];
	}
	else if (i == 5) {
		return m_matrixValues[5];
	}
	else if (i == 6) {
		return m_matrixValues[6];
	}
	else if (i == 7) {
		return m_matrixValues[7];
	}
	else if (i == 8) {
		return m_matrixValues[8];
	}
	else {
		return 0;
	}
}

#pragma endregion


#pragma region Constructors & Destructors

Matrix3x3::Matrix3x3() {

}

Matrix3x3::Matrix3x3(const double a_fm11, const double a_fm12, const double a_fm13,
	const double a_fm21, const double a_fm22, const double a_fm23,
	const double a_fm31, const double a_fm32, const double a_fm33) {
	m_matrixValues[0] = a_fm11; m_matrixValues[1] = a_fm12; m_matrixValues[2] = a_fm13;
	m_matrixValues[3] = a_fm21; m_matrixValues[4] = a_fm22; m_matrixValues[5] = a_fm23;
	m_matrixValues[6] = a_fm31; m_matrixValues[7] = a_fm32; m_matrixValues[8] = a_fm33;
}

Matrix3x3::Matrix3x3(const double* a_fpm33Values) {
	for (int i = 0; i < 9; ++i) {
		m_matrixValues[i] = a_fpm33Values[i];
	}
}

Matrix3x3::~Matrix3x3() {

}

#pragma endregion


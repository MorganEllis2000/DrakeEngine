#include "../Header/Matrix4x4.h"
#include "../Header/Math.h"
using namespace Math;

#pragma region Getters and Setters
/*
const Vector3D Matrix4x4::GetRow(const int a_irowNumber) const {
	Vector3D row;

	if (a_irowNumber == 0) {
		row.x = m_matrixValues[0];
		row.y = m_matrixValues[1];
		row.z = m_matrixValues[2];
	}
	else if (a_irowNumber == 1) {
		row.x = m_matrixValues[3];
		row.y = m_matrixValues[4];
		row.z = m_matrixValues[5];
	}
	else if (a_irowNumber == 2) {
		row.x = m_matrixValues[6];
		row.y = m_matrixValues[7];
		row.z = m_matrixValues[8];
	}
	else if (a_irowNumber == 3) {
		row.x = m_matrixValues[6];
		row.y = m_matrixValues[7];
		row.z = m_matrixValues[8];
	}

	return row;
}

void Matrix4x4::SetRow(const int a_irowNumber, const Vector3D& a_rowValues) {
	if (a_irowNumber == 0) {
		m_matrixValues[0] = a_rowValues.x;
		m_matrixValues[1] = a_rowValues.y;
		m_matrixValues[2] = a_rowValues.z;
	}
	else if (a_irowNumber == 1) {
		m_matrixValues[3] = a_rowValues.x;
		m_matrixValues[4] = a_rowValues.y;
		m_matrixValues[5] = a_rowValues.z;
	}
	else if (a_irowNumber == 2) {
		m_matrixValues[6] = a_rowValues.x;
		m_matrixValues[7] = a_rowValues.y;
		m_matrixValues[8] = a_rowValues.z;
	}
}
#pragma endregion
*/

#pragma region Rotations

const Matrix4x4 Matrix4x4::RotateX(double a_ftheta) {
	double c = Math::cos(a_ftheta);
	double s = Math::sin(a_ftheta);
	this->m_matrixValues[0] = 1;		this->m_matrixValues[1] = 0;			this->m_matrixValues[2] = 0;
	this->m_matrixValues[3] = 0;		this->m_matrixValues[4] = c;			this->m_matrixValues[5] = -s;
	this->m_matrixValues[6] = 0;		this->m_matrixValues[7] = s;			this->m_matrixValues[8] = c;

	return *this;
}

const Matrix4x4 Matrix4x4::RotateY(double a_ftheta) {
	double c = Math::cos(a_ftheta);
	double s = Math::sin(a_ftheta);
	this->m_matrixValues[0] = c;		this->m_matrixValues[1] = 0;			this->m_matrixValues[2] = s;
	this->m_matrixValues[3] = 0;		this->m_matrixValues[4] = 1;			this->m_matrixValues[5] = 0;
	this->m_matrixValues[6] = -s;		this->m_matrixValues[7] = 0;			this->m_matrixValues[8] = c;

	return *this;
}

const Matrix4x4 Matrix4x4::RotateZ(double a_ftheta) {
	double c = Math::cos(a_ftheta);
	double s = Math::sin(a_ftheta);
	this->m_matrixValues[0] = c;		this->m_matrixValues[1] = -s;			this->m_matrixValues[2] = 0;
	this->m_matrixValues[3] = s;		this->m_matrixValues[4] = c;			this->m_matrixValues[5] = 0;
	this->m_matrixValues[6] = 0;		this->m_matrixValues[7] = 0;			this->m_matrixValues[8] = 1;

	return *this;
}
#pragma endregion


#pragma region Matrix Operations

const Matrix4x4 Matrix4x4::Identity() {

	for (int i = 0; i < 16; i++) {
		if (i % 5 == 0) {
			this->m_matrixValues[i] = 1.f;
		}
		else {
			this->m_matrixValues[i] = 0.f;
		}
	}
	return *this;
}

/*
For 4x4 matrixes:
	 ________________________________________
	|         |         |         |         |    ________  _________ _________		 ________  _________ _________	     ________  _________ _________       ________  ________  _________
	|    A    |    B    |    C    |    D    |   |         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	| _______ | _______ |________ |________ |	|    F    |    G    |    H    |		|    E    |    G    |    H    |		|    E    |    F    |    H    |		|    E    |    F    |    G    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    E    |    F    |    G    |    H    |  	|         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	|_________|_________|_________|_________|= A|    J    |    K    |    L    |	- B	|    I    |    K    |    L    | + C	|    I    |    J    |    L    | - D	|    I    |    J    |    K    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    I    |    J    |    K    |    L    |	|         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	|_________|_________|_________|_________|	|    N    |    O    |    P    |		|    M    |    O    |    P    |		|    M    |    N    |    P    |		|    M    |    N    |    O    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    M    |    N    |    O    |    P    |
	|_________|_________|_________|_________|

	= A(FKP - FLO - GJP + GLN + HJO - HKN) - B(EKP - ELO - GIP + GLM + HIO - HKM) + C(EJP - ELN - FIP + FLM + HIN - HJM) + D(EJO - EKN - FIO + FKM + GIN - GJM)

	 ________________________________________
	|         |         |         |         |    ________  _________ _________		 ________  _________ _________	     ________  _________ _________       ________  ________  _________
	|    5    |    7    |    9    |    4    |   |         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	| _______ | _______ |________ |________ |	|    5    |    8    |    4    |		|    3    |    8    |    4    |		|    3    |    5    |    4    |		|    3    |    5    |    8    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    3    |    5    |    8    |    4    |  	|         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	|_________|_________|_________|_________|= 5|    3    |    8    |    4    |	- 7	|    1    |    8    |    4    | + 9	|    1    |    3    |    4    | - 4	|    1    |    3    |    8    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    1    |    3    |    8    |    4    |	|         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	|_________|_________|_________|_________|	|    7    |    1    |    3    |		|    3    |    1    |    3    |		|    3    |    7    |    3    |		|    3    |    7    |    1    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    3    |    7    |    1    |    3    |
	|_________|_________|_________|_________|


	= 5 * ( (5*8*3) - (5*4*1) - (8*3*3) + (8*4*7) + (4*3*1) - (4*8*7) ) -
	 -7 * ( (3*8*3) - (3*4*1) - (8*1*3) + (8*4*3) + (4*1*1) - (4*8*3) ) +
	  9 * ( (3*3*3) - (3*4*7) - (5*1*3) + (5*4*3) + (4*1*7) - (4*3*3) ) -
	 -4 * ( (3*3*1) - (3*8*7) - (5*1*1) + (5*8*3) + (8*1*7) - (8*3*3) )

	= 5 * ( 120 - 20 - 72 + 224 + 12 - 224 ) -
	 -7 * ( 72 - 12 - 24 + 96 + 4 - 96) +
	  9 * ( 27 - 84 - 15 + 60 + 28 - 36) -
	 -4 * ( 9 - 168 - 5 + 120 + 56 - 72)

	= -20
*/
double Matrix4x4::det4x4() {
	double detA = m_matrixValues[0] * ((m_matrixValues[5] * m_matrixValues[10] * m_matrixValues[15]) - (m_matrixValues[5] * m_matrixValues[11] * m_matrixValues[14]) - (m_matrixValues[6] * m_matrixValues[9] * m_matrixValues[15]) + (m_matrixValues[6] * m_matrixValues[11] * m_matrixValues[13]) +
					   (m_matrixValues[7] * m_matrixValues[9] * m_matrixValues[14]) - (m_matrixValues[7] * m_matrixValues[10] * m_matrixValues[13]));
	double detB = m_matrixValues[1] * ((m_matrixValues[4] * m_matrixValues[10] * m_matrixValues[15]) - (m_matrixValues[4] * m_matrixValues[11] * m_matrixValues[14]) - (m_matrixValues[6] * m_matrixValues[8] * m_matrixValues[15]) + (m_matrixValues[6] * m_matrixValues[11] * m_matrixValues[12]) +
					   (m_matrixValues[7] * m_matrixValues[8] * m_matrixValues[14]) - (m_matrixValues[7] * m_matrixValues[10] * m_matrixValues[12]));
	double detC = m_matrixValues[2] * ((m_matrixValues[4] * m_matrixValues[9] * m_matrixValues[15]) - (m_matrixValues[4] * m_matrixValues[11] * m_matrixValues[13]) - (m_matrixValues[5] * m_matrixValues[8] * m_matrixValues[15]) + (m_matrixValues[5] * m_matrixValues[11] * m_matrixValues[12]) +
					   (m_matrixValues[7] * m_matrixValues[8] * m_matrixValues[13]) - (m_matrixValues[7] * m_matrixValues[9] * m_matrixValues[12]));
	double detD = m_matrixValues[3] * ((m_matrixValues[4] * m_matrixValues[9] * m_matrixValues[14]) - (m_matrixValues[4] * m_matrixValues[10] * m_matrixValues[13]) - (m_matrixValues[5] * m_matrixValues[8] * m_matrixValues[14]) + (m_matrixValues[5] * m_matrixValues[10] * m_matrixValues[12]) +
					   (m_matrixValues[6] * m_matrixValues[8] * m_matrixValues[13]) - (m_matrixValues[6] * m_matrixValues[9] * m_matrixValues[12]));
	return detA - detB + detC - detD;
}

/*
We transpose matrixes as the often gives us another matrix to extrapolate data from. For example a rotation matrix can be transposed to give use the inverse rotation matrix

To transpose a matrix we swap values over the diagonals but the diagonal always stays the same

|---------------|		|---------------|
|	A	B	C	|		|	A	D	G	|
|	D	E	F	| --->  |	B	E	H	|
|	G	H	I	|		|	C	F	I	|
|---------------|		|---------------|

*/
void Matrix4x4::Transpose() {
	Matrix4x4 mat;

	for (int i = 0; i < 16; ++i) {
		mat.m_matrixValues[i] = this->m_matrixValues[i];
	}

	this->m_matrixValues[0]  = mat.m_matrixValues[0];
	this->m_matrixValues[1]  = mat.m_matrixValues[4];
	this->m_matrixValues[2]  = mat.m_matrixValues[8];
	this->m_matrixValues[3]  = mat.m_matrixValues[12];
	this->m_matrixValues[4]  = mat.m_matrixValues[1];
	this->m_matrixValues[5]  = mat.m_matrixValues[5];
	this->m_matrixValues[6]  = mat.m_matrixValues[9];
	this->m_matrixValues[7]  = mat.m_matrixValues[13];
	this->m_matrixValues[8]  = mat.m_matrixValues[2];
	this->m_matrixValues[9]  = mat.m_matrixValues[6];
	this->m_matrixValues[10] = mat.m_matrixValues[10];
	this->m_matrixValues[11] = mat.m_matrixValues[14];
	this->m_matrixValues[12] = mat.m_matrixValues[3];
	this->m_matrixValues[13] = mat.m_matrixValues[7];
	this->m_matrixValues[14] = mat.m_matrixValues[11];
	this->m_matrixValues[15] = mat.m_matrixValues[15];
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
void Matrix4x4::Inverse() {
	Matrix4x4 mat;
	double det = this->det4x4(); // We need the original determinant of the matrix as its used to multiply our final matrix by 1/det
	for (int i = 0; i < 16; ++i) {
		mat.m_matrixValues[i] = this->m_matrixValues[i];
	}
	// Matrix of Minors

	this->m_matrixValues[0] = (-(mat[7] * mat[10] * mat[13]) + (mat[6] * mat[11] * mat[13]) + (mat[7] * mat[9] * mat[14]) - (mat[5] * mat[11] * mat[14]) - (mat[6] * mat[9] * mat[15]) + (mat[5] * mat[10] * mat[15]));
	this->m_matrixValues[1] = ( (mat[3] * mat[10] * mat[13]) - (mat[2] * mat[11] * mat[13]) - (mat[3] * mat[9] * mat[14]) + (mat[1] * mat[11] * mat[14]) + (mat[2] * mat[9] * mat[15]) - (mat[1] * mat[10] * mat[15]));
	this->m_matrixValues[2] = (-(mat[3] * mat[6]  * mat[13]) + (mat[2] * mat[7]  * mat[13]) + (mat[3] * mat[5] * mat[14]) - (mat[1] * mat[7]  * mat[14]) - (mat[2] * mat[5] * mat[15]) + (mat[1] * mat[6]  * mat[15]));
	this->m_matrixValues[3] = ( (mat[3] * mat[6]  * mat[9] ) - (mat[2] * mat[7]  * mat[9] ) - (mat[3] * mat[5] * mat[10]) + (mat[1] * mat[7]  * mat[10]) + (mat[2] * mat[5] * mat[11]) - (mat[1] * mat[6]  * mat[11]));

	this->m_matrixValues[4] = ( (mat[7] * mat[10] * mat[12]) - (mat[6] * mat[11] * mat[12]) - (mat[7] * mat[8] * mat[14]) + (mat[4] * mat[11] * mat[14]) + (mat[6] * mat[8] * mat[15]) - (mat[4] * mat[10] * mat[15]));
	this->m_matrixValues[5] = (-(mat[3] * mat[10] * mat[12]) + (mat[2] * mat[11] * mat[12]) + (mat[3] * mat[8] * mat[14]) - (mat[0] * mat[11] * mat[14]) - (mat[2] * mat[8] * mat[15]) + (mat[0] * mat[10] * mat[15]));
	this->m_matrixValues[6] = ( (mat[3] * mat[6]  * mat[12]) - (mat[2] * mat[7]  * mat[12]) - (mat[3] * mat[4] * mat[14]) + (mat[0] * mat[7]  * mat[14]) + (mat[2] * mat[4] * mat[15]) - (mat[0] * mat[6]  * mat[15]));
	this->m_matrixValues[7] = (-(mat[3] * mat[6]  * mat[8] ) + (mat[2] * mat[7]  * mat[8] ) + (mat[3] * mat[4] * mat[10]) - (mat[0] * mat[7]  * mat[10]) - (mat[2] * mat[4] * mat[11]) + (mat[0] * mat[6]  * mat[11]));

	this->m_matrixValues[8]  = (-(mat[7] * mat[9]  * mat[12]) + (mat[5] * mat[11] * mat[12]) + (mat[7] * mat[8] * mat[13]) - (mat[4] * mat[11] * mat[13]) - (mat[5] * mat[8] * mat[15]) + (mat[4] * mat[9] * mat[15]));
	this->m_matrixValues[9]  = ( (mat[3] * mat[9]  * mat[12]) - (mat[1] * mat[11] * mat[12]) - (mat[3] * mat[8] * mat[13]) + (mat[0] * mat[11] * mat[13]) + (mat[1] * mat[8] * mat[15]) - (mat[0] * mat[9] * mat[15]));
	this->m_matrixValues[10] = (-(mat[3] * mat[5]  * mat[12]) + (mat[1] * mat[7]  * mat[12]) + (mat[3] * mat[4] * mat[13]) - (mat[0] * mat[7]  * mat[13]) - (mat[1] * mat[4] * mat[15]) + (mat[0] * mat[5] * mat[15]));
	this->m_matrixValues[11] = ( (mat[3] * mat[5]  * mat[8] ) - (mat[1] * mat[7]  * mat[8] ) - (mat[3] * mat[4] * mat[9] ) + (mat[0] * mat[7]  * mat[9] ) + (mat[1] * mat[4] * mat[11]) - (mat[0] * mat[5] * mat[11]));

	this->m_matrixValues[12] = ( (mat[6] * mat[9]  * mat[12]) - (mat[5] * mat[10] * mat[12]) - (mat[6] * mat[8] * mat[13]) + (mat[4] * mat[10] * mat[13]) + (mat[5] * mat[8] * mat[14]) - (mat[4] * mat[9]  * mat[14]));
	this->m_matrixValues[13] = (-(mat[2] * mat[9]  * mat[12]) + (mat[1] * mat[10] * mat[12]) + (mat[2] * mat[8] * mat[13]) - (mat[0] * mat[10] * mat[13]) - (mat[1] * mat[8] * mat[14]) + (mat[0] * mat[9]  * mat[14]));
	this->m_matrixValues[14] = ( (mat[2] * mat[5]  * mat[12]) - (mat[1] * mat[6]  * mat[12]) - (mat[2] * mat[4] * mat[13]) + (mat[0] * mat[6]  * mat[13]) + (mat[1] * mat[4] * mat[14]) - (mat[0] * mat[5]  * mat[14]));
	this->m_matrixValues[15] = (-(mat[2] * mat[5]  * mat[8] ) + (mat[1] * mat[6]  * mat[8] ) + (mat[2] * mat[4] * mat[9] ) - (mat[0] * mat[6]  * mat[9] ) - (mat[1] * mat[4] * mat[10]) + (mat[0] * mat[5]  * mat[10]));

	/* Matrix of Cofactors
	this->m_matrixValues[0] = +this->m_matrixValues[0];
	this->m_matrixValues[1] = -this->m_matrixValues[1];
	this->m_matrixValues[2] = +this->m_matrixValues[2];
	this->m_matrixValues[3] = -this->m_matrixValues[3];
	this->m_matrixValues[4] = -this->m_matrixValues[4];
	this->m_matrixValues[5] = +this->m_matrixValues[5];
	this->m_matrixValues[6] = -this->m_matrixValues[6];
	this->m_matrixValues[7] = +this->m_matrixValues[7];
	this->m_matrixValues[8] = +this->m_matrixValues[8];
	this->m_matrixValues[9] = -this->m_matrixValues[9];
	this->m_matrixValues[10] = +this->m_matrixValues[10];
	this->m_matrixValues[11] = -this->m_matrixValues[11];
	this->m_matrixValues[12] = -this->m_matrixValues[12];
	this->m_matrixValues[13] = +this->m_matrixValues[13];
	this->m_matrixValues[14] = -this->m_matrixValues[14];
	this->m_matrixValues[15] = +this->m_matrixValues[15];

	this->Transpose();
	*/

	for (int i = 0; i < 16; ++i) {
		this->m_matrixValues[i] *= (1.f / det);
	}
}

#pragma endregion


#pragma region Overload Operations

const Matrix4x4 Matrix4x4::operator+(const Matrix4x4& a_rhs) const {
	Matrix4x4 sum;

	for (int i = 0; i < 16; ++i) {
		sum.m_matrixValues[i] = this->m_matrixValues[i] + a_rhs.m_matrixValues[i];
	}

	return sum;
}
Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& a_rhs)
{
	for (int i = 0; i < 16; ++i) {
		this->m_matrixValues[i] += a_rhs[i];
	}

	return *this;
}

const Matrix4x4 Matrix4x4::operator-(const Matrix4x4& a_rhs) const {
	Matrix4x4 dif;

	for (int i = 0; i < 16; ++i) {
		dif.m_matrixValues[i] = this->m_matrixValues[i] - a_rhs.m_matrixValues[i];
	}

	return dif;
}
Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& a_rhs)
{
	for (int i = 0; i < 16; ++i) {
		this->m_matrixValues[i] -= a_rhs[i];
	}

	return *this;
}

const Matrix4x4 Matrix4x4::operator*(const Matrix4x4& a_rhs) const {
	Matrix4x4 mul;

	for (int i = 0; i < 16; ++i) {
		mul.m_matrixValues[i] = this->m_matrixValues[i] * a_rhs.m_matrixValues[i];
	}

	return mul;
}
Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& a_rhs) {
	for (int i = 0; i < 16; ++i) {
		this->m_matrixValues[i] *= a_rhs[i];
	}

	return *this;
}

const Matrix4x4 Matrix4x4::operator*(const double& a_rhs) const {
	Matrix4x4 mul;

	for (int i = 0; i < 16; ++i) {
		mul.m_matrixValues[i] = this->m_matrixValues[i] * a_rhs;
	}

	return mul;
}
Matrix4x4& Matrix4x4::operator*=(const double& a_rhs) {
	for (int i = 0; i < 16; ++i) {
		this->m_matrixValues[i] *= a_rhs;
	}

	return *this;
}

const bool Matrix4x4::operator==(const Matrix4x4& a_rhs) const {
	for (int i = 0; i < 16; ++i) {
		if (this->m_matrixValues[i] == a_rhs.m_matrixValues[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}

const bool Matrix4x4::operator!=(const Matrix4x4& a_rhs) const {
	for (int i = 0; i < 16; ++i) {
		if (this->m_matrixValues[i] != a_rhs.m_matrixValues[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}

const double Matrix4x4::operator[](const int i) const {
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
	else if (i == 9) {
		return m_matrixValues[9];
	}
	else if (i == 10) {
		return m_matrixValues[10];
	}
	else if (i == 11) {
		return m_matrixValues[11];
	}
	else if (i == 12) {
		return m_matrixValues[12];
	}
	else if (i == 13) {
		return m_matrixValues[13];
	}
	else if (i == 14) {
		return m_matrixValues[14];
	}
	else if (i == 15) {
		return m_matrixValues[15];
	}
	else {
		return 0;
	}
}

#pragma endregion


#pragma region Constructors & Destructors

Matrix4x4::Matrix4x4() {
	for (int i = 0; i < 16; i++) {
		if (i % 5 == 0) {
			this->m_matrixValues[i] = 1.f;
		}
		else {
			this->m_matrixValues[i] = 0.f;
		}
	}
}

Matrix4x4::Matrix4x4(const Matrix4x4& a_other) {
	for (int i = 0; i < 16; ++i) {
		m_matrixValues[i] = a_other.m_matrixValues[i];
	}
}

Matrix4x4::Matrix4x4(
	const double a_fm11, const double a_fm12, const double a_fm13, const double a_fm14,
	const double a_fm21, const double a_fm22, const double a_fm23, const double a_fm24,
	const double a_fm31, const double a_fm32, const double a_fm33, const double a_fm34,
	const double a_fm41, const double a_fm42, const double a_fm43, const double a_fm44) {

	m_matrixValues[0]  = a_fm11;  m_matrixValues[1]  = a_fm12; m_matrixValues[2]  = a_fm13; m_matrixValues[3]  = a_fm14;
	m_matrixValues[4]  = a_fm21;  m_matrixValues[5]  = a_fm22; m_matrixValues[6]  = a_fm23; m_matrixValues[7]  = a_fm24;
	m_matrixValues[8]  = a_fm31;  m_matrixValues[9]  = a_fm32; m_matrixValues[10] = a_fm33; m_matrixValues[11] = a_fm34;
	m_matrixValues[12] = a_fm41; m_matrixValues[13]  = a_fm42; m_matrixValues[14] = a_fm43; m_matrixValues[15] = a_fm44;
}

Matrix4x4::Matrix4x4(float OGLMatrix[16]) {
	for (int i = 0; i < 16; ++i) {
		m_matrixValues[i] = OGLMatrix[i];
	}
}

Matrix4x4::Matrix4x4(double OGLMatrix[16]) {
	for (int i = 0; i < 16; ++i) {
		m_matrixValues[i] = OGLMatrix[i];
	}
}

Matrix4x4::Matrix4x4(const Matrix3x3& a_other) {
	m_matrixValues[0]  = a_other[0]; m_matrixValues[1]  = a_other[1]; m_matrixValues[2]  = 0; m_matrixValues[3]  = a_other[2];
	m_matrixValues[4]  = a_other[3]; m_matrixValues[5]  = a_other[4]; m_matrixValues[6]  = 0; m_matrixValues[7]  = a_other[5];
	m_matrixValues[8]  = 0;			 m_matrixValues[9]  = 0;		  m_matrixValues[10] = 1; m_matrixValues[11] = 0;
	m_matrixValues[12] = a_other[6]; m_matrixValues[13] = a_other[7]; m_matrixValues[14] = 0; m_matrixValues[15] = a_other[8];

}

Matrix4x4::Matrix4x4(const Matrix3x3& a_other, const Vector3D& a_vector) {
	m_matrixValues[0]  = a_other[0]; m_matrixValues[1]  = a_other[1]; m_matrixValues[2]  = a_other[2]; m_matrixValues[3]  = a_vector[0];
	m_matrixValues[4]  = a_other[3]; m_matrixValues[5]  = a_other[4]; m_matrixValues[6]  = a_other[5]; m_matrixValues[7]  = a_vector[1];
	m_matrixValues[8]  = a_other[6]; m_matrixValues[9]  = a_other[7]; m_matrixValues[10] = a_other[8]; m_matrixValues[11] = a_vector[2];
	m_matrixValues[12] = 0;			 m_matrixValues[13] = 0;		  m_matrixValues[14] = 0;		   m_matrixValues[15] = 1;
}

Matrix4x4::Matrix4x4(const double* a_fpm33Values) {
	for (int i = 0; i < 9; ++i) {
		m_matrixValues[i] = a_fpm33Values[i];
	}
}

Matrix4x4::~Matrix4x4() {

}

#pragma endregion

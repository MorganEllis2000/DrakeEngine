#ifndef __MATRIX3X3_H__
#define __MATRIX3X3_H__

#include "Vector3D.h"

class Matrix3x3
{
public:

#pragma region Getters and Setters

	const Vector3D GetRow(const int a_irowNumber) const;
	void SetRow(const int a_irowNumber, const Vector3D& a_rowValues);

#pragma endregion

#pragma region Rotations

	const bool isRotationMatrix(const Matrix3x3 a_matrix) const;
	const Matrix3x3 RotateX(double a_ftheta);
	const Matrix3x3 RotateY(double a_ftheta);
	const Matrix3x3 RotateZ(double a_ftheta);

#pragma endregion

#pragma region Matrix Operations

	const Matrix3x3 Identity();

	double det3x3();

	void Transpose();

	void Inverse();
#pragma endregion

#pragma region Overload Operations

	const Matrix3x3 operator+(const Matrix3x3& a_rhs) const;
	Matrix3x3& operator+=(const Matrix3x3& a_rhs);

	const Matrix3x3 operator-(const Matrix3x3& a_rhs) const;
	Matrix3x3& operator-=(const Matrix3x3& a_rhs);

	const Matrix3x3 operator*(const Matrix3x3& a_rhs) const;
	Matrix3x3& operator*=(const Matrix3x3& a_rhs);

	const Matrix3x3 operator*(const double& a_rhs) const;
	Matrix3x3& operator*=(const double& a_rhs);

	const bool operator==(const Matrix3x3& a_other) const;
	const bool operator!=(const Matrix3x3& a_other) const;

	const double operator[](const int i) const;

#pragma endregion

#pragma region Constructors and Destructors

	Matrix3x3();
	Matrix3x3(const double a_fm11, const double a_fm12, const double a_fm13,
		const double a_fm21, const double a_fm22, const double a_fm23,
		const double a_fm31, const double a_fm32, const double a_fm33);
	Matrix3x3(const double* a_fpm33Values);

	~Matrix3x3();

#pragma endregion


private:
	static const int cols = 3;
	static const int rows = 3;
	double m_matrixValues[9];
};

#endif // __MATRIX3X3_H__
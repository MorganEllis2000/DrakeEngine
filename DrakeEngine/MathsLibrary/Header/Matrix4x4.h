#ifndef __MATRIX4X4_H__
#define __MATRIX4X4_H__

#include "Vector3D.h"
#include "Matrix3x3.h"

class Matrix4x4
{
public:

#pragma region Getters and Setters

	const Vector3D GetRow(const int a_irowNumber) const;
	void SetRow(const int a_irowNumber, const Vector3D& a_rowValues);

#pragma endregion

#pragma region Rotations

	const bool isRotationMatrix(const Matrix4x4 a_matrix) const;
	const Matrix4x4 RotateX(double a_ftheta);
	const Matrix4x4 RotateY(double a_ftheta);
	const Matrix4x4 RotateZ(double a_ftheta);

#pragma endregion

#pragma region Matrix Operations

	const Matrix4x4 Identity();

	double det4x4();

	void Transpose();

	void Inverse();
#pragma endregion

#pragma region Overload Operations

	const Matrix4x4 operator+(const Matrix4x4& a_rhs) const;
	Matrix4x4& operator+=(const Matrix4x4& a_rhs);

	const Matrix4x4 operator-(const Matrix4x4& a_rhs) const;
	Matrix4x4& operator-=(const Matrix4x4& a_rhs);

	const Matrix4x4 operator*(const Matrix4x4& a_rhs) const;
	Matrix4x4& operator*=(const Matrix4x4& a_rhs);

	const Matrix4x4 operator*(const double& a_rhs) const;
	Matrix4x4& operator*=(const double& a_rhs);

	const bool operator==(const Matrix4x4& a_other) const;
	const bool operator!=(const Matrix4x4& a_other) const;

	const double operator[](const int i) const;

#pragma endregion

#pragma region Constructors and Destructors

	Matrix4x4();
	Matrix4x4(const Matrix4x4& a_other);
	Matrix4x4(	const double a_fm11, const double a_fm12, const double a_fm13, const double a_fm14,
				const double a_fm21, const double a_fm22, const double a_fm23, const double a_fm24,
				const double a_fm31, const double a_fm32, const double a_fm33, const double a_fm34,
				const double a_fm41, const double a_fm42, const double a_fm43, const double a_fm44);

	//Builds a matrix from the specified matrix elements.They are asssumed to be stored in row - major order.
	Matrix4x4(float OGLMatrix[16]);
	Matrix4x4(double OGLMatrix[16]);
	// Allows for 2d transformations as it interpurts that the matrix a_other is a 2D transformation operating on 2D points in embedded space
	// This sees the third row and column being swapped with the forth and the third column becomes that of a 4x4 indentity matrix.
	Matrix4x4(const Matrix3x3& a_other);
	Matrix4x4(const Matrix3x3& a_other, const Vector3D& a_vector);
	Matrix4x4(const Vector3D& a_vector);
	Matrix4x4(const double* a_fpm33Values);

	~Matrix4x4();

#pragma endregion


private:
	static const int cols = 4;
	static const int rows = 4;
	double m_matrixValues[16];
};

#endif // __Matrix4x4_H__

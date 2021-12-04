#ifndef __VECTOR4D_H__
#define __VECTOR4D_H__

#include "Matrix4x4.h"

class Vector4D
{
public:
#pragma region Constructors
	Vector4D();
	Vector4D(double a_x, double a_y, double a_z, double a_w);
	Vector4D(const Vector4D& a_vector);
	~Vector4D();
#pragma endregion

#pragma region Operator Overloads
	Vector4D& operator= (const Vector4D& rhs); 

	const Vector4D operator+(const Vector4D& rhs) const;
	Vector4D& operator+=(const Vector4D& rhs);

	const Vector4D operator-(const Vector4D& rhs) const;
	Vector4D& operator-=(const Vector4D& rhs);

	const Vector4D operator*(const float& rhs) const;
	Vector4D& operator*=(const float& rhs);

	const Vector4D operator*(const Vector4D& rhs) const;
	Vector4D& operator*=(const Vector4D& rhs);

	const Vector4D operator*(const Matrix4x4& rhs) const;

	const Vector4D operator/(const float& rhs) const;
	Vector4D& operator/=(const float& rhs);

	const Vector4D operator/(const Vector4D& rhs) const;
	Vector4D& operator/=(const Vector4D& rhs);

	const float operator[](const int i) const;

	const bool operator==(const Vector4D& rhs) const;
	const bool operator!=(const Vector4D& rhs) const;
#pragma endregion

#pragma region Math Operations
	const Vector4D add(const Vector4D& a_vector, const Vector4D& a_vector2) const;
	const Vector4D add(const Vector4D& a_vector, const float& a_float) const;

	const Vector4D subtract(const Vector4D& a_vector, const Vector4D& a_vector2) const;
	const Vector4D subtract(const Vector4D& a_vector, const float& a_float) const;

	const Vector4D multiply(const Vector4D& a_vector, const Vector4D& a_vector2) const;
	const Vector4D multiply(const Vector4D& a_vector, const float& a_float) const;

	const Vector4D divide(const Vector4D& a_vector, const Vector4D& a_vector2) const;
	const Vector4D divide(const Vector4D& a_vector, const float& a_float) const;
#pragma endregion

	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const Vector4D& a_vector) const;
	const float distanceSq(const Vector4D& a_vector) const;

	const float dotProduct(const Vector4D& a_vector, const Vector4D& a_vector2) const;
	const Vector4D crossProduct(const Vector4D& a_vector, const Vector4D& a_vector2) const;

	const Vector4D normalise() const;

	const float* GetPointer() const;

private:
	float m_coordinates[4];
};

#endif // __VECTOR4D_H__
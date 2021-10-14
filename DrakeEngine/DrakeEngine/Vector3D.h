#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

class Vector3D
{
public:

	float x;
	float y;
	float z;

#pragma region Constructors
	Vector3D();
	Vector3D(float a_x, float a_y, float a_z);
	Vector3D(const Vector3D& v);
	~Vector3D();
#pragma endregion
	
#pragma region Overload Operations

	Vector3D& operator= (const Vector3D& rhs); // Set two vectors equal to eachother

	const Vector3D operator+(const Vector3D& rhs) const;
	Vector3D& operator+=(const Vector3D& rhs);

	const Vector3D operator-(const Vector3D& rhs) const;
	Vector3D& operator-=(const Vector3D& rhs);

	const Vector3D operator*(const float& rhs) const;
	Vector3D& operator*=(const float& rhs);

	const Vector3D operator*(const Vector3D& rhs) const;
	Vector3D& operator*=(const Vector3D& rhs);

	const Vector3D operator/(const float& rhs) const;
	Vector3D& operator/=(const float& rhs);

	const Vector3D operator/(const Vector3D& rhs) const;
	Vector3D& operator/=(const Vector3D& rhs);

	const float operator[](const int i) const;

	const bool operator==(const Vector3D& rhs) const;
	const bool operator!=(const Vector3D& rhs) const;

#pragma endregion

#pragma region Math Operations

	const Vector3D add(const Vector3D& a_vector, const Vector3D& a_vector2) const;
	const Vector3D add(const Vector3D& a_vector, const float& a_float) const;

	const Vector3D subtract(const Vector3D& a_vector, const Vector3D& a_vector2) const;
	const Vector3D subtract(const Vector3D& a_vector, const float& a_float) const;

	const Vector3D multiply(const Vector3D& a_vector, const Vector3D& a_vector2) const;
	const Vector3D multiply(const Vector3D& a_vector, const float& a_float) const;

	const Vector3D divide(const Vector3D& a_vector, const Vector3D& a_vector2) const;
	const Vector3D divide(const Vector3D& a_vector, const float& a_float) const;

#pragma endregion

#pragma region Public Functions

	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const Vector3D& a_vector) const;
	const float distanceSq(const Vector3D& a_vector) const;

	const float dotProduct(const Vector3D& a_vector, const Vector3D& a_vector2) const;
	const Vector3D crossProduct(const Vector3D& a_vector, const Vector3D& a_vector2) const;

	const Vector3D normalise() const;

	const float* GetPointer() const;

#pragma endregion

private:
	float m_coordinates[3];
};


#endif // __VECTOR3D_H__

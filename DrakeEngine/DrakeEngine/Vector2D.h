#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

class Vector2D
{
public:

#pragma region Constructors
	Vector2D();
	Vector2D(float a_x, float a_y);
	Vector2D(const Vector2D& v);
	~Vector2D();
#pragma endregion

#pragma region Overload Operations

	Vector2D& operator=(const Vector2D& rhs); // Set two vectors equal to eachother
	const Vector2D operator+(const Vector2D& rhs) const;
	Vector2D& operator+=(const Vector2D& rhs);

	const Vector2D operator-(const Vector2D& rhs) const;
	Vector2D& operator-=(const Vector2D& rhs);

	const Vector2D operator*(const float& rhs) const;
	Vector2D& operator*=(const float& rhs);

	const Vector2D operator*(const Vector2D& rhs) const;
	Vector2D& operator*=(const Vector2D& rhs);

	const Vector2D operator/(const float& rhs) const;
	Vector2D& operator/=(const float& rhs);

	const Vector2D operator/(const Vector2D& rhs) const;
	Vector2D& operator/=(const Vector2D& rhs);

	const float operator[](const int i) const;

	const bool operator==(const Vector2D& rhs) const;
	const bool operator!=(const Vector2D& rhs) const;

#pragma endregion

#pragma region Math Operations

	const Vector2D add(const Vector2D& a_vector, const Vector2D& a_vector2) const;
	const Vector2D add(const Vector2D& a_vector, const float& a_float) const;

	const Vector2D subtract(const Vector2D& a_vector, const Vector2D& a_vector2) const;
	const Vector2D subtract(const Vector2D& a_vector, const float& a_float) const;

	const Vector2D multiply(const Vector2D& a_vector, const float& a_float) const;
	const Vector2D multiply(const Vector2D& a_vector, const Vector2D& a_vector2) const;

	const Vector2D divide(const Vector2D& a_vector, const float& a_float) const;
	const Vector2D divide(const Vector2D& a_vector, const Vector2D& a_vector2) const;

#pragma endregion

#pragma region Public Functions

	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const Vector2D& a_vector) const;
	const float distanceSq(const Vector2D& a_vector) const;

	const float dotProduct(const Vector2D& a_vector, const Vector2D& a_vector2) const;
	const Vector2D crossProduct(const Vector2D& a_vector, const Vector2D& a_vector2) const;

	const Vector2D normalise() const;

	const float* GetPointer() const;

#pragma endregion

private:
	float m_coordinates[2];
};

#endif // __VECTOR2D_H__
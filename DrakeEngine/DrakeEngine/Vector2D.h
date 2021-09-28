#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

class Vector2D
{
public:

	float x;
	float y;

	Vector2D();
	Vector2D(float a_x, float a_y);
	Vector2D(const Vector2D& v);
	~Vector2D();

#pragma region Overload Operations

	Vector2D& operator= (const Vector2D& rhs); // Set two vectors equal to eachother
	friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D operator*(const Vector2D& lhs, const float& rhs);
	friend Vector2D operator*(const float& lhs, const Vector2D& rhs);
	friend Vector2D operator/(const Vector2D& lhs, const float& rhs);
	friend Vector2D operator/(const float& lhs, const Vector2D& rhs);
	const float operator[](const int i) const;

#pragma endregion

#pragma region Math Operations

	const Vector2D add(const Vector2D& a_vector, const Vector2D& a_vector2) const;
	const Vector2D subtract(const Vector2D& a_vector, const Vector2D& a_vector2) const;
	const Vector2D multiply(const Vector2D& a_vector, const float& a_float) const;
	const Vector2D divide(const Vector2D& a_vector, const float& a_float) const;

#pragma endregion


#pragma region Public Functions

	const float magnitude(const Vector2D& a_vector) const;
	const float magnitudeSq(const Vector2D& a_vector) const;

	const float distance(const Vector2D& a_vector, const Vector2D& a_vector2) const;
	const float distanceSq(const Vector2D& a_vector, const Vector2D& a_vector2) const;

	const float dotProduct(const Vector2D& a_vector, const Vector2D& a_vector2) const;
	const Vector2D crossProduct(const Vector2D& a_vector, const Vector2D& a_vector2) const;

	const Vector2D normalised(const Vector2D& a_vector) const;

	const float* GetPointer() const;

#pragma endregion

private:
	float coordinates[2];
};

#endif // __VECTOR2D_H__
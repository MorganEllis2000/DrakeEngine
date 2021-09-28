#include "Vector2D.h"
#include "Math.h"

using namespace Math;

#pragma region Constructors

Vector2D::Vector2D() {
	x = 0;
	y = 0;
}

Vector2D::Vector2D(float a_x, float a_y) {
	x = a_x;
	y = a_y;
}

Vector2D::~Vector2D() {

}

Vector2D::Vector2D(const Vector2D& v) {
	x = v.x;
	y = v.y;
}

#pragma endregion

#pragma region Overload Operations

Vector2D& Vector2D::operator=(const Vector2D& rhs) {
	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
	}

	return *this;
}

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
	Vector2D sum;

	sum.x = lhs.x + rhs.x;
	sum.y = lhs.y + rhs.y;

	return sum;
}

Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs) {
	Vector2D diff = Vector2D();

	diff.x = lhs.x - rhs.x;
	diff.y = lhs.y - rhs.y;

	return diff;
}

Vector2D operator*(const Vector2D& lhs, const float& rhs) {
	Vector2D mul = Vector2D();

	mul.x = lhs.x * rhs;
	mul.y = lhs.y * rhs;

	return mul;
}

Vector2D operator*(const float& lhs, const Vector2D& rhs) {
	return rhs * lhs;
}

Vector2D operator/(const Vector2D& lhs, const float& rhs) {
	Vector2D div = Vector2D();

	div.x = lhs.x / rhs;
	div.y = lhs.y / rhs;

	return div;
}

Vector2D operator/(const float& lhs, const Vector2D& rhs) {
	return rhs / lhs;
}

const float Vector2D::operator[](const int i) const {
	if (i == 0) {
		return x;
	}
	else if (i == 1) {
		return y;
	}
	else {
		return 0;
	}
}

#pragma endregion

#pragma region Math Operations

const Vector2D Vector2D::add(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	Vector2D sum = Vector2D();
	sum.x = a_vector.x + a_vector2.x;
	sum.y = a_vector.y + a_vector2.y;

	return sum;
}

const Vector2D Vector2D::subtract(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	Vector2D diff = Vector2D();
	diff.x = a_vector2.x - a_vector.x;
	diff.y = a_vector2.y - a_vector.y;

	return diff;
}

const Vector2D Vector2D::multiply(const Vector2D& a_vector, const float& a_float) const {
	Vector2D mul = Vector2D();
	mul.x = a_vector.x * a_float;
	mul.y = a_vector.y * a_float;

	return mul;
}

const Vector2D Vector2D::divide(const Vector2D& a_vector, const float& a_float) const {
	Vector2D div = Vector2D();
	div.x = a_vector.x / a_float;
	div.y = a_vector.y / a_float;

	return div;
}

#pragma endregion

#pragma region Public Functions

/*
Finds the magnitude(length) of a vector

|v| = sqrt(v.x^2 + v.y^2 + v.z^2)
*/
const float Vector2D::magnitude(const Vector2D& a_vector) const {
	return (a_vector.x * a_vector.x + a_vector.y * a_vector.y);
}

const float Vector2D::magnitudeSq(const Vector2D& a_vector) const {
	return sqrt(a_vector.x * a_vector.x + a_vector.y * a_vector.y);
}

/*
distance = sqrt( (x - x2)^2 + (y - y2)^2 + (z - z2)^2) )
*/
const float Vector2D::distance(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	return (((a_vector.x - a_vector2.x) * (a_vector.x - a_vector2.x)) + ((a_vector.y - a_vector2.y) * (a_vector.y - a_vector2.y)));
}

const float Vector2D::distanceSq(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	return sqrt(((a_vector.x - a_vector2.x) * (a_vector.x - a_vector2.x)) + ((a_vector.y - a_vector2.y) * (a_vector.y - a_vector2.y)));
}

/*
The dot product is used to find the angle between two set of vector coordinates

A dot B = |A| * |B| * cos(theta)

|A|, |B| = The magnitude of the vector

The dot product can also be used to find the angle between points A and B

cos(theta) = A * B / |A| * |B|

*/
const float Vector2D::dotProduct(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	return a_vector.x * a_vector2.x + a_vector.y * a_vector2.y;
}

/*
|A cross B | = |A| |B| sin(theta)

A cross B = x(v1.y, v1.z, v2.y, v2.z) + y(v1.x, v1.z, v2.x, v2.z) + z(v1.x, v1.y, v2.x, v2.y)

If we calculate the cross product using matrix notation we can take the determinant and the equation becomes

v1 = v1.x * x + v1.y * y + v1.z * z
v2 = v2.x * x + v2.y * y + v2.z * z
crossProduct = v1 * v2

 ______________________________
|         |         |         |
|    x    |    y    |    z    |		 ___________________	  ___________________	   ___________________
| _______ | _______ |________ |		|         |         |	 |         |         |	  |         |         |
|         |         |         |		|   v1.y  |   v1.z  |	 |  v1.x   |   v1.z  |	  |  v1.x   |   v1.y  |
|  v1.x   |   v1.y  |   v1.z  | = x	|_________|_________| - y|_________|_________| + z|_________|_________|
|_________|_________|_________|		|         |         |	 |         |         |	  |         |         |
|         |         |         |		|   v2.y  |   v2.z  |	 |  v2.x   |   v2.z  |	  |  v2.x   |   v2.y  |
|  v2.x   |   v2.y  |   v2.z  |		|_________|_________|	 |_________|_________|	  |_________|_________|
|_________|_________|_________|

crossProduct = x * ( (v1.y * v2.y) - (v1.z * v2.y) ) - y * ( (v1.z * v2.x) - (v1.x * v2.z) ) + z * * ( (v1.x * v2.y) - (v1.y * v2.x) )

From this equation we can extrapolate the equations we need to perform on each axis in the crossproduct
x = x * (v1.y * v2.y) - (v1.z * v2.y)
y = -y * (v1.z * v2.x) - (v1.x * v2.z)
z = z * (v1.x * v2.y) - (v1.y * v2.x)

We already have a function that does this so we use this when calculating the final value

*/
const Vector2D Vector2D::crossProduct(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	Vector2D crossProduct = Vector2D();
	crossProduct.x = (a_vector.x * a_vector2.y);
	crossProduct.y = (a_vector2.x * a_vector.y);; 

	return crossProduct;
}

/*
Normalizing vectors allow use to get a value that will represent the direction of the vector but does not include its magnetude

norm x = x / magnitude
*/
const Vector2D Vector2D::normalised(const Vector2D& a_vector) const {
	Vector2D norm = Vector2D();
	float length = magnitudeSq(a_vector);

	norm.x = a_vector.x / length;
	norm.y = a_vector.y / length;

	return norm;
}

const float* Vector2D::GetPointer() const {
	return coordinates;
}

#pragma endregion
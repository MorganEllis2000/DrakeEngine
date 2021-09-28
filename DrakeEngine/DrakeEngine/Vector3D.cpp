#include "Vector3D.h"
#include "Math.h"

using namespace Math;

#pragma region Constructors

Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(float a_x, float a_y, float a_z) {
	x = a_x;
	y = a_y;
	z = a_z;
}

Vector3D::~Vector3D() {

}

Vector3D::Vector3D(const Vector3D& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}

#pragma endregion

#pragma region Overload Operations

Vector3D& Vector3D::operator=(const Vector3D& rhs) {
	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}

	return *this;
}

Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs) {
	Vector3D sum;

	sum.x = lhs.x + rhs.x;
	sum.y = lhs.y + rhs.y;
	sum.z = lhs.z + rhs.z;

	return sum;
}

Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs) {
	Vector3D diff = Vector3D();

	diff.x = lhs.x - rhs.x;
	diff.y = lhs.y - rhs.y;
	diff.z = lhs.z - rhs.z;

	return diff;
}

Vector3D operator*(const Vector3D& lhs, const float& rhs) {
	Vector3D mul = Vector3D();

	mul.x = lhs.x * rhs;
	mul.y = lhs.y * rhs;
	mul.z = lhs.z * rhs;

	return mul;
}

Vector3D operator*(const float& lhs, const Vector3D& rhs) {
	return rhs * lhs;
}

Vector3D operator/(const Vector3D& lhs, const float& rhs) {
	Vector3D div = Vector3D();

	div.x = lhs.x / rhs;
	div.y = lhs.y / rhs;
	div.z = lhs.z / rhs;

	return div;
}

Vector3D operator/(const float& lhs, const Vector3D& rhs) {
	return rhs / lhs;
}

const float Vector3D::operator[](const int i) const {
	if (i == 0) {
		return x;
	}
	else if (i == 1) {
		return y;
	}
	else if (i == 2) {
		return z;
	}
	else {
		return 0;
	}
}

#pragma endregion

#pragma region Math Operations

const Vector3D Vector3D::add(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	Vector3D sum = Vector3D();
	sum.x = a_vector.x + a_vector2.x;
	sum.y = a_vector.y + a_vector2.y;
	sum.z = a_vector.z + a_vector2.z;

	return sum;
}

const Vector3D Vector3D::subtract(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	Vector3D diff = Vector3D();
	diff.x = a_vector2.x - a_vector.x;
	diff.y = a_vector2.y - a_vector.y;
	diff.z = a_vector2.z - a_vector.z;

	return diff;
}

const Vector3D Vector3D::multiply(const Vector3D& a_vector, const float& a_float) const {
	Vector3D mul = Vector3D();
	mul.x = a_vector.x * a_float;
	mul.y = a_vector.y * a_float;
	mul.z = a_vector.z * a_float;

	return mul;
}

const Vector3D Vector3D::divide(const Vector3D& a_vector, const float& a_float) const {
	Vector3D div = Vector3D();
	div.x = a_vector.x / a_float;
	div.y = a_vector.y / a_float;
	div.z = a_vector.z / a_float;

	return div;
}

#pragma endregion

#pragma region Public Functions

/*
Finds the magnitude(length) of a vector

|v| = sqrt(v.x^2 + v.y^2 + v.z^2)
*/
const float Vector3D::magnitude(const Vector3D& a_vector) const {
	return (a_vector.x * a_vector.x + a_vector.y * a_vector.y + a_vector.z * a_vector.z);
}

const float Vector3D::magnitudeSq(const Vector3D& a_vector) const {
	return sqrt(a_vector.x * a_vector.x + a_vector.y * a_vector.y + a_vector.z * a_vector.z);
}

/*
distance = sqrt( (x - x2)^2 + (y - y2)^2 + (z - z2)^2) )
*/
const float Vector3D::distance(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	return (((a_vector.x - a_vector2.x) * (a_vector.x - a_vector2.x)) + ((a_vector.y - a_vector2.y) * (a_vector.y - a_vector2.y)) + ((a_vector.z - a_vector2.z) * (a_vector.z - a_vector2.z)));
}

const float Vector3D::distanceSq(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	return sqrt(((a_vector.x - a_vector2.x) * (a_vector.x - a_vector2.x)) + ((a_vector.y - a_vector2.y) * (a_vector.y - a_vector2.y)) + ((a_vector.z - a_vector2.z) * (a_vector.z - a_vector2.z)));
}

/*
The dot product is used to find the angle between two set of vector coordinates

A dot B = |A| * |B| * cos(theta)

|A|, |B| = The magnitude of the vector

The dot product can also be used to find the angle between points A and B

cos(theta) = A * B / |A| * |B|

*/
const float Vector3D::dotProduct(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	return a_vector.x * a_vector2.x + a_vector.y * a_vector2.y + a_vector.z * a_vector2.z;
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
const Vector3D Vector3D::crossProduct(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	Vector3D crossProduct = Vector3D();
	crossProduct.x = det2x2(a_vector.y, a_vector.z, a_vector2.y, a_vector2.z);
	crossProduct.y = -1 * det2x2(a_vector.x, a_vector.z, a_vector2.x, a_vector2.z); // As seen above we need to subtract but we cant in this instance so we multiply by negative 1 to flip the sign
	crossProduct.z = det2x2(a_vector.x, a_vector.y, a_vector2.x, a_vector2.y);

	return crossProduct;
}

/*
Normalizing vectors allow use to get a value that will represent the direction of the vector but does not include its magnetude

norm x = x / magnitude
*/
const Vector3D Vector3D::normalised(const Vector3D& a_vector) const {
	Vector3D norm = Vector3D();
	float length = magnitudeSq(a_vector);

	norm.x = a_vector.x / length;
	norm.y = a_vector.y / length;
	norm.z = a_vector.z / length;
	
	return norm;
}

const float* Vector3D::GetPointer() const {
	return coordinates;
}

#pragma endregion




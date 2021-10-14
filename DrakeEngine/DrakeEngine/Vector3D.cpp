#include "Vector3D.h"
#include "Math.h"

using namespace Math;

#pragma region Constructors

Vector3D::Vector3D() {
	this->m_coordinates[0] = 0;
	this->m_coordinates[1] = 0;
	this->m_coordinates[2] = 0;
}

Vector3D::Vector3D(float a_x, float a_y, float a_z) {
	this->m_coordinates[0] = a_x;
	this->m_coordinates[1] = a_y;
	this->m_coordinates[2] = a_z;
}

Vector3D::~Vector3D() {

}

Vector3D::Vector3D(const Vector3D& v) {
	this->m_coordinates[0] = v.m_coordinates[0];
	this->m_coordinates[1] = v.m_coordinates[1];
	this->m_coordinates[2] = v.m_coordinates[2];
}

#pragma endregion

#pragma region Overload Operations

Vector3D& Vector3D::operator=(const Vector3D& rhs) {
	if (this != &rhs) {
		this->m_coordinates[0] = rhs.m_coordinates[0];
		this->m_coordinates[1] = rhs.m_coordinates[1];
		this->m_coordinates[2] = rhs.m_coordinates[2];
	}

	return *this;
}

const Vector3D Vector3D::operator+(const Vector3D& rhs) const {
	Vector3D sum;

	sum.m_coordinates[0] = this->m_coordinates[0] + rhs.m_coordinates[0];
	sum.m_coordinates[1] = this->m_coordinates[1] + rhs.m_coordinates[1];
	sum.m_coordinates[2] = this->m_coordinates[2] + rhs.m_coordinates[2];

	return sum;
}
Vector3D& Vector3D::operator+=(const Vector3D& rhs) {
	this->m_coordinates[0] += rhs.m_coordinates[0];
	this->m_coordinates[1] += rhs.m_coordinates[1];
	this->m_coordinates[2] += rhs.m_coordinates[2];

	return *this;
}

const Vector3D Vector3D::operator-(const Vector3D& rhs) const {
	Vector3D diff = Vector3D();

	diff.m_coordinates[0] = this->m_coordinates[0] + rhs.m_coordinates[0];
	diff.m_coordinates[1] = this->m_coordinates[1] + rhs.m_coordinates[1];
	diff.m_coordinates[2] = this->m_coordinates[2] + rhs.m_coordinates[2];

	return diff;
}
Vector3D& Vector3D::operator-=(const Vector3D& rhs) {
	this->m_coordinates[0] -= rhs.m_coordinates[0];
	this->m_coordinates[1] -= rhs.m_coordinates[1];
	this->m_coordinates[2] -= rhs.m_coordinates[2];

	return *this;
}

const Vector3D Vector3D::operator*(const float& rhs) const {
	Vector3D mul = Vector3D();

	mul.m_coordinates[0] = this->m_coordinates[0] * rhs;
	mul.m_coordinates[1] = this->m_coordinates[1] * rhs;
	mul.m_coordinates[2] = this->m_coordinates[2] * rhs;

	return mul;
}
Vector3D& Vector3D::operator*=(const float& rhs) {
	this->m_coordinates[0] *= rhs;
	this->m_coordinates[1] *= rhs;
	this->m_coordinates[2] *= rhs;

	return *this;
}

const Vector3D Vector3D::operator*(const Vector3D& rhs) const {
	Vector3D mul = Vector3D();

	mul.m_coordinates[0] = this->m_coordinates[0] * rhs.m_coordinates[0];
	mul.m_coordinates[1] = this->m_coordinates[1] * rhs.m_coordinates[1];
	mul.m_coordinates[2] = this->m_coordinates[2] * rhs.m_coordinates[2];

	return mul;
}
Vector3D& Vector3D::operator*=(const Vector3D& rhs) {
	this->m_coordinates[0] *= rhs.m_coordinates[0];
	this->m_coordinates[1] *= rhs.m_coordinates[1];
	this->m_coordinates[2] *= rhs.m_coordinates[2];

	return *this;
}

const Vector3D Vector3D::operator/(const float& rhs) const {
	Vector3D div = Vector3D();

	div.m_coordinates[0] = this->m_coordinates[0] / rhs;
	div.m_coordinates[1] = this->m_coordinates[1] / rhs;
	div.m_coordinates[2] = this->m_coordinates[2] / rhs;

	return div;
}
Vector3D& Vector3D::operator/=(const float& rhs) {
	this->m_coordinates[0] /= rhs;
	this->m_coordinates[1] /= rhs;
	this->m_coordinates[2] /= rhs;

	return *this;
}

const Vector3D Vector3D::operator/(const Vector3D& rhs) const {
	Vector3D div = Vector3D();

	div.m_coordinates[0] = this->m_coordinates[0] / rhs.m_coordinates[0];
	div.m_coordinates[1] = this->m_coordinates[1] / rhs.m_coordinates[1];
	div.m_coordinates[2] = this->m_coordinates[2] / rhs.m_coordinates[2];

	return div;
}
Vector3D& Vector3D::operator/=(const Vector3D& rhs) {
	this->m_coordinates[0] /= rhs.m_coordinates[0];
	this->m_coordinates[1] /= rhs.m_coordinates[1];
	this->m_coordinates[2] /= rhs.m_coordinates[2];

	return *this;
}

const float Vector3D::operator[](const int i) const {
	if (i == 0) {
		return m_coordinates[0];
	}
	else if (i == 1) {
		return m_coordinates[1];
	}
	else if (i == 2) {
		return m_coordinates[2];
	}
	else {
		return 0;
	}
}

const bool Vector3D::operator==(const Vector3D& rhs) const {
	for (int i = 0; i < 3; ++i) {
		if (this->m_coordinates[i] == rhs.m_coordinates[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}
const bool Vector3D::operator!=(const Vector3D& rhs) const {
	for (int i = 0; i < 3; ++i) {
		if (this->m_coordinates[i] != rhs.m_coordinates[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}

#pragma endregion

#pragma region Math Operations

const Vector3D Vector3D::add(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	Vector3D sum = Vector3D();
	sum.m_coordinates[0] = a_vector.m_coordinates[0] + a_vector2.m_coordinates[0];
	sum.m_coordinates[1] = a_vector.m_coordinates[1] + a_vector2.m_coordinates[1];
	sum.m_coordinates[2] = a_vector.m_coordinates[2] + a_vector2.m_coordinates[2];

	return sum;
}
const Vector3D Vector3D::add(const Vector3D& a_vector, const float& a_float) const {
	Vector3D add = Vector3D();
	add.m_coordinates[0] = a_vector.m_coordinates[0] + a_float;
	add.m_coordinates[1] = a_vector.m_coordinates[1] + a_float;
	add.m_coordinates[2] = a_vector.m_coordinates[2] + a_float;

	return add;
}

const Vector3D Vector3D::subtract(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	Vector3D diff = Vector3D();
	diff.m_coordinates[0] = a_vector.m_coordinates[0] - a_vector2.m_coordinates[0];
	diff.m_coordinates[1] = a_vector.m_coordinates[1] - a_vector2.m_coordinates[1];
	diff.m_coordinates[2] = a_vector.m_coordinates[2] - a_vector2.m_coordinates[2];

	return diff;
}
const Vector3D Vector3D::subtract(const Vector3D& a_vector, const float& a_float) const {
	Vector3D diff = Vector3D();
	diff.m_coordinates[0] = a_vector.m_coordinates[0] - a_float;
	diff.m_coordinates[1] = a_vector.m_coordinates[1] - a_float;
	diff.m_coordinates[2] = a_vector.m_coordinates[2] - a_float;

	return diff;
}

const Vector3D Vector3D::multiply(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	Vector3D mul = Vector3D();
	mul.m_coordinates[0] = a_vector.m_coordinates[0] * a_vector2.m_coordinates[0];
	mul.m_coordinates[1] = a_vector.m_coordinates[1] * a_vector2.m_coordinates[1];
	mul.m_coordinates[2] = a_vector.m_coordinates[2] * a_vector2.m_coordinates[2];

	return mul;
}
const Vector3D Vector3D::multiply(const Vector3D& a_vector, const float& a_float) const {
	Vector3D mul = Vector3D();
	mul.m_coordinates[0] = a_vector.m_coordinates[0] * a_float;
	mul.m_coordinates[1] = a_vector.m_coordinates[1] * a_float;
	mul.m_coordinates[2] = a_vector.m_coordinates[2] * a_float;

	return mul;
}

const Vector3D Vector3D::divide(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	Vector3D div = Vector3D();
	div.m_coordinates[0] = a_vector.m_coordinates[0] / a_vector2.m_coordinates[0];
	div.m_coordinates[1] = a_vector.m_coordinates[1] / a_vector2.m_coordinates[1];
	div.m_coordinates[2] = a_vector.m_coordinates[2] / a_vector2.m_coordinates[2];

	return div;
}
const Vector3D Vector3D::divide(const Vector3D& a_vector, const float& a_float) const {
	Vector3D div = Vector3D();
	div.m_coordinates[0] = a_vector.m_coordinates[0] / a_float;
	div.m_coordinates[1] = a_vector.m_coordinates[1] / a_float;
	div.m_coordinates[2] = a_vector.m_coordinates[2] / a_float;

	return div;
}

#pragma endregion

#pragma region Public Functions

/*
Finds the magnitude(length) of a vector

|v| = sqrt(v.x^2 + v.y^2 + v.z^2)
*/
const float Vector3D::magnitude() const {
	return (this->m_coordinates[0] * this->m_coordinates[0] +
			this->m_coordinates[1] * this->m_coordinates[1] +
			this->m_coordinates[2] * this->m_coordinates[2]);
}

const float Vector3D::magnitudeSq() const {
	return sqrt(this->magnitude());
}

/*
distance = sqrt( (x - x2)^2 + (y - y2)^2 + (z - z2)^2) )
*/
const float Vector3D::distance(const Vector3D& a_vector) const {
	return (((a_vector.m_coordinates[0] - this->m_coordinates[0]) * (a_vector.m_coordinates[0] - this->m_coordinates[0])) +
			((a_vector.m_coordinates[1] - this->m_coordinates[1]) * (a_vector.m_coordinates[1] - this->m_coordinates[1])) +
			((a_vector.m_coordinates[2] - this->m_coordinates[2]) * (a_vector.m_coordinates[2] - this->m_coordinates[2])));
}

const float Vector3D::distanceSq(const Vector3D& a_vector) const {
	return sqrt(this->distance(a_vector));
}

/*
The dot product is used to find the angle between two set of vector coordinates

A dot B = |A| * |B| * cos(theta)

|A|, |B| = The magnitude of the vector

The dot product can also be used to find the angle between points A and B

cos(theta) = A * B / |A| * |B|

*/
const float Vector3D::dotProduct(const Vector3D& a_vector, const Vector3D& a_vector2) const {
	return  a_vector.m_coordinates[0] * a_vector2.m_coordinates[0] +
			a_vector.m_coordinates[1] * a_vector2.m_coordinates[1] +
			a_vector.m_coordinates[2] * a_vector2.m_coordinates[2];
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
	crossProduct.m_coordinates[0] = det2x2(a_vector.m_coordinates[1], a_vector.m_coordinates[2], a_vector2.m_coordinates[1], a_vector2.m_coordinates[2]);
	crossProduct.m_coordinates[1] = -1 * det2x2(a_vector.m_coordinates[0], a_vector.m_coordinates[2], a_vector2.m_coordinates[0], a_vector2.m_coordinates[2]); // As seen above we need to subtract but we cant in this instance so we multiply by negative 1 to flip the sign
	crossProduct.m_coordinates[2] = det2x2(a_vector.m_coordinates[0], a_vector.m_coordinates[1], a_vector2.m_coordinates[0], a_vector2.m_coordinates[1]);

	return crossProduct;
}

/*
Normalizing vectors allow use to get a value that will represent the direction of the vector but does not include its magnetude

norm x = x / magnitude
*/
const Vector3D Vector3D::normalise() const {
	Vector3D norm = Vector3D();
	float length = this->magnitudeSq();

	norm.m_coordinates[0] = this->m_coordinates[0] / length;
	norm.m_coordinates[1] = this->m_coordinates[1] / length;
	norm.m_coordinates[2] = this->m_coordinates[2] / length;
	
	return norm;
}

const float* Vector3D::GetPointer() const {
	return m_coordinates;
}

#pragma endregion




#include "Vector2D.h"
#include "Math.h"

using namespace Math;

#pragma region Constructors

Vector2D::Vector2D() {
	this->m_coordinates[0] = 0;
	this->m_coordinates[1] = 0;
}

Vector2D::Vector2D(float a_x, float a_y) {
	this->m_coordinates[0] = a_x;
	this->m_coordinates[1] = a_y;
}

Vector2D::~Vector2D() {

}

Vector2D::Vector2D(const Vector2D& v) {
	this->m_coordinates[0] = v.m_coordinates[0];
	this->m_coordinates[1] = v.m_coordinates[1];
}

#pragma endregion

#pragma region Overload Operations

Vector2D& Vector2D::operator=(const Vector2D& rhs) {
	if (this != &rhs) {
		this->m_coordinates[0] = rhs.m_coordinates[0];
		this->m_coordinates[1] = rhs.m_coordinates[1];
	}

	return *this;
}

const Vector2D Vector2D::operator+(const Vector2D& rhs) const{
	Vector2D sum = Vector2D();

	sum.m_coordinates[0] = this->m_coordinates[0] + rhs.m_coordinates[0];
	sum.m_coordinates[1] = this->m_coordinates[1] + rhs.m_coordinates[1];

	return sum;
}
Vector2D& Vector2D::operator+=(const Vector2D& rhs){
	this->m_coordinates[0] += rhs.m_coordinates[0];
	this->m_coordinates[1] += rhs.m_coordinates[1];

	return *this;
}

const Vector2D Vector2D::operator-(const Vector2D& rhs) const{
	Vector2D diff = Vector2D();

	diff.m_coordinates[0] = this->m_coordinates[0] - rhs.m_coordinates[0];
	diff.m_coordinates[1] = this->m_coordinates[1] - rhs.m_coordinates[1];

	return diff;
}
Vector2D& Vector2D::operator-=(const Vector2D& rhs) {
	this->m_coordinates[0] -= rhs.m_coordinates[0];
	this->m_coordinates[1] -= rhs.m_coordinates[1];

	return *this;
}
		
const Vector2D Vector2D::operator*(const float& rhs) const {
	Vector2D mul = Vector2D();

	mul.m_coordinates[0] = this->m_coordinates[0] * rhs;
	mul.m_coordinates[1] = this->m_coordinates[1] * rhs;

	return mul;
}
Vector2D& Vector2D::operator*=(const float& rhs) {
	this->m_coordinates[0] *= rhs;
    this->m_coordinates[1] *= rhs;

	return *this;
}
		
const Vector2D Vector2D::operator*(const Vector2D& rhs) const {
	Vector2D mul = Vector2D();

	mul.m_coordinates[0] = this->m_coordinates[0] * rhs.m_coordinates[0];
	mul.m_coordinates[1] = this->m_coordinates[1] * rhs.m_coordinates[1];

	return mul;
}
Vector2D& Vector2D::operator*=(const Vector2D& rhs) {
	this->m_coordinates[0] *= rhs.m_coordinates[0];
	this->m_coordinates[1] *= rhs.m_coordinates[1];

	return *this;
}
		
const Vector2D Vector2D::operator/(const float& rhs) const {
	Vector2D div = Vector2D();

	div.m_coordinates[0] = this->m_coordinates[0] / rhs;
	div.m_coordinates[1] = this->m_coordinates[1] / rhs;

	return div;
}
Vector2D& Vector2D::operator/=(const float& rhs) {
	this->m_coordinates[0] /= rhs;
	this->m_coordinates[1] /= rhs;

	return *this;
}

const Vector2D Vector2D::operator/(const Vector2D& rhs) const {
	Vector2D div = Vector2D();

	div.m_coordinates[0] = this->m_coordinates[0] / rhs.m_coordinates[0];
	div.m_coordinates[1] = this->m_coordinates[1] / rhs.m_coordinates[1];

	return div;
}
Vector2D& Vector2D::operator/=(const Vector2D& rhs) {
	this->m_coordinates[0] /= rhs.m_coordinates[0];
	this->m_coordinates[1] /= rhs.m_coordinates[1];

	return *this;
}

const float Vector2D::operator[](const int i) const {
	if (i == 0) {
		return m_coordinates[0];
	}
	else if (i == 1) {
		return m_coordinates[1];
	}
	else {
		return 0;
	}
}

const bool Vector2D::operator==(const Vector2D& rhs) const {
	for (int i = 0; i < 2; ++i) {
		if (this->m_coordinates[i] == rhs.m_coordinates[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}
const bool Vector2D::operator!=(const Vector2D& rhs) const {
	for (int i = 0; i < 2; ++i) {
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

const Vector2D Vector2D::add(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	Vector2D sum = Vector2D();
	sum.m_coordinates[0] = a_vector.m_coordinates[0] + a_vector2.m_coordinates[0];
	sum.m_coordinates[1] = a_vector.m_coordinates[1] + a_vector2.m_coordinates[1];

	return sum;
}
const Vector2D Vector2D::add(const Vector2D& a_vector, const float& a_float) const {
	Vector2D add = Vector2D();
	add.m_coordinates[0] = a_vector.m_coordinates[0] + a_float;
	add.m_coordinates[1] = a_vector.m_coordinates[1] + a_float;

	return add;
}

const Vector2D Vector2D::subtract(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	Vector2D diff = Vector2D();
	diff.m_coordinates[0] = a_vector2.m_coordinates[0] - a_vector.m_coordinates[0];
	diff.m_coordinates[1] = a_vector2.m_coordinates[1] - a_vector.m_coordinates[1];

	return diff;
}
const Vector2D Vector2D::subtract(const Vector2D& a_vector, const float& a_float) const {
	Vector2D add = Vector2D();
	add.m_coordinates[0] = a_vector.m_coordinates[0] - a_float;
	add.m_coordinates[1] = a_vector.m_coordinates[1] - a_float;

	return add;
}

const Vector2D Vector2D::multiply(const Vector2D& a_vector, const float& a_float) const {
	Vector2D mul = Vector2D();
	mul.m_coordinates[0] = a_vector.m_coordinates[0] * a_float;
	mul.m_coordinates[1] = a_vector.m_coordinates[1] * a_float;

	return mul;
}
const Vector2D Vector2D::multiply(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	Vector2D mul = Vector2D();
	mul.m_coordinates[0] = a_vector.m_coordinates[0] * a_vector2.m_coordinates[0];
	mul.m_coordinates[1] = a_vector.m_coordinates[1] * a_vector2.m_coordinates[1];

	return mul;
}

const Vector2D Vector2D::divide(const Vector2D& a_vector, const float& a_float) const {
	Vector2D div = Vector2D();
	div.m_coordinates[0] = a_vector.m_coordinates[0] / a_float;
	div.m_coordinates[1] = a_vector.m_coordinates[1] / a_float;

	return div;
}
const Vector2D Vector2D::divide(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	Vector2D div = Vector2D();
	div.m_coordinates[0] = a_vector.m_coordinates[0] / a_vector2.m_coordinates[0];
	div.m_coordinates[1] = a_vector.m_coordinates[1] / a_vector2.m_coordinates[1];

	return div;
}

#pragma endregion

#pragma region Public Functions

/*
Finds the magnitude(length) of a vector

|v| = sqrt(v.x^2 + v.y^2 + v.z^2)
*/
const float Vector2D::magnitude() const {
	return (this->m_coordinates[0] * this->m_coordinates[0] + this->m_coordinates[1] * this->m_coordinates[1]);
}

const float Vector2D::magnitudeSq() const {
	return sqrt(this->magnitude());
}

/*
distance = sqrt( (x - x2)^2 + (y - y2)^2 + (z - z2)^2) )
*/
const float Vector2D::distance(const Vector2D& a_vector) const {
	return (((a_vector.m_coordinates[0] - this->m_coordinates[0]) * (a_vector.m_coordinates[0] - this->m_coordinates[0])) + ((a_vector.m_coordinates[1] - this->m_coordinates[1]) * (a_vector.m_coordinates[1] - this->m_coordinates[1])));
}

const float Vector2D::distanceSq(const Vector2D& a_vector) const {
	return sqrt(this->distance(a_vector));
}

/*
The dot product is used to find the angle between two set of vector coordinates

A dot B = |A| * |B| * cos(theta)

|A|, |B| = The magnitude of the vector

The dot product can also be used to find the angle between points A and B

cos(theta) = A * B / |A| * |B|

*/
const float Vector2D::dotProduct(const Vector2D& a_vector, const Vector2D& a_vector2) const {
	return a_vector.m_coordinates[0] * a_vector2.m_coordinates[0] + a_vector.m_coordinates[1] * a_vector2.m_coordinates[1];
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
	crossProduct.m_coordinates[0] = (a_vector.m_coordinates[0]  * a_vector2.m_coordinates[1]);
	crossProduct.m_coordinates[1] = (a_vector2.m_coordinates[0] * a_vector.m_coordinates[1]);; 

	return crossProduct;
}

/*
Normalizing vectors allow use to get a value that will represent the direction of the vector but does not include its magnetude

norm x = x / magnitude
*/
const Vector2D Vector2D::normalise() const {
	Vector2D norm = Vector2D();
	float length = this->magnitudeSq();

	norm.m_coordinates[0] = this->m_coordinates[0] / length;
	norm.m_coordinates[1] = this->m_coordinates[1] / length;

	return norm;
}

const float* Vector2D::GetPointer() const {
	return m_coordinates;
}

#pragma endregion
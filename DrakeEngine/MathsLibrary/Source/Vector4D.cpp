#include "../Header/Vector4D.h"
#include "../Header/Math.h"

using namespace Math;

#pragma region Constructors
Vector4D::Vector4D() {
	this->m_coordinates[0] = 0;
	this->m_coordinates[1] = 0;
	this->m_coordinates[2] = 0;
	this->m_coordinates[3] = 0;
}
Vector4D::Vector4D(double a_x, double a_y, double a_z, double a_w) {
	this->m_coordinates[0] = a_x;
	this->m_coordinates[1] = a_y;
	this->m_coordinates[2] = a_z;
	this->m_coordinates[3] = a_w;
}
Vector4D::Vector4D(const Vector4D& a_vector) {
	this->m_coordinates[0] = a_vector.m_coordinates[0];
	this->m_coordinates[1] = a_vector.m_coordinates[1];
	this->m_coordinates[2] = a_vector.m_coordinates[2];
	this->m_coordinates[3] = a_vector.m_coordinates[3];
}
Vector4D::~Vector4D() {

}
#pragma endregion

#pragma region Operator Overloads
Vector4D& Vector4D::operator= (const Vector4D& rhs) {
	if (this != &rhs) {
		this->m_coordinates[0] = rhs.m_coordinates[0];
		this->m_coordinates[1] = rhs.m_coordinates[1];
		this->m_coordinates[2] = rhs.m_coordinates[2];
		this->m_coordinates[3] = rhs.m_coordinates[3];
	}

	return *this;
}

const Vector4D Vector4D::operator+(const Vector4D& rhs) const {
	Vector4D sum = Vector4D();
	
	sum.m_coordinates[0] = this->m_coordinates[0] + rhs.m_coordinates[0];
	sum.m_coordinates[1] = this->m_coordinates[1] + rhs.m_coordinates[1];
	sum.m_coordinates[2] = this->m_coordinates[2] + rhs.m_coordinates[2];
	sum.m_coordinates[3] = this->m_coordinates[3] + rhs.m_coordinates[3];

	return sum;
}
Vector4D& Vector4D::operator+=(const Vector4D& rhs) {
	this->m_coordinates[0] += rhs.m_coordinates[0];
	this->m_coordinates[1] += rhs.m_coordinates[1];
	this->m_coordinates[2] += rhs.m_coordinates[2];
	this->m_coordinates[3] += rhs.m_coordinates[3];

	return *this;
}

const Vector4D Vector4D::operator-(const Vector4D& rhs) const {
	Vector4D dif = Vector4D();

	dif.m_coordinates[0] = this->m_coordinates[0] - rhs.m_coordinates[0];
	dif.m_coordinates[1] = this->m_coordinates[1] - rhs.m_coordinates[1];
	dif.m_coordinates[2] = this->m_coordinates[2] - rhs.m_coordinates[2];
	dif.m_coordinates[3] = this->m_coordinates[3] - rhs.m_coordinates[3];

	return dif;
}
Vector4D& Vector4D::operator-=(const Vector4D& rhs) {
	this->m_coordinates[0] -= rhs.m_coordinates[0];
	this->m_coordinates[1] -= rhs.m_coordinates[1];
	this->m_coordinates[2] -= rhs.m_coordinates[2];
	this->m_coordinates[3] -= rhs.m_coordinates[3];

	return *this;
}

const Vector4D Vector4D::operator*(const float& rhs) const {
	Vector4D mul = Vector4D();

	mul.m_coordinates[0] = this->m_coordinates[0] * rhs;
	mul.m_coordinates[1] = this->m_coordinates[1] * rhs;
	mul.m_coordinates[2] = this->m_coordinates[2] * rhs;
	mul.m_coordinates[3] = this->m_coordinates[3] * rhs;

	return mul;
}
Vector4D& Vector4D::operator*=(const float& rhs) {
	this->m_coordinates[0] *= rhs;
	this->m_coordinates[1] *= rhs;
	this->m_coordinates[2] *= rhs;
	this->m_coordinates[3] *= rhs;

	return *this;
}

const Vector4D Vector4D::operator*(const Vector4D& rhs) const {
	Vector4D mul = Vector4D();

	mul.m_coordinates[0] = this->m_coordinates[0] * rhs.m_coordinates[0];
	mul.m_coordinates[1] = this->m_coordinates[1] * rhs.m_coordinates[1];
	mul.m_coordinates[2] = this->m_coordinates[2] * rhs.m_coordinates[2];
	mul.m_coordinates[3] = this->m_coordinates[3] * rhs.m_coordinates[3];
	
	return mul;
}
Vector4D& Vector4D::operator*=(const Vector4D& rhs) {
	this->m_coordinates[0] *= rhs.m_coordinates[0];
	this->m_coordinates[1] *= rhs.m_coordinates[1];
	this->m_coordinates[2] *= rhs.m_coordinates[2];
	this->m_coordinates[3] *= rhs.m_coordinates[3];

	return *this;
}

const Vector4D Vector4D::operator*(const Matrix4x4& rhs) const {
	Vector4D mul;

	mul.m_coordinates[0] = (  (rhs[0]  * this->m_coordinates[0]) + (rhs[1]  * this->m_coordinates[1]) + (rhs[2]  * this->m_coordinates[2])  + (rhs[3] * this->m_coordinates[3])  );
	mul.m_coordinates[1] = (  (rhs[4]  * this->m_coordinates[0]) + (rhs[5]  * this->m_coordinates[1]) + (rhs[6]  * this->m_coordinates[2])  + (rhs[7] * this->m_coordinates[3])  );
	mul.m_coordinates[2] = (  (rhs[8]  * this->m_coordinates[0]) + (rhs[9]  * this->m_coordinates[1]) + (rhs[10] * this->m_coordinates[2]) + (rhs[11] * this->m_coordinates[3]) );
	mul.m_coordinates[3] = (  (rhs[12] * this->m_coordinates[0]) + (rhs[13] * this->m_coordinates[1]) + (rhs[14] * this->m_coordinates[2]) + (rhs[15] * this->m_coordinates[3]) );

	return mul;
}

const Vector4D Vector4D::operator/(const float& rhs) const {
	Vector4D mul = Vector4D();

	mul.m_coordinates[0] = this->m_coordinates[0] / rhs;
	mul.m_coordinates[1] = this->m_coordinates[1] / rhs;
	mul.m_coordinates[2] = this->m_coordinates[2] / rhs;
	mul.m_coordinates[3] = this->m_coordinates[3] / rhs;

	return mul;
}
Vector4D& Vector4D::operator/=(const float& rhs) {
	this->m_coordinates[0] /= rhs;
	this->m_coordinates[1] /= rhs;
	this->m_coordinates[2] /= rhs;
	this->m_coordinates[3] /= rhs;

	return *this;
}

const Vector4D Vector4D::operator/(const Vector4D& rhs) const {
	Vector4D mul = Vector4D();

	mul.m_coordinates[0] = this->m_coordinates[0] / rhs.m_coordinates[0];
	mul.m_coordinates[1] = this->m_coordinates[1] / rhs.m_coordinates[1];
	mul.m_coordinates[2] = this->m_coordinates[2] / rhs.m_coordinates[2];
	mul.m_coordinates[3] = this->m_coordinates[3] / rhs.m_coordinates[3];

	return mul;
}
Vector4D& Vector4D::operator/=(const Vector4D& rhs) {
	this->m_coordinates[0] /= rhs.m_coordinates[0];
	this->m_coordinates[1] /= rhs.m_coordinates[1];
	this->m_coordinates[2] /= rhs.m_coordinates[2];
	this->m_coordinates[3] /= rhs.m_coordinates[3];

	return *this;
}

const float Vector4D::operator[](const int i) const {
	if (i == 0) {
		return m_coordinates[0];
	}
	else if (i == 1) {
		return m_coordinates[1];
	}
	else if (i == 2) {
		return m_coordinates[2];
	}
	else if (i == 3) {
		return m_coordinates[3];
	}
	else {
		return 0;
	}
}

const bool Vector4D::operator==(const Vector4D& rhs) const {
	for (int i = 0; i < 4; ++i) {
		if (this->m_coordinates[i] == rhs.m_coordinates[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}
const bool Vector4D::operator!=(const Vector4D& rhs) const {
	for (int i = 0; i < 4; ++i) {
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

const Vector4D Vector4D::add(const Vector4D& a_vector, const Vector4D& a_vector2) const {
	Vector4D sum = Vector4D();
	sum.m_coordinates[0] = a_vector.m_coordinates[0] + a_vector2.m_coordinates[0];
	sum.m_coordinates[1] = a_vector.m_coordinates[1] + a_vector2.m_coordinates[1];
	sum.m_coordinates[2] = a_vector.m_coordinates[2] + a_vector2.m_coordinates[2];
	sum.m_coordinates[3] = a_vector.m_coordinates[3] + a_vector2.m_coordinates[3];

	return sum;
}
const Vector4D Vector4D::add(const Vector4D& a_vector, const float& a_float) const {
	Vector4D add = Vector4D();
	add.m_coordinates[0] = a_vector.m_coordinates[0] + a_float;
	add.m_coordinates[1] = a_vector.m_coordinates[1] + a_float;
	add.m_coordinates[2] = a_vector.m_coordinates[2] + a_float;
	add.m_coordinates[3] = a_vector.m_coordinates[3] + a_float;

	return add;
}

const Vector4D Vector4D::subtract(const Vector4D& a_vector, const Vector4D& a_vector2) const {
	Vector4D diff = Vector4D();
	diff.m_coordinates[0] = a_vector.m_coordinates[0] - a_vector2.m_coordinates[0];
	diff.m_coordinates[1] = a_vector.m_coordinates[1] - a_vector2.m_coordinates[1];
	diff.m_coordinates[2] = a_vector.m_coordinates[2] - a_vector2.m_coordinates[2];
	diff.m_coordinates[3] = a_vector.m_coordinates[3] - a_vector2.m_coordinates[3];

	return diff;
}
const Vector4D Vector4D::subtract(const Vector4D& a_vector, const float& a_float) const {
	Vector4D diff = Vector4D();
	diff.m_coordinates[0] = a_vector.m_coordinates[0] - a_float;
	diff.m_coordinates[1] = a_vector.m_coordinates[1] - a_float;
	diff.m_coordinates[2] = a_vector.m_coordinates[2] - a_float;
	diff.m_coordinates[3] = a_vector.m_coordinates[3] - a_float;

	return diff;
}

const Vector4D Vector4D::multiply(const Vector4D& a_vector, const Vector4D& a_vector2) const {
	Vector4D mul = Vector4D();
	mul.m_coordinates[0] = a_vector.m_coordinates[0] * a_vector2.m_coordinates[0];
	mul.m_coordinates[1] = a_vector.m_coordinates[1] * a_vector2.m_coordinates[1];
	mul.m_coordinates[2] = a_vector.m_coordinates[2] * a_vector2.m_coordinates[2];
	mul.m_coordinates[3] = a_vector.m_coordinates[3] * a_vector2.m_coordinates[3];

	return mul;
}
const Vector4D Vector4D::multiply(const Vector4D& a_vector, const float& a_float) const {
	Vector4D mul = Vector4D();
	mul.m_coordinates[0] = a_vector.m_coordinates[0] * a_float;
	mul.m_coordinates[1] = a_vector.m_coordinates[1] * a_float;
	mul.m_coordinates[2] = a_vector.m_coordinates[2] * a_float;
	mul.m_coordinates[3] = a_vector.m_coordinates[3] * a_float;

	return mul;
}

const Vector4D Vector4D::divide(const Vector4D& a_vector, const Vector4D& a_vector2) const {
	Vector4D div = Vector4D();
	div.m_coordinates[0] = a_vector.m_coordinates[0] / a_vector2.m_coordinates[0];
	div.m_coordinates[1] = a_vector.m_coordinates[1] / a_vector2.m_coordinates[1];
	div.m_coordinates[2] = a_vector.m_coordinates[2] / a_vector2.m_coordinates[2];
	div.m_coordinates[3] = a_vector.m_coordinates[3] / a_vector2.m_coordinates[3];

	return div;
}
const Vector4D Vector4D::divide(const Vector4D& a_vector, const float& a_float) const {
	Vector4D div = Vector4D();
	div.m_coordinates[0] = a_vector.m_coordinates[0] / a_float;
	div.m_coordinates[1] = a_vector.m_coordinates[1] / a_float;
	div.m_coordinates[2] = a_vector.m_coordinates[2] / a_float;
	div.m_coordinates[3] = a_vector.m_coordinates[3] / a_float;

	return div;
}

#pragma endregion

#pragma region Public Functions

const float Vector4D::magnitude() const {
	return (this->m_coordinates[0] * this->m_coordinates[0] +
			this->m_coordinates[1] * this->m_coordinates[1] +
			this->m_coordinates[2] * this->m_coordinates[2] +
			this->m_coordinates[3] * this->m_coordinates[3]);
}
const float Vector4D::magnitudeSq() const {
	return sqrt(this->magnitude());
}

const float Vector4D::distance(const Vector4D& a_vector) const {
	return (Math::pow((a_vector.m_coordinates[0] - this->m_coordinates[0]), 2) + 
			Math::pow((a_vector.m_coordinates[1] - this->m_coordinates[1]), 2) + 
			Math::pow((a_vector.m_coordinates[2] - this->m_coordinates[2]), 2) + 
			Math::pow((a_vector.m_coordinates[3] - this->m_coordinates[3]), 2));
}
const float Vector4D::distanceSq(const Vector4D& a_vector) const {
	return Math::sqrt(this->distance(a_vector));
}

const float Vector4D::dotProduct(const Vector4D& a_vector, const Vector4D& a_vector2) const {
	return  a_vector.m_coordinates[0] * a_vector2.m_coordinates[0] +
			a_vector.m_coordinates[1] * a_vector2.m_coordinates[1] +
			a_vector.m_coordinates[2] * a_vector2.m_coordinates[2] +
			a_vector.m_coordinates[3] * a_vector2.m_coordinates[3];
}

const Vector4D Vector4D::normalise() const {
	Vector4D norm = Vector4D();
	float length = this->magnitudeSq();

	norm.m_coordinates[0] = this->m_coordinates[0] / length;
	norm.m_coordinates[1] = this->m_coordinates[1] / length;
	norm.m_coordinates[2] = this->m_coordinates[2] / length;
	norm.m_coordinates[3] = this->m_coordinates[3] / length;

	return norm;
}

const float* Vector4D::GetPointer() const {
	return m_coordinates;
}

#pragma endregion



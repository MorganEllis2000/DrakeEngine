#ifndef __Math_H__
#define __Math_H__

#include "Matrix.h"
#include "Vector3D.h"

namespace Math
{
#pragma region General Functions
	float DegToRad(float d);
	float RadToDeg(float r);

	float sqrtNewton(float val, float estimate);
	float sqrt(float x);

	float abs(float a);
#pragma endregion

#pragma region Vector Math
	Vector3D add(Vector3D a, Vector3D b);
	Vector3D subtract(Vector3D b, Vector3D a);
	Vector3D multiply(Vector3D a, float c);
	Vector3D divide(Vector3D a, float c);

	float magnitude(Vector3D v);
	float normalizeX(Vector3D v, float m);
	float normalizeY(Vector3D v, float m);
	float normalizeZ(Vector3D v, float m);
	float distance3D(Vector3D v1, Vector3D v2);

	float dot(Vector3D a, Vector3D b); // find the dot product
	Vector3D cross(Vector3D a, Vector3D b); // find the cross product
#pragma endregion

#pragma region Matrix Math
	float det2x2(float a, float b, float c, float d); // find the determinant for 2x2 matrix
	float det3x3(float a, float b, float c, float d, float e, float f, float g, float h, float i); // find the determinant for 2x2 matrix
	float det4x4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
#pragma endregion

};

#endif // __Math_H__
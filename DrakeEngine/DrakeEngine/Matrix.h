#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix
{
public:

	size_t rows;
	size_t columns;


	Matrix();
	~Matrix();

	Matrix(const Matrix& m);
	Matrix& operator= (Matrix& rhs);

	float get(size_t row, size_t column); // get value form the matrix
	void set(size_t row, size_t column, float value); // set value in matrix

private:
	float data[3][3];
};

#endif // __MATRIX_H__
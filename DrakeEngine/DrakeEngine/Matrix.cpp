#include "Matrix.h"

// Initialise a matrix
Matrix::Matrix() : rows(3), columns(3) {

	// Iterate of rows
	for (size_t i = 0; i < 2; ++i) {
		// Iterate of columns
		for (size_t j = 0; j < 2; ++j) {
			data[i][j] = 0.0f; // set values for matrix
		}
	}
}

// Deconstructor for matrix
Matrix::~Matrix() {

}


Matrix::Matrix(const Matrix& m) : rows(m.rows), columns(m.columns) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			data[i][j] = m.data[i][j]; // Populate our matrix with data
		}
	}
}

Matrix& Matrix::operator=(Matrix& rhs) {
	rows = rhs.rows;
	columns = rhs.columns;

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			data[i][j] = rhs.data[i][j];
		}
	}

	return *this;
}

float Matrix::get(size_t row, size_t column) {
	return data[row][column];
}

void Matrix::set(size_t row, size_t column, float value) {
	data[row][column] = value;
}
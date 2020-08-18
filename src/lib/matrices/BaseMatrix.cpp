#ifndef MATCAL_BASEMATRIX_CPP
#define MATCAL_BASEMATRIX_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "BaseMatrix.h"


// ------------
// Constructors
// ------------
template<typename T>
BaseMatrix<T>::BaseMatrix(Slice descriptor):
	m_desc { std::move(descriptor) }
{}


template<typename T>
BaseMatrix<T>::BaseMatrix(size_t rows, size_t columns):
	m_desc { 0, {rows, columns}, {columns, 1} }
{}


// ---------
// Accessors
// ---------
template<typename T>
const Slice & BaseMatrix<T>::desc() const {
	return m_desc;
}


template<typename T>
size_t BaseMatrix<T>::rows_num() const {
	return m_desc.m_sizes.first;
}


template<typename T>
size_t BaseMatrix<T>::cols_num() const {
	return m_desc.m_sizes.second;
}


template<typename T>
size_t BaseMatrix<T>::size() const {
	return rows_num() * cols_num();
}


// ---------
// Subscript
// ---------
template<typename T>
T & BaseMatrix<T>::at(size_t row, size_t column) {
	return *(data() + m_desc.at(row, column));
}


template<typename T>
const T & BaseMatrix<T>::at(size_t row, size_t column) const {
	return *(data() + m_desc.at(row, column));
}


// --------------------
// Non-member functions
// --------------------
template<typename T>
std::ostream & operator<<(std::ostream & os, const BaseMatrix<T> & matrix) {
	for (size_t r {0}; r < matrix.rows_num(); ++r) {
		os << (r == 0 ? '{' : ' ');
		for (size_t c {0}; c < matrix.cols_num(); ++c) {
			os << matrix.at(r, c);
			if (c + 1 != matrix.cols_num())
				os << ' ';
		}
		if (r + 1 == matrix.rows_num())
			os << '}';
		os << '\n';
	}
	return os;
}

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_BASEMATRIX_CPP
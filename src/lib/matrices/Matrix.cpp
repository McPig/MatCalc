#ifndef MATCAL_MATRIX_CPP
#define MATCAL_MATRIX_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Matrix.h"


// ------------
// Constructors
// ------------
template<typename T>
Matrix<T>::Matrix(size_t rows, size_t columns):
	BaseMatrix<T>(rows, columns),
	m_items {}
{
	m_items.resize(rows * columns, 0);
}


template<typename T>
Matrix<T>::Matrix(size_t rows, size_t columns, std::vector<T> items):
	BaseMatrix<T>(rows, columns),
	m_items { std::move(items) }
{
	if (this->size() != m_items.size()) {
		std::stringstream ss;
		ss << "Matrix: got " << m_items.size() << " items, but declared Matrix size is " << rows * columns;
		throw std::length_error(ss.str());
	}
}


template<typename T>
Matrix<T>::Matrix(size_t rows, size_t columns, const T & item):
	BaseMatrix<T>(rows, columns),
	m_items {}
{
	m_items.resize(this->size(), item);
}


// ---------
// Accessors
// ---------
template<typename T>
T * Matrix<T>::data() {
	return m_items.data();
}


template<typename T>
const T * Matrix<T>::data() const {
	return m_items.data();
}


template<typename T>
template<typename F>
Matrix<T> & Matrix<T>::apply(F func) {
	for (auto & i : m_items)
		func(i);
	return *this;
}


template<typename T>
template<typename F>
Matrix<T> & Matrix<T>::apply(F func, const Matrix<T> & matrix) {
	if (this->rows_num() != matrix.rows_num() || this->cols_num() != matrix.cols_num())
		throw std::invalid_argument("Matrix: got matrices with incompatible sizes");

	auto t_iter = begin();
	auto m_iter = matrix.begin();

	while (t_iter != end()) {
		func(*t_iter, *m_iter);
		t_iter++;
		m_iter++;
	}

	return *this;
}


// ---------
// Iterators
// ---------
template<typename T>
typename Matrix<T>::iterator Matrix<T>::begin() {
	return m_items.begin();
}


template<typename T>
typename Matrix<T>::const_iterator Matrix<T>::begin() const {
	return m_items.cbegin();
}


template<typename T>
typename Matrix<T>::iterator Matrix<T>::end() {
	return m_items.end();
}


template<typename T>
typename Matrix<T>::const_iterator Matrix<T>::end() const {
	return m_items.cend();
}

// --------------------
// Primitive arithmetic
// --------------------
template<typename T>
Matrix<T> & Matrix<T>::operator+=(const T & scalar) {
	return apply([&](T & obj) {obj += scalar;});
}


template<typename T>
Matrix<T> & Matrix<T>::operator+=(const Matrix<T> & matrix) {
	return apply([](T & item, const T & m_item) {item += m_item;}, matrix);
}


template<typename T>
Matrix<T> & Matrix<T>::operator-=(const T & scalar) {
	return apply([&](T & obj) {obj -= scalar;});
}


template<typename T>
Matrix<T> & Matrix<T>::operator-=(const Matrix<T> & matrix) {
	return apply([](T & item, const T & m_item) {item -= m_item;}, matrix);
}


template<typename T>
Matrix<T> & Matrix<T>::operator*=(const T & scalar) {
	return apply([&](T & obj) {obj *= scalar;});
}


template<typename T>
Matrix<T> & Matrix<T>::operator/=(const T & scalar) {
	return apply([&](T & obj) {obj /= scalar;});
}


template<typename T>
Matrix<T> & Matrix<T>::operator%=(const T & scalar) {
	return apply([&](T & obj) { obj %= scalar; });
}

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_MATRIX_CPP

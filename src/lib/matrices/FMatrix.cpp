#ifndef MATCAL_FMATRIX_CPP
#define MATCAL_FMATRIX_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "FMatrix.h"

template<typename T>
FMatrix<T>::FMatrix(size_t rows, size_t cols, const T & item):
	BaseMatrix<T>(rows, cols),
	m_item {item}
{}


template<typename T>
const T * FMatrix<T>::data() const {
	return &m_item;
}


template<typename T>
T * FMatrix<T>::data() {
	return &m_item;
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_FMATRIX_CPP

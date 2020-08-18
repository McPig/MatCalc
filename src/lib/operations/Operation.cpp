#ifndef MATCAL_OPERATION_CPP
#define MATCAL_OPERATION_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Operation.h"


template<typename T>
Operation<T>::Operation(const Matrix<T> * a):
	m_a {a},
	m_b {},
	m_s {}
{}


template<typename T>
Operation<T>::Operation(const Matrix<T> * a, const Matrix<T> * b):
	m_a {a},
	m_b {b},
	m_s {}
{}


template<typename T>
Operation<T>::Operation(const Matrix<T> * a, T s):
	m_a {a},
	m_b {},
	m_s {s}
{}

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_OPERATION_CPP
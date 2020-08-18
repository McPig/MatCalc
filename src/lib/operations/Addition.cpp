#ifndef MATCAL_ADDITION_CPP
#define MATCAL_ADDITION_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Addition.h"


template<typename T>
Addition<T>::Addition(const Matrix<T> * a, const Matrix<T> * b):
	Operation<T>(a, b)
{}


template<typename T>
Addition<T>::Addition(const Matrix<T> * a, T s):
	Operation<T>(a, s)
{}


template<typename T>
Matrix<T> Addition<T>::result() {
	Matrix<T> res { *(this->m_a) };
	if (this->m_b)
		res += *(this->m_b);
	else
		res += this->m_s;
	return res;
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_ADDITION_CPP

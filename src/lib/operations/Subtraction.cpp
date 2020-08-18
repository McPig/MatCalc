#ifndef MATCAL_SUBTRACTION_CPP
#define MATCAL_SUBTRACTION_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Subtraction.h"


template<typename T>
Subtraction<T>::Subtraction(const Matrix<T> * a, const Matrix<T> * b):
	Operation<T>(a, b)
{}


template<typename T>
Subtraction<T>::Subtraction(const Matrix<T> * a, T s):
	Operation<T>(a, s)
{}


template<typename T>
Matrix<T> Subtraction<T>::result() {
	Matrix<T> res { *(this->m_a) };
	if (this->m_b)
		res -= *(this->m_b);
	else
		res -= this->m_s;
	return res;
}

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_SUBTRACTION_CPP

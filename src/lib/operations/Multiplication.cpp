#ifndef MATCAL_MULTIPLICATION_CPP
#define MATCAL_MULTIPLICATION_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Multiplication.h"


template<typename T>
Multiplication<T>::Multiplication(const Matrix<T> * a, const Matrix<T> * b):
	Operation<T>(a, b)
{
	if (a->cols_num() != b->rows_num())
		throw std::invalid_argument("Multiplication: got matrices with incompatible sizes");
}


template<typename T>
Multiplication<T>::Multiplication(const Matrix<T> * a, T s):
	Operation<T>(a, s)
{}


template<typename T>
Matrix<T> Multiplication<T>::result() {
	// With Matrix
	if (this->m_b) {
		size_t a_rows = this->m_a->rows_num();
		size_t a_cols = this->m_a->cols_num();
		size_t b_cols = this->m_b->cols_num();

		Matrix<T> res {a_rows, b_cols};

		for (size_t r {0}; r < a_rows; ++r)
			for (size_t bc {0}; bc < b_cols; ++bc)
				for (size_t ac {0}; ac < a_cols; ++ac)
					res.at(r, bc) += this->m_a->at(r, ac) * this->m_b->at(ac, bc);
		return res;
	}

	// With scalar
	Matrix<T> res { *(this->m_a) };
	res *= this->m_s;
	return res;
}

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_MULTIPLICATION_CPP

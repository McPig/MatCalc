#ifndef MATCAL_TRANSPOSITION_CPP
#define MATCAL_TRANSPOSITION_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Transposition.h"


template<typename T>
Transposition<T>::Transposition(const Matrix<T> * a):
	Operation<T>(a)
{}


template<typename T>
Matrix<T> Transposition<T>::result() {
	size_t rows { this->m_a->rows_num() };
	size_t cols { this->m_a->cols_num() };

	std::vector<T> r_vec;

	for (size_t c {0}; c < cols; ++c)
		for (size_t r {0}; r < rows; ++r)
			r_vec.push_back(this->m_a->at(r, c));

	Matrix<T> res {cols, rows, r_vec};
	return res;
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_TRANSPOSITION_CPP

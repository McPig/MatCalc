#ifndef MATCAL_MERGE_CPP
#define MATCAL_MERGE_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Merge.h"


template<typename T>
Merge<T>::Merge(const Matrix<T> * a, const Matrix<T> * b):
	Operation<T>(a, b)
{
	if (a->rows_num() != b->rows_num())
		throw std::invalid_argument("Merge: got matrices with incompatible sizes");
}


template<typename T>
Matrix<T> Merge<T>::result() {
	size_t rows { this->m_a->rows_num() };
	size_t a_cols { this->m_a->cols_num() };
	size_t b_cols { this->m_b->cols_num() };
	std::vector<T> items {};

	for (size_t r {0}; r < rows; ++r) {
		for (size_t c {0}; c < a_cols; ++c)
			items.push_back(this->m_a->at(r, c));
		for (size_t c {0}; c < b_cols; ++c)
			items.push_back(this->m_b->at(r, c));
	}

	Matrix<T> res {rows, a_cols + b_cols, items};
	return res;
}

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_MERGE_CPP

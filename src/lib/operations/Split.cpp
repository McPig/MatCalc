#ifndef MATCAL_SPLIT_CPP
#define MATCAL_SPLIT_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Split.h"


template<typename T>
Split<T>::Split(const Matrix<T> * a, size_t row, size_t col, size_t rows, size_t cols):
	Operation<T>(a),
	m_row  {row},
	m_col  {col},
	m_rows {rows},
	m_cols {cols}
{
	if (row + rows > a->rows_num() || col + cols > a->cols_num())
		std::out_of_range("Split: index out of range");
}


template<typename T>
Matrix<T> Split<T>::result() {
	std::vector<T> items {};
	for (size_t r {m_row}; r < m_row + m_rows; ++r)
		for (size_t c {m_col}; c < m_col + m_cols; ++c)
			items.push_back(this->m_a->at(r, c));

	Matrix<T> res {m_rows, m_cols, items};
	return res;
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_SPLIT_CPP

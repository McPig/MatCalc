#ifndef MATCAL_SPLIT_H
#define MATCAL_SPLIT_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"
#include "Operation.h"

#include <stdexcept>
#include <vector>


/**
 * Performs split operation on Matrix.
 * @tparam T The type of Matrix.
 */
template<typename T>
class Split : public Operation<T> {
private:
	size_t m_row, m_col;
	size_t m_rows, m_cols;

public:
	/**
	 * Creates Split with given parameters.
	 * @param a The matrix to split.
	 * @param row The start row index.
	 * @param col The start column index.
	 * @param rows The number of rows.
	 * @param cols The number of columns.
	 */
	Split(const Matrix<T> * a, size_t row, size_t col, size_t rows, size_t cols);

	/**
	 * Splits Matrix.
	 * @return The sub-matrix.
	 */
	Matrix<T> result() override;
};


#include "Split.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_SPLIT_H

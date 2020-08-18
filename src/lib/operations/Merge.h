#ifndef MATCAL_MERGE_H
#define MATCAL_MERGE_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"
#include "Operation.h"

#include <stdexcept>
#include <vector>


/**
 * @brief Performs merging operation on its operands.
 * @tparam T The type of operands.
 */
template<typename T>
class Merge : public Operation<T> {
public:
	/**
	 * @brief Constructs Merge from two pointers to Matrix'es.
	 * @param a The pointer to Matrix of type T.
	 * @param b The pointer to Matrix of type T.
	 */
	Merge(const Matrix<T> * a, const Matrix<T> * b);

	/**
	 * @brief Performs merging operation.
	 * @return New Matrix as a result of merging.
	 */
	Matrix<T> result() override;
};


#include "Merge.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_MERGE_H

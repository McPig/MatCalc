#ifndef MATCAL_ADDITION_H
#define MATCAL_ADDITION_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"
#include "Operation.h"


/**
 * @brief Performs addition operation on its operands.
 * @tparam T The type of operands.
 */
template<typename T>
class Addition : public Operation<T> {
public:
	/**
	 * @brief Constructs Addition from two pointers to Matrix'es.
	 * @param a The pointer to Matrix of type T.
	 * @param b The pointer to Matrix of type T.
	 */
	Addition(const Matrix<T> * a, const Matrix<T> * b);

	/**
	 * @brief Constructs Addition from a pointer to Matrix and type T.
	 * @param a The pointer to Matrix of type T.
	 * @param s The scalar value of type T.
	 */
	Addition(const Matrix<T> * a, T s);

	/**
	 * @brief Performs addition operation.
	 * @return New Matrix as a result of addition.
	 */
	Matrix<T> result() override;
};


#include "Addition.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_ADDITION_H

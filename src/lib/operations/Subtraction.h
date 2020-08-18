#ifndef MATCAL_SUBTRACTION_H
#define MATCAL_SUBTRACTION_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"
#include "Operation.h"


/**
 * @brief Performs subtraction operation on its operands.
 * @tparam T The type of operands.
 */
template<typename T>
class Subtraction : public Operation<T> {
public:
	/**
	 * @brief Constructs Subtraction from two pointers to Matrix'es.
	 * @param a The pointer to Matrix of type T.
	 * @param b The pointer to Matrix of type T.
	 */
	Subtraction(const Matrix<T> * a, const Matrix<T> * b);

	/**
	 * @brief Constructs Subtraction from a pointer to Matrix and type T.
	 * @param a The pointer to Matrix of type T.
	 * @param s The scalar value of type T.
	 */
	Subtraction(const Matrix<T> * a, T s);


	/**
	 * @brief Performs addition operation.
	 * @return New Matrix as a result of subtraction.
	 */
	Matrix<T> result() override;
};


#include "Subtraction.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_SUBTRACTION_H

#ifndef MATCAL_MULTIPLICATION_H
#define MATCAL_MULTIPLICATION_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"
#include "Operation.h"

#include <stdexcept>


/**
 * @brief Performs multiplication operation on its operands.
 * @tparam T The type of operands.
 */
template<typename T>
class Multiplication : public Operation<T> {
public:
	/**
	 * @brief Constructs Multiplication from two pointers to Matrix'es.
	 * @param a The pointer to Matrix of type T.
	 * @param b The pointer to Matrix of type T.
	 * @throw std::invalid_argument in case of Matrix size mismatch.
	 */
	Multiplication(const Matrix<T> * a, const Matrix<T> * b);

	/**
	 * @brief Constructs Multiplication from a pointer to Matrix and type T.
	 * @param a The pointer to Matrix of type T.
	 * @param s The scalar value of type T.
	 */
	Multiplication(const Matrix<T> * a, T s);

	/**
	 * @brief Performs multiplication operation.
	 * @return New Matrix as a result of multiplication.
	 */
	Matrix<T> result() override;
};


#include "Multiplication.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_MULTIPLICATION_H

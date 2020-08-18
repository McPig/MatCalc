#ifndef MATCAL_OPERATION_H
#define MATCAL_OPERATION_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"

#include <memory>


/**
 * @brief Operation is a base abstract class for any operation on Matrix that requires creation of new Matrix.
 *
 * It also can be used to perform operations on the Matrix itself in case these operations are more complex than those
 * already implemented in Matrix class (such as += operator).
 * @tparam T The type of Operation operands.
 */
template<typename T>
class Operation {
protected:
	// ----------------
	// Member variables
	// ----------------
	const Matrix<T> * m_a;  // the first matrix
	const Matrix<T> * m_b;  // the second matrix (optional)
	T m_s;                  // the scalar (optional)


	// ------------
	// Constructors
	// ------------
	/**
	 * @brief Constructs Operation from pointer to Matrix.
	 * @param[in] a The pointer to Matrix of type T.
	 */
	explicit Operation(const Matrix<T> * a);

	/**
	 * @brief Constructs Operation from pointers to Matrix'es.
	 * @param[in] a The pointer to Matrix of type T.
	 * @param[in] b The pointer to Matrix of type T.
	 */
	Operation(const Matrix<T> * a, const Matrix<T> * b);

	/**
	 * @brief Constructs Operation from pointer to Matrix and type T.
	 * @param[in] a The pointer to Matrix of type T.
	 * @param[in] s The scalar value of type T.
	 */
	Operation(const Matrix<T> * a, T s);

public:
	// -------
	// Methods
	// -------
	/**
	 * @brief Computes the result of the operation. This method is pure virtual.
	 * @return
	 */
	virtual Matrix<T> result() = 0;
};


#include "Operation.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_OPERATION_H

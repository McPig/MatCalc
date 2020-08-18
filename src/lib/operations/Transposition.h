#ifndef MATCAL_TRANSPOSITION_H
#define MATCAL_TRANSPOSITION_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"
#include "Operation.h"

#include <stdexcept>
#include <vector>


/**
 * @brief Performs operation of transposition on its operand.
 * @tparam T The type of operand.
 */
template<typename T>
class Transposition : public Operation<T> {
public:
	/**
	 * @brief Constructs Transposition from a pointer to Matrix.
	 * @param a The pointer to Matrix of type T.
	 */
	explicit Transposition(const Matrix<T> * a);

	/**
	 * @brief Performs transposition.
	 * @return New transposed Matrix.
	 */
	Matrix<T> result() override;
};


#include "Transposition.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_TRANSPOSITION_H

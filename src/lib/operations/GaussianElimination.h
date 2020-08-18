#ifndef MATCAL_GAUSSIANELIMINATION_H
#define MATCAL_GAUSSIANELIMINATION_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"
#include "Operation.h"

#include <stdexcept>
#include <vector>
#include <cmath>
#include <iostream>


/**
 * @brief Solves the system of equations using Gaussian elimination.
 * @tparam T The type of operands.
 */
template<typename T>
class GaussianElimination : public Operation<T> {
private:
	std::vector<std::vector<T>> m_equations;

public:
	/**
	 * @brief Constructs GaussianElimination from two pointers to Matrix'es.
	 * @param a The pointer to Matrix of type T.
	 * @param b The pointer to Matrix of type T that represent vector with constants.
	 * @throw std::invalid_argument exception in case of Matrix size mismatch.
	 */
	GaussianElimination(const Matrix<T> * a, const Matrix<T> * b);

	/**
	 * Equations getter.
	 * @return Vector of vectors which represent triangular matrix.
	 */
	std::vector<std::vector<T>> equations() const;

	/**
	 * @brief Eliminate Matrix. Triangular form.
	 */
	void eliminate();

	/**
	 * Solves the system of equations.
	 * @return std::vector with found solutions.
	 */
	std::vector<T> solve();

	/**
	 * Returns Matrix that represents vector of found solutions.
	 * @return Matrix of type T.
	 */
	Matrix<T> result() override;
};


#include "GaussianElimination.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_GAUSSIANELIMINATION_H

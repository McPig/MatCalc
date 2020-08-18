#ifndef MATCAL_DETERMINANT_H
#define MATCAL_DETERMINANT_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"
#include "Operation.h"

#include <stdexcept>


template<typename T>
class Determinant : public Operation<T> {
public:
	explicit Determinant(const Matrix<T> * a);

	void cofactors(Matrix<T> & m, Matrix<T> & tmp, int p, int c, int n);

	T determinant(Matrix<T> & m, int n);

	Matrix<T> result() override;
};


#include "Determinant.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_DETERMINANT_H

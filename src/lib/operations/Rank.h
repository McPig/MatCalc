#ifndef MATCAL_RANK_H
#define MATCAL_RANK_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../matrices/Matrix.h"
#include "Operation.h"
#include "GaussianElimination.h"


template<typename T>
class Rank : public Operation<T> {
public:
	explicit Rank(const Matrix<T> * a);

	Matrix<T> result() override;
};


#include "Rank.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_RANK_H

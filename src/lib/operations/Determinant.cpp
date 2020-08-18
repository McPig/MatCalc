#ifndef MATCAL_DETERMINANT_CPP
#define MATCAL_DETERMINANT_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Determinant.h"

template<typename T>
Determinant<T>::Determinant(const Matrix<T> * a):
	Operation<T>(a)
{
	if (a->rows_num() != a->cols_num())
		throw std::invalid_argument("Determinant: given matrix is not square matrix");
}


template<typename T>
void Determinant<T>::cofactors(Matrix<T> & m, Matrix<T> & tmp, int p, int q, int n) {
	int i {};
	int j {};

	for (size_t r {}; r < (size_t) n; ++r)
		for (size_t c {}; c < (size_t) n; ++c) {
			if (r != (size_t) p && c != (size_t) q) {
				tmp.at(i, j++) = m.at(r, c);

				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
}


template<typename T>
T Determinant<T>::determinant(Matrix<T> & m, int n) {
	if (n == 1)
		return m.at(0, 0);

	T det {};
	Matrix<T> tmp(n, n);

	int sign = 1;
	for (size_t c {0}; c < (size_t) n; ++c) {
		cofactors(m, tmp, 0, c, n);
		det += sign * m.at(0, c) * determinant(tmp, n - 1);
		sign -= sign;
	}

	return det;
}


template<typename T>
Matrix<T> Determinant<T>::result() {
	Matrix<T> mat { *(this->m_a) };
	T d = determinant(mat, mat.rows_num());
	Matrix<T> res {1, 1, d};
	return res;
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_DETERMINANT_CPP

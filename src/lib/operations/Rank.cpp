#ifndef MATCAL_RANK_CPP
#define MATCAL_RANK_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Rank.h"


template<typename T>
Rank<T>::Rank(const Matrix<T> * a):
	Operation<T>(a)
{}


template<typename T>
Matrix<T> Rank<T>::result() {
	Matrix<T> b {this->m_a->rows_num(), 1, 0};

	GaussianElimination<T> gem {this->m_a, &b};
	gem.eliminate();
	std::vector<std::vector<T>> eq {gem.equations()};

	size_t rows { eq.size() };
	size_t cols { eq.at(0).size() };
	T rank {0};
	for (size_t r {0}; r < rows; ++r)
		for (size_t c {0}; c < cols; ++c)
			if (eq.at(r).at(c) != 0) {
				rank++;
				break;
			}

	Matrix<T> res {1, 1, rank};
	return res;
}

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_RANK_CPP

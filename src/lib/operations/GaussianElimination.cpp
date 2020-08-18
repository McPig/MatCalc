#ifndef MATCAL_GAUSSIANELIMINATION_CPP
#define MATCAL_GAUSSIANELIMINATION_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "GaussianElimination.h"


template<typename T>
GaussianElimination<T>::GaussianElimination(const Matrix<T> * a, const Matrix<T> * b):
	Operation<T>(a, b),
	m_equations(a->rows_num(), std::vector<T>(a->cols_num() + 1, 0))
{
	if (a->rows_num() != b->rows_num() || b->cols_num() != 1 || a->rows_num() + 1 != a->cols_num() + b->cols_num())
		throw std::invalid_argument("GaussianElimination: got matrices with incompatible sizes");

	for (size_t r {0}; r < a->rows_num(); ++r)
		for (size_t c {0}; c < a->cols_num() + 1; ++c)
			if (c + 1 != a->cols_num() + 1)
				m_equations.at(r).at(c) = a->at(r, c);
			else
				m_equations.at(r).at(c) = b->at(r, 0);
}


template<typename T>
std::vector<std::vector<T>> GaussianElimination<T>::equations() const {
	return m_equations;
}


template<typename T>
void GaussianElimination<T>::eliminate() {
	size_t n{m_equations.size()};
	for (size_t r{0}; r < n; ++r) {
		// Find max item in current column
		T max = abs(m_equations.at(r).at(r));
		size_t max_row = r;
		for (size_t c{r + 1}; c < n; ++c)
			if (abs(m_equations.at(c).at(r)) > max) {
				max = abs(m_equations.at(c).at(r));
				max_row = c;
			}
		// Row swap item by item
		for (size_t c{r}; c < n + 1; ++c) {
			T tmp = m_equations.at(max_row).at(c);
			m_equations.at(max_row).at(c) = m_equations.at(r).at(c);
			m_equations.at(r).at(c) = tmp;
		}
		// Triangular form
		for (size_t c{r + 1}; c < n; ++c) {
			T item = -m_equations.at(c).at(r) / m_equations.at(r).at(r);
			for (size_t j{r}; j < n + 1; ++j)
				if (r == j)
					m_equations.at(c).at(j) = 0;
				else
					m_equations.at(c).at(j) += item * m_equations.at(r).at(j);
		}
	}
}


template<typename T>
std::vector<T> GaussianElimination<T>::solve() {
	eliminate();

	size_t n { m_equations.size() };

	// Solve equations
	std::vector<T> res_vec(n);

	for (long r = n - 1; r >= 0; --r) {
		res_vec.at(r) = m_equations.at(r).at(n) / m_equations.at(r).at(r);
		for (long c = r - 1; c >= 0; --c)
			m_equations.at(c).at(n) -= m_equations.at(c).at(r) * res_vec.at(r);
	}

	return res_vec;
}


template<typename T>
Matrix<T> GaussianElimination<T>::result() {
	std::vector<T> r(solve());
	Matrix<T> res(1, r.size(), r);
	return res;
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_GAUSSIANELIMINATION_CPP

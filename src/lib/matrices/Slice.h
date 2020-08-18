#ifndef MATCAL_SLICE_H
#define MATCAL_SLICE_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include <stdexcept>
#include <sstream>
#include <utility>


/**
 * @brief Slice is an abstraction that allows to manipulate a one-dimensional array as a matrix.
 *
 * The class is a simplified version of std::gslice. It describes a mapping from non-negative integer values
 * (subscripts) to indices. Slice is capable of describing rows, columns and more complex structures (such as
 * sub-matrices) in terms of three values: starting index, pair of lengths, pair of strides.
 */
struct Slice {
	// ----------
	// Type alias
	// ----------
	using Container = std::pair<size_t, size_t>;

	// ----------------
	// Member variables
	// ----------------
	size_t    m_start {};  // first index
	Container m_sizes;     // number of indices included (first for rows, second for columns)
	Container m_strides;   // pair of distances between elements in sequence (first for rows, second for columns)

	// ------------
	// Constructors
	// ------------
	/**
	 * @brief Slice constructor for empty matrices.
	 */
	Slice() = default;

	/**
	 * @brief Constructs Slice with the given parameters.
	 * @param[in] start The index of the first element.
	 * @param[in] sizes The pair of lengths. The first for rows, the second for columns.
	 * @param[in] strides The pair of distances between elements in sequence. The first for rows, the second for
	 * columns.
	 */
	Slice(size_t start, Container sizes, Container strides);

	// ---------
	// Subscript
	// ---------
	/**
	 * @brief Maps the given row and column indices to the actual index within one-dimensional array.
	 * @param[in] row The row to subscript.
	 * @param[in] column The column to subscript.
	 * @return An actual index from a one-dimensional array.
	 * @throw std::out_of_range exception if row or column are not valid indices.
	 */
	size_t at(size_t row, size_t column) const;
};

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_SLICE_H

#ifndef MATCAL_BASEMATRIX_H
#define MATCAL_BASEMATRIX_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Slice.h"

#include <ostream>


/**
 * @brief BaseMatrix is a base for matrix-like classes.
 *
 * It is an abstract class that does not hold any items but describes the matrix shape (number of rows and columns).
 * @tparam T The type of matrix items.
 */
template<typename T>
class BaseMatrix {
protected:
	// ----------------
	// Member variables
	// ----------------
	Slice m_desc;        // descriptor of the Matrix shape (number of rows and columns)

	// ------------
	// Constructors
	// ------------
	/**
	 * @brief Constructs BaseMatrix from Slice.
	 * @param[in] descriptor The descriptor to construct BaseMatrix from.
	 */
	explicit BaseMatrix(Slice descriptor);

	/**
	 * @brief Constructs BaseMatrix with the given parameters.
	 * @param rows The number of rows.
	 * @param columns The number of columns.
	 */
	BaseMatrix(size_t rows, size_t columns);

public:
	/**
	 * @brief Constructor for empty BaseMatrix.
	 */
	BaseMatrix() = default;

	/**
	 * @brief Default copy constructor.
	 */
	BaseMatrix(const BaseMatrix &) = default;

	/**
	 * @brief Default move constructor.
	 */
	BaseMatrix(BaseMatrix &&) noexcept = default;

	// ----------
	// Assignment
	// ----------
	/**
	 * @brief Default copy assignment.
	 * @return Reference to *this.
	 */
	BaseMatrix<T> & operator=(const BaseMatrix &) = default;

	/**
	 * @brief Default move assignment.
	 * @return Reference to *this.
	 */
	BaseMatrix<T> & operator=(BaseMatrix &&) noexcept = default;

	// ----------
	// Destructor
	// ----------
	/**
	 * @brief Default destructor.
	 */
	virtual ~BaseMatrix() = default;

	// ---------
	// Accessors
	// ---------
	/**
	 * @brief Returns matrix descriptor.
	 * @return Slice describing matrix shape.
	 */
	const Slice & desc() const;

	/**
	 * @brief Returns the number of matrix rows.
	 * @return The number of rows.
	 */
	size_t rows_num() const;

	/**
	 * @brief Returns the number of matrix columns.
	 * @return The number of columns.
	 */
	size_t cols_num() const;

	/**
	 * @brief Returns the total number of matrix items.
	 * @return The Total number of items.
	 */
	size_t size() const;

	/**
	 * @brief Provides direct access to the matrix items.
	 *
	 * Since derived classes may use different kinds of items storage this method is pure virtual.
	 * @return Pointer to the first item of the matrix.
	 */
	virtual T * data() = 0;

	/**
	 * @brief Provides direct access to the matrix items. Prohibits object modification.
	 *
	 * Since derived classes may use different kinds of items storage this method is pure virtual.
	 * @return Pointer to the first item of the matrix.
	 */
	virtual const T * data() const = 0;

	// ---------
	// Subscript
	// ---------
	/**
	 * @brief Provides direct subscript access to the item stored at position (row, col).
	 * @param[in] row The row index to subscript.
	 * @param[in] column The column index to subscript.
	 * @return Reference to the item stored at position (row, col).
	 */
	T & at(size_t row, size_t column);

	/**
	 * @brief Provides direct subscript access to the item stored at position (row, col). Prohibits object modification.
	 * @param row The row index to subscript.
	 * @param column The column index to subscript.
	 * @return Reference to the item stored at position (row, col).
	 */
	const T & at(size_t row, size_t column) const;
};


// --------------------
// Non-member functions
// --------------------
template<typename T>
std::ostream & operator<<(std::ostream & os, const BaseMatrix<T> & matrix);


#include "BaseMatrix.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_BASEMATRIX_H


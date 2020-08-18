#ifndef MATCAL_MATRIX_H
#define MATCAL_MATRIX_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Slice.h"
#include "BaseMatrix.h"

#include <stdexcept>
#include <sstream>
#include <vector>


/**
 * @brief Matrix is a container that stores items of arbitrary type.
 *
 * The class provides iterators and some primitive arithmetic operations available through overloaded operators. All
 * operations are applied on the Matrix itself (*this).
 * @tparam T The type of the Matrix items.
 */
template<typename T>
class Matrix : public BaseMatrix<T> {
private:
	// ----------------
	// Member variables
	// ----------------
	std::vector<T> m_items;  // matrix items

public:
	// ------------
	// Type aliases
	// ------------
	using iterator = typename std::vector<T>::iterator;
	using const_iterator = typename std::vector<T>::const_iterator;

	// ------------
	// Constructors
	// ------------
	/**
	 * @brief Default constructor for empty Matrix.
	 */
	Matrix() = default;

	/**
	 * @brief Default copy constructor.
	 */
	Matrix(const Matrix &) = default;

	/**
	 * @brief Default move constructor.
	 */
	Matrix(Matrix &&) noexcept = default;

	/**
	 * @brief Constructs Matrix with the given parameters.
	 * @param[in] rows The number of rows.
	 * @param[in] columns The number of columns.
	 */
	Matrix(size_t rows, size_t columns);

	/**
	 * @brief Constructs Matrix with the given parameters.
	 * @param[in] rows The number of rows.
	 * @param[in] cols The number of columns.
	 * @param[in] items The items to store in Matrix.
	 * @throw std::length_error exception in case of size mismatch.
	 */
	Matrix(size_t rows, size_t columns, std::vector<T> items);

	/**
	 * @brief Constructs Matrix with the given parameters.
	 * @param[in] rows The number of rows.
	 * @param[in] cols The number of columns.
	 * @param[in] elem The item to fill Matrix with.
	 */
	Matrix(size_t rows, size_t columns, const T & item);

	// ----------
	// Assignment
	// ----------
	/**
	 * @brief Default copy assignment.
	 * @return Reference to *this.
	 */
	Matrix & operator=(const Matrix &) = default;

	/**
	 * @brief Default move assignment.
	 * @return Reference to *this.
	 */
	Matrix & operator=(Matrix &&) noexcept = default;

	// ----------
	// Destructor
	// ----------
	/**
	 * @brief Default destructor.
	 */
	~Matrix() override = default;

	// ---------
	// Accessors
	// ---------
	/**
	 * @brief Provides direct access to the Matrix items.
	 * @return Pointer to the first item of the Matrix.
	 */
	T * data() override;

	/**
	 * @brief Provides direct access to the Matrix items. Prohibits object modification.
	 * @return Pointer to the first item of the Matrix.
	 */
	const T * data() const override;

	/**
	 * @brief Applies the given function to each item of the Matrix.
	 * @tparam F Any type that can be considered a function or a function object and can take a parameter of type T.
	 * @param func The function to apply.
	 * @return Reference to *this.
	 */
	template<typename F>
	Matrix & apply(F func);

	/**
	 * @brief Applies the given function with corresponding item from passed Matrix to each item of *this.
	 * @tparam F Any type that can be considered a function or a function object and can take two parameters of type T.
	 * The first to apply operation on and the second to apply operation with.
	 * @param matrix The Matrix with corresponding rows and columns sizes.
	 * @param func The function to apply.
	 * @return Reference to *this.
	 */
	template<typename F>
	Matrix & apply(F func, const Matrix & matrix);


	// ---------
	// Iterators
	// ---------
	/**
	 * @brief Returns an iterator pointing to the first item in the storage.
	 * @return iterator to beginning.
	 */
	iterator begin();

	/**
	 * @brief Returns a const_iterator pointing to the first item in the storage.
	 * @return const_iterator to beginning.
	 */
	const_iterator begin() const;

	/**
	 * @brief Returns an iterator referring to the past-the-end item in the storage.
	 * @return iterator to end.
	 */
	iterator end();

	/**
	 * @brief Returns a const_iterator pointing to the past-the-end item in the storage.
	 * @return const_iterator to end.
	 */
	const_iterator end() const;


	// --------------------
	// Primitive arithmetic
	// --------------------
	/**
	 * @brief Adds the value passed as a parameter to each item of the Matrix.
	 * @param scalar The value to add.
	 * @return Reference to *this.
	 */
	Matrix & operator+=(const T & scalar);

	/**
	 * @brief Adds the given Matrix to *this.
	 * @param matrix The matrix to add.
	 * @return Reference to *this.
	 */
	Matrix & operator+=(const Matrix & matrix);

	/**
	 * @brief Subtracts the value passed as a parameter from each item of the Matrix.
	 * @param scalar The value to subtract.
	 * @return Reference to *this.
	 */
	Matrix & operator-=(const T & scalar);

	/**
	 * @brief Subtracts the given Matrix from *this.
	 * @param matrix The matrix to subtract.
	 * @return Reference to *this.
	 */
	Matrix & operator-=(const Matrix & matrix);

	/**
	 * @brief Multiplies each item of the Matrix by the value passed as a parameter.
	 * @param scalar The value to multiply by.
	 * @return Reference to *this.
	 */
	Matrix & operator*=(const T & scalar);

	/**
	 * @brief Divides each item of the Matrix with the value passed as a parameter.
	 * @param scalar The value to divide with.
	 * @return Reference to *this.
	 */
	Matrix & operator/=(const T & scalar);

	/**
	 * @brief Performs modulo operation on each item of the Matrix with the value passed as a parameter.
	 * @param scalar The value to perform modulo operation with.
	 * @return Reference to *this.
	 */
	Matrix & operator%=(const T & scalar);
};


#include "Matrix.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_MATRIX_H

#ifndef MATCAL_FMATRIX_H
#define MATCAL_FMATRIX_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "BaseMatrix.h"


/**
 * @brief Represents matrix filled with one item.
 * @tparam T The type of item.
 */
template<typename T>
class FMatrix : public BaseMatrix<T> {
private:
	T m_item;

public:
	/**
	 * @brief Default constructor.
	 */
	FMatrix() = default;

	/**
	 * @brief Default copy constructor.
	 */
	FMatrix(const FMatrix &) = default;

	/**
	 * @brief Default move constructor.
	 */
	FMatrix(FMatrix &&) noexcept = default;

	/**
	 * @brief Constructs FMatrix with given parameters.
	 * @param rows The number of rows.
	 * @param cols The number of columns.
	 * @param item The item.
	 */
	FMatrix(size_t rows, size_t cols, const T & item);

	/**
	 * @brief Default copy assignment.
	 * @return
	 */
	FMatrix<T> & operator=(const FMatrix &) = default;

	/** @brief Default move assignment
	 *
	 * @return Reference to *this.
	 */
	FMatrix<T> & operator=(FMatrix &&) noexcept = default;

	/**
	 * Default destructor.
	 */
	~FMatrix() override = default;

	/**
	 * Direct data access.
	 * @return Reference to *this.
	 */
	T * data() override;

	/**
	 * Direct const data access.
	 * @return Reference to *this.
	 */
	const T * data() const override;
};


#include "FMatrix.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_FMATRIX_H

#ifndef MATCAL_TABLE_H
#define MATCAL_TABLE_H
/* ------------------------------------------------------------------------------------------------------------------ */


#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <memory>


/**
 * @brief Abstract class which represents one cell in the table.
 */
class Cell {
protected:
	size_t m_width;
	size_t m_height;
	Cell();

public:
	/**
	 * @brief Width getter.
	 * @return Actual width (number of characters) of cell.
	 */
	size_t GetWidth() const;

	/**
	 * @brief Height getter.
	 * @return Actual height (number of lines) of cell.
	 */
	size_t GetHeight() const;

	virtual ~Cell() = default;

	/**
	 * @brief Prints content of the cell. Pure virtual method. To be implemented in subclasses.
	 * @param[in, out] os The output stream to print cell to.
	 * @param[in] max_width The max width of some cell in the current column.
	 * @param[in] max_height The max height of some cell in the current row.
	 * @param[in] line_num The number of lines in the cell.
	 * @return ostream (function argument os) for output chaining.
	 */
	virtual std::ostream & Print(std::ostream & os, size_t & max_width, size_t & max_height, size_t & line_num) const = 0;

	/**
	 * @brief Creates clone of the cell (deep copy).
	 * @return Unique pointer to the newly created copy of the cell.
	 */
	virtual std::unique_ptr<Cell> Clone() const = 0;
};


/**
 * @brief Represents table which contains some text.
 */
class Text : public Cell {
public:
	enum EAlign {ALIGN_LEFT, ALIGN_RIGHT};

	/**
	 * @brief Text constructor.
	 * @param[in] str The text which will be added to the cell.
	 * @param[in] alignment The text alignment
	 */
	Text(const std::string & str, const EAlign & alignment);

	/**
	 * @brief Text setter.
	 * @param[in] str The text to add to the cell.
	 */
	void SetText(const std::string & str);

	/**
	 * @brief Overridden version of Print for cell containing text. See Cell::Print for more information.
	 */
	std::ostream & Print(std::ostream & os, size_t & max_width, size_t & max_height, size_t & line_num) const override;

	/**
	 * @brief Overridden version of Clone. See Cell::Clone for more information.
	 */
	std::unique_ptr<Cell> Clone() const override;

private:
	std::vector<std::string> m_text;
	EAlign         m_align;

	/**
	 * @brief Parses string and splits it by EOL to vector of lines.
	 * @param[in] str The string to parse.
	 * @return Vector of lines.
	 */
	std::vector<std::string> ParseStr(const std::string & str);
};


/**
 * @brief Represents an empty cell.
 */
class Empty : public Cell {
public:
	Empty();

	/**
	 * @brief Overridden version of Print for empty cell. See CCell::Print for more information.
	 */
	std::ostream & Print(std::ostream & os, size_t & max_width, size_t & max_height, size_t & line_num) const override;

	/**
	 * @brief Overridden version of Clone. See CCell::Clone for more information.
	 */
	std::unique_ptr<Cell> Clone() const override;
};


/**
 * @brief Represents the whole table.
 */
class Table {
private:
	size_t m_rows;
	size_t m_cols;
	std::vector< std::vector<std::unique_ptr<Cell>> > m_data;

	/**
	 * Creates the row delimiter for table.
	 * @param[in] cols The number of columns.
	 * @param[in] max_widths Vector with max widths of every table column.
	 * @return Row delimiter.
	 */
	std::string CreateRowDelim(size_t cols, const std::vector<size_t> & max_widths) const;

public:
	/**
	 * @brief Table constructor.
	 * @param[in] rows The number of rows.
	 * @param[in] cols The number of columns.
	 */
	Table(size_t rows, size_t cols);

	Table(const Table & table);
	Table & operator=(const Table & table);

	/**
	 * Cell getter.
	 * @param row Row index of the table.
	 * @param col Column index of the table.
	 * @return The cell in the given row and column.
	 */
	Cell & GetCell(size_t row, size_t col);

	/**
	 * Cell setter.
	 * @param row Row index of the table.
	 * @param col Column index of the table.
	 * @param content The cell to copy.
	 */
	void SetCell(size_t row, size_t col, const Cell & content);

	/**
	 * Prints the whole table to output stream.
	 * @param os The output stream to print table to.
	 * @return Function argument os for method chaining.
	 */
	std::ostream & Print(std::ostream & os) const;

	/**
	 * Prints the whole table to output stream using function Table::Print
	 * @param os The output stream.
	 * @param table The table to print.
	 * @return The output stream.
	 */
	friend std::ostream & operator<<(std::ostream & os, const Table & table);
};

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_TABLE_H

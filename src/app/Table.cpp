#include "Table.h"

/* --------------------------------------------------- Cell -------------------------------------------------------- */

Cell::Cell():
		m_width  {},
		m_height {}
{}

size_t Cell::GetWidth() const {
	return m_width;
}

size_t Cell::GetHeight() const {
	return m_height;
}


/* --------------------------------------------------- Text -------------------------------------------------------- */

Text::Text(const std::string & str, const Text::EAlign & alignment):
		Cell(),
		m_text  {ParseStr(str)},
		m_align {alignment}
{}

void Text::SetText(const std::string & str) {
	m_text = ParseStr(str);
}

std::vector<std::string> Text::ParseStr(const std::string & str) {
	std::vector<std::string> res {};
	std::istringstream iss(str);
	std::string line;
	size_t len {};

	while (std::getline(iss, line)) {
		if (line.length() > len)
			len = line.length();
		res.push_back(move(line));
	}

	m_width = len;
	m_height = res.size();
	return res;
}

std::ostream & Text::Print(std::ostream & os, size_t & max_width, size_t &, size_t & line_num) const {
	if (line_num >= m_height) {  // add empty lines at the end of cell
		std::string spaces(max_width, ' ');
		return os << spaces;
	}
	size_t space_size {max_width - m_text.at(line_num).length()};
	std::string spaces(space_size, ' ');
	if (m_align == ALIGN_LEFT) {
		return os << m_text.at(line_num) << spaces;
	}
	/* ALIGN_RIGHT */
	return os << spaces << m_text.at(line_num);
}

std::unique_ptr<Cell> Text::Clone() const {
	return std::make_unique<Text>(*this);
}

/* -------------------------------------------------- Empty -------------------------------------------------------- */

Empty::Empty():
	Cell()
{}

std::ostream & Empty::Print(std::ostream & os, size_t & max_width, size_t &, size_t &) const {
	std::string spaces(max_width, ' ');
	return os << spaces;
}

std::unique_ptr<Cell> Empty::Clone() const {
	return std::make_unique<Empty>(*this);
}

/* -------------------------------------------------- Table -------------------------------------------------------- */

Table::Table(size_t rows, size_t cols):
		m_rows {rows},
		m_cols {cols},
		m_data {}
{
	for (size_t r = 0; r < rows; ++r) {
		std::vector<std::unique_ptr<Cell>> tmp;
		m_data.push_back(move(tmp));
		for (size_t c = 0; c < cols; ++c)
			m_data.at(r).push_back(Empty().Clone());
	}
}

Table::Table(const Table & table):
		m_rows {table.m_rows},
		m_cols {table.m_cols},
		m_data {}
{
	for (size_t r = 0; r < m_rows; ++r) {
		std::vector<std::unique_ptr<Cell>> tmp;
		m_data.push_back(move(tmp));
		for (size_t c = 0; c < m_cols; ++c)
			m_data.at(r).push_back(table.m_data.at(r).at(c)->Clone());
	}
}

Table & Table::operator=(const Table & table) {
	if (this == &table)
		return *this;

	m_data.clear();
	m_rows = table.m_rows;
	m_cols = table.m_cols;

	for (size_t r = 0; r < m_rows; ++r) {
		std::vector<std::unique_ptr<Cell>> tmp;
		m_data.push_back(move(tmp));
		for (size_t c = 0; c < m_cols; ++c)
			m_data.at(r).push_back(table.m_data.at(r).at(c)->Clone());
	}

	return *this;
}

Cell & Table::GetCell(size_t row, size_t col) {
	return *m_data.at(row).at(col);
}

void Table::SetCell(size_t row, size_t col, const Cell & content) {
	m_data.at(row).at(col) = content.Clone();
}

std::string Table::CreateRowDelim(size_t cols, const std::vector<size_t> & max_widths) const {
	std::string res {"+"};

	for (size_t c = 0; c < cols; ++c) {
		std::string tmp(max_widths.at(c), '-');
		res.append(tmp + '+');
	}

	return res;
}

std::ostream & Table::Print(std::ostream & os) const {
	std::vector<size_t> max_widths{};  // max width for every column
	std::vector<size_t> max_heights{};  // max height for every row
	max_widths.resize(m_cols, 0);
	max_heights.resize(m_rows, 0);

	/* Find max widths and heights */
	for (size_t r = 0; r < m_rows; ++r)
		for (size_t c = 0; c < m_cols; ++c) {
			if (m_data.at(r).at(c)->GetHeight() > max_heights.at(r))
				max_heights.at(r) = m_data.at(r).at(c)->GetHeight();
			if (m_data.at(r).at(c)->GetWidth() > max_widths.at(c))
				max_widths.at(c) = m_data.at(r).at(c)->GetWidth();
		}

	/* Print every cell */
	std::string delim {CreateRowDelim(m_cols, max_widths)};
	for (size_t r = 0; r < m_rows; ++r) {
		os << delim << '\n';
		for (size_t line = 0; line < max_heights.at(r); ++line) {
			for (size_t c = 0; c < m_cols; ++c) {
				os << '|';
				m_data.at(r).at(c)->Print(os, max_widths.at(c), max_heights.at(r), line);
			}
			os << "|\n";
		}
	}
	os << delim << std::endl;

	return os;
}

std::ostream & operator<<(std::ostream & os, const Table & table) {
	return table.Print(os);
}
#include "Slice.h"

/* ----------------------------------------------------- Slice ----------------------------------------------------- */

Slice::Slice(size_t start, Container sizes, Container strides):
	m_start   { start },
	m_sizes   { std::move(sizes) },
	m_strides { std::move(strides) }
{}


size_t Slice::at(size_t row, size_t column) const {
	if (row < m_sizes.first && column < m_sizes.second)
		return m_start + row * m_strides.first + column * m_strides.second;

	std::stringstream ss;
	ss << "Slice: got indices (" << row << ", " << column << "), but the Slice size is (" << m_sizes.first << ", "
	   << m_sizes.second << ")";
	throw std::out_of_range(ss.str());
}

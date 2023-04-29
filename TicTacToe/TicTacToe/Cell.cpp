#include "Cell.h"

Cell::Cell()
{
	m_CellState = CellState::EMPTY;
}

Cell::Cell(CellState state)
{
	m_CellState = state;
}

Cell::~Cell()
{

}

void Cell::SetState(CellState state)
{
	m_CellState = state;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
	switch (cell.m_CellState)
	{
	case EMPTY:
		return os << " ";
		break;
	case CROSS:
		return os << "X";
		break;
	case ZERO:
		return os << "O";
		break;
	}
}

void Cell::Reset()
{
	m_CellState = CellState::EMPTY;
}
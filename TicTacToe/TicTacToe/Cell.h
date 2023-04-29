#pragma once
#include <ostream>
#include "CellState.h"

class Cell
{
public:
	Cell();

	Cell(CellState state);

	~Cell();

	void Reset();

	void SetState(CellState state);

	inline CellState GetState()
	{
		return m_CellState;
	}

	inline bool IsOccupied()
	{
		return m_CellState != CellState::EMPTY;
	}

	friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

private:
	CellState m_CellState;
};
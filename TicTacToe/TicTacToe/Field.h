#pragma once
#include <iostream>
#include "Cell.h"
#include "PlayerTeam.h"


using namespace std;

class Field
{
public:
	Field();

	~Field();

	void Clear();

	void Clear(CellState state);

	void PrintField();

	bool SetCellState(int n, CellState state);

	PlayerTeam CheckWinner();

	int CheckWinningPossibility(PlayerTeam team);

private:
	Cell m_Cells[9];
};
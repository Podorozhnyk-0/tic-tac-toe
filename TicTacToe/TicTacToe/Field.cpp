#include "PlayerTeam.h"
#include "Field.h"


Field::Field()
{
	for (size_t i = 0; i < 9; i++)
	{
		m_Cells[i].SetState(CellState::EMPTY);
	}
}

Field::~Field()
{
	for (size_t i = 0; i < 9; i++)
	{
		m_Cells[i].SetState(CellState::EMPTY);
	}
}

void Field::Clear()
{
	for (size_t i = 0; i < 9; i++)
	{
		m_Cells[i].SetState(CellState::EMPTY);
	}
}

void Field::Clear(CellState state)
{
	for (size_t i = 0; i < 9; i++)
	{
		m_Cells[i].SetState(state);
	}
}

void Field::PrintField()
{
	cout << " ___ ___ ___" << endl;
	cout << "| " << m_Cells[0] << " | " << m_Cells[1] << " | " << m_Cells[2] << " |" << endl;
	cout << "| " << m_Cells[3] << " | " << m_Cells[4] << " | " << m_Cells[5] << " |" << endl;
	cout << "| " << m_Cells[6] << " | " << m_Cells[7] << " | " << m_Cells[8] << " |" << endl;
	cout << " ——— ——— ———" << endl;
}

bool Field::SetCellState(int n, CellState state)
{
	if (m_Cells[n].IsOccupied()) return false;
	
	m_Cells[n].SetState(state);
	
	return true;
}

PlayerTeam Field::CheckWinner()
{
	PlayerTeam winner = PlayerTeam::NONE;
	bool hasWinner = false;
	for (size_t i = 0; i < 3; i++)
	{
		//горизонталь
		if (m_Cells[i * 3].GetState() == m_Cells[i * 3 + 1].GetState() && m_Cells[i * 3 + 1].GetState() == m_Cells[i * 3 + 2].GetState() && m_Cells[i * 3 + 1].GetState() != CellState::EMPTY)
		{
			winner = (PlayerTeam)m_Cells[i * 3].GetState();
			hasWinner = true;
			break;
		}
		//вертикаль
		else if(m_Cells[i].GetState() == m_Cells[i + 3].GetState() && m_Cells[i + 3].GetState() == m_Cells[i + 6].GetState() && m_Cells[i + 3].GetState() != CellState::EMPTY)
		{
			winner = (PlayerTeam)m_Cells[i].GetState();
			hasWinner = true;
			break;
		}
		//диагональ
		else if ((m_Cells[0].GetState() == m_Cells[4].GetState() && m_Cells[4].GetState() == m_Cells[8].GetState())
			|| (m_Cells[2].GetState() == m_Cells[4].GetState() && m_Cells[4].GetState() == m_Cells[6].GetState()) && m_Cells[4].GetState() != CellState::EMPTY)
		{
			winner = (PlayerTeam)m_Cells[4].GetState();
			hasWinner = true;
			break;
		}
	}
	if (!hasWinner)
	{
		bool allOccupied = true;
		for (size_t i = 0; i < 9; i++)
		{
			if (!m_Cells[i].IsOccupied())
			{
				allOccupied = false;
			}
		}
		if (allOccupied) winner = PlayerTeam::TIE;
	}
	return winner;
}

int Field::CheckWinningPossibility(PlayerTeam team)
{
	for (size_t i = 0; i < 3; i++)
	{
		//горизонталь
		if ((m_Cells[i * 3].GetState() == m_Cells[i * 3 + 1].GetState() && m_Cells[i * 3].GetState() == (CellState)team)
			|| (m_Cells[i * 3 + 1].GetState() == m_Cells[i * 3 + 2].GetState() && m_Cells[i * 3 + 1].GetState() == (CellState)team)
			|| (m_Cells[i * 3].GetState() == m_Cells[i * 3 + 2].GetState() && m_Cells[i * 3].GetState() == (CellState)team))
		{
			if (!m_Cells[i * 3].IsOccupied()) return i * 3;
			if (!m_Cells[i * 3 + 1].IsOccupied()) return i * 3 + 1;
			if (!m_Cells[i * 3 + 2].IsOccupied()) return i * 3 + 2;
		}
		//вертикаль
		else if ((m_Cells[i].GetState() == m_Cells[i + 3].GetState() && m_Cells[i].GetState() == (CellState)team)
			|| (m_Cells[i + 3].GetState() == m_Cells[i + 6].GetState() && m_Cells[i + 3].GetState() == (CellState)team)
			|| (m_Cells[i].GetState() == m_Cells[i + 6].GetState() && m_Cells[i].GetState() == (CellState)team))
		{
			if (!m_Cells[i].IsOccupied()) return i;
			if (!m_Cells[i + 3].IsOccupied()) return i + 3;
			if (!m_Cells[i + 6].IsOccupied()) return i + 6;
		}
		//диагональ 0-4-8
		else if ((m_Cells[0].GetState() == m_Cells[4].GetState() && m_Cells[0].GetState() == (CellState)team)
			|| (m_Cells[0].GetState() == m_Cells[8].GetState() && m_Cells[0].GetState() == (CellState)team)
			|| (m_Cells[4].GetState() == m_Cells[8].GetState() && m_Cells[4].GetState() == (CellState)team)
			)
				
		{
			if (!m_Cells[0].IsOccupied()) return 0;
			if (!m_Cells[4].IsOccupied()) return 4;
			if (!m_Cells[8].IsOccupied()) return 8;
		}
		//диагональ 2-4-6
		else if ((m_Cells[2].GetState() == m_Cells[4].GetState() && m_Cells[2].GetState() == (CellState)team)
			|| (m_Cells[2].GetState() == m_Cells[6].GetState() && m_Cells[2].GetState() == (CellState)team)
			|| (m_Cells[4].GetState() == m_Cells[6].GetState() && m_Cells[4].GetState() == (CellState)team)
			)

		{
			if (!m_Cells[2].IsOccupied()) return 2;
			if (!m_Cells[4].IsOccupied()) return 4;
			if (!m_Cells[6].IsOccupied()) return 6;
		}
	}
	return -1;
}

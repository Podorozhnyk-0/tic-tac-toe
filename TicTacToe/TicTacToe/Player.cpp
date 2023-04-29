#include "Player.h"
#include "Field.h"
#include "Utils.h"

Player::Player(bool isAi, int id, PlayerTeam team, Field& field) : m_Field(field)
{
	m_AI = isAi;
	m_ID = id;
	m_Team = team;
}

Player::~Player()
{
	
}

void Player::Move()
{
	if (m_Field.CheckWinner() == PlayerTeam::TIE) return;

	int cell;
	if (m_AI)
	{
		do
		{
			cell = m_Field.CheckWinningPossibility(m_Team);
			cout << cell << endl;
			if (cell == -1)
			{
				cell = m_Field.CheckWinningPossibility(GetOppositeTeam(m_Team));
				if (cell == -1)
				{
					if (!m_Field.SetCellState(4, (CellState)m_Team))
					{
						int rnd = rand() % 4;
						switch (rnd)
						{
						case 0:
							if (m_Field.SetCellState(0, (CellState)m_Team)) return;
							break;
						case 1:
							if (m_Field.SetCellState(2, (CellState)m_Team)) return;
							break;
						case 2:
							if (m_Field.SetCellState(6, (CellState)m_Team)) return;
							break;
						case 3:
							if (m_Field.SetCellState(8, (CellState)m_Team)) return;
							break;
						}
					}
					else return;

					cell = rand() % 9;
				}
			}
		} while (!m_Field.SetCellState(cell, (CellState)m_Team));
	}
	else
	{

		bool result;
		do
		{
			cell = AskInput<int>("Enter cell to move (1-9): ", "ERROR! Invalid data entered");

			result =  m_Field.SetCellState(cell - 1, (CellState)m_Team);

			if (cell < 1 || cell > 9 || !result)
			{
				cout << "ERROR! Invalid data entered" << endl;
			}
		} while (cell < 1 || cell > 9 || !result);
	}
}


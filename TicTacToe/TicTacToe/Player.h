#pragma once
#include "Field.h"
#include "PlayerTeam.h"


class Player
{
public:
	Player(bool isAi, int id, PlayerTeam type, Field& field);

	~Player();

	void Move();

	inline int GetId()
	{
		return m_ID;
	}

	inline bool IsAI()
	{
		return m_AI;
	}

	inline PlayerTeam GetPlayerTeam()
	{
		return m_Team;
	}

private:
	bool m_AI;
	int m_ID;
	PlayerTeam m_Team;
	Field& m_Field;
};
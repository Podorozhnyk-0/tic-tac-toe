#include "PlayerTeam.h"

PlayerTeam GetOppositeTeam(PlayerTeam team)
{
	if (team == PlayerTeam::CROSS_TEAM)
	{
		return PlayerTeam::ZERO_TEAM;
	}
	else
	{
		return PlayerTeam::CROSS_TEAM;
	}
}
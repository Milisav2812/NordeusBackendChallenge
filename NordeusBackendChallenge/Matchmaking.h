#pragma once
#include "Club.h"


class Matchmaking
{
public:

	std::vector<std::pair<Club, Club>> MatchPlayers(std::vector<Club> Players);

private:
	void PrintMatchmaking(const std::vector<std::pair<Club, Club>>& FinalMatching);
	
};
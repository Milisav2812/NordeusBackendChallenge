#include "Matchmaking.h"
#include <algorithm>
#include <iostream>

using namespace std;

std::vector<std::pair<Club, Club>> Matchmaking::MatchPlayers(std::vector<Club> Players)
{
	if (Players.size() < 2)
	{
		std::cout << "ERROR: Not enough players to match!" << std::endl;
		exit(1);
	}
	std::vector<std::pair<Club, Club>> FinalMatching;

	std::sort(Players.begin(), Players.end());

	int Size = (Players.size() % 2 == 0) ? Players.size() : ( Players.size() - 1 );

	for (int i = 0; i < Size; i = i+2)
	{
		std::pair<Club, Club> NewPair = { Players[i], Players[i+1] };
		FinalMatching.push_back(NewPair);
	}

	PrintMatchmaking(FinalMatching);

	return FinalMatching;
}

void Matchmaking::PrintMatchmaking(const std::vector<std::pair<Club, Club>>& FinalMatching)
{
	std::cout << "########################## MATCHMAKING ##########################" << std::endl;
	for (int i = 0; i < FinalMatching.size(); i++)
	{
		std::cout << "----------------------------- Pair " << i+1 << ". ----------------------------" << std::endl;
		Club Club1 = std::get<0>(FinalMatching[i]);
		Club Club2 = std::get<1>(FinalMatching[i]);

		std::cout << "TEAM 1" << std::endl;
		Club1.PrintStrongestTeam();
		std::cout << "TEAM 2" << std::endl;
		Club2.PrintStrongestTeam();
	}
}

#include <iostream>
#include <math.h>
#include "Matchmaking.h"

using namespace std;

vector<Player> GenerateRandomTeam();

int main()
{
	Matchmaking m;

	vector<Player> TestTeam;

	std::vector<Club> CompetingClubs;

	for (int i = 0; i < 20; i++)
	{
		TestTeam = GenerateRandomTeam();
		Club TempClub (TestTeam);
		CompetingClubs.push_back(TempClub);
	}

	m.MatchPlayers(CompetingClubs);

	return 0;
}

vector<Player> GenerateRandomTeam()
{
	vector<Player> NewTeam;
	int i;
	for (i = 0; i < 2; i++)
	{
		Player NewPlayer = Player(rand() % 101, PlayerRole::Goalkeeper);
		NewTeam.push_back(NewPlayer);
	}

	for (i = 0; i < 4; i++)
	{
		Player NewPlayer = Player(rand() % 101, PlayerRole::Forward);
		NewTeam.push_back(NewPlayer);
	}

	for (i = 0; i < 8; i++)
	{
		Player NewPlayer = Player(rand() % 101, PlayerRole::MiddField);
		NewTeam.push_back(NewPlayer);
	}

	for (i = 0; i < 8; i++)
	{
		Player NewPlayer = Player(rand() % 101, PlayerRole::Back);
		NewTeam.push_back(NewPlayer);
	}

	return NewTeam;
}
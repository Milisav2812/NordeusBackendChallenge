#include "Club.h"
#include "Team.h"

#include <iostream>
#include <vector>
#include <algorithm>

#define OUT

int Club::ID = 0;

Club::Club(std::vector<Player> Players)
{
	if (Players.size() < 18 || Players.size() > 30)
	{
		std::cout << "ERROR: Number of Players in a Club must be between 18 and 30!" << std::endl;
		exit(1);
	}

	this->StrongestTeam = FormStrongestTeam(Players);
	StrongestTeamRating = StrongestTeam.CalculateAverageRating();

	this->Players = Players;
	AveragePlayerRating = CalculateAverageRating(this->Players);

	ClubId = ID++;
}

/* Checks whether there are enough players in each role to create one whole team */
Team Club::FormStrongestTeam(const std::vector<Player>& Players)
{
	std::vector<Player> Goalkeeper;
	AddNumberOfPlayersByRole(Goalkeeper, Players, PlayerRole::Goalkeeper, 1);
	std::vector<Player> Forward;
	AddNumberOfPlayersByRole(Forward, Players, PlayerRole::Forward, 2);
	std::vector<Player> Middfield;
	AddNumberOfPlayersByRole(Middfield, Players, PlayerRole::MiddField, 4);
	std::vector<Player> Back;
	AddNumberOfPlayersByRole(Back, Players, PlayerRole::Back, 4);

	return Team(Goalkeeper, Forward, Middfield, Back);
}

/* Receive players from TeamIn and transfer them to TeamOut */
void Club::AddNumberOfPlayersByRole(OUT std::vector<Player>& TeamOut, const std::vector<Player>& TeamIn, PlayerRole Role, int NumOfPlayers)
{
	std::vector<Player> Players = GetAllPlayersOfTheSameRole(TeamIn, Role);
	if (Players.size() < NumOfPlayers)
	{
		std::cout << "ERROR: Not enough players of each Role to make one whole Team!" << std::endl;
		exit(1);
	}

	for (int i = Players.size() - NumOfPlayers; (size_t)i <= Players.size() - 1; i++)
	{
		TeamOut.push_back(Players[i]);
	}
}

std::vector<Player> Club::GetAllPlayersOfTheSameRole(const std::vector<Player>& Team, PlayerRole Role)
{
	std::vector<Player> Players;
	for (auto Player : Team)
	{
		if (Player.GetRole() == Role)
		{
			Players.push_back(Player);
		}
	}

	std::sort(Players.begin(), Players.end());

	return Players;
}

bool Club::operator<(const Club& Club2) const
{
	return (this->StrongestTeamRating < Club2.StrongestTeamRating);
}

double Club::CalculateAverageRating(const std::vector<Player>& Team)
{
	double AverageRating = 0;
	for (auto Element : Team)
	{
		AverageRating += Element.GetRating();
	}
	AverageRating /= Team.size();
	return AverageRating;
}

void Club::PrintStrongestTeam()
{
	std::cout << "ClubID: " << ClubId << std::endl;
	std::cout << "Club Strongest Average: " << StrongestTeamRating << std::endl;
	StrongestTeam.Print();
}
void Club::PrintWholeTeam()
{
	PrintVector(Players);
}

void Club::PrintVector(const std::vector<Player>& Team)
{
	std::vector<Player> TempVector = GetAllPlayersOfTheSameRole(Team, PlayerRole::Goalkeeper);
	std::cout << "Goalkeeper [ ";
	for (auto Player : TempVector)
	{
		std::cout << Player.GetRating() << " ";
	}
	std::cout << "]" << std::endl;

	TempVector = GetAllPlayersOfTheSameRole(Team, PlayerRole::Forward);
	std::cout << "Forward [ ";
	for (auto Player : TempVector)
	{
		std::cout << Player.GetRating() << " ";
	}
	std::cout << "]" << std::endl;

	TempVector = GetAllPlayersOfTheSameRole(Team, PlayerRole::MiddField);
	std::cout << "MiddField [ ";
	for (auto Player : TempVector)
	{
		std::cout << Player.GetRating() << " ";
	}
	std::cout << "]" << std::endl;

	TempVector = GetAllPlayersOfTheSameRole(Team, PlayerRole::Back);
	std::cout << "Back [ ";
	for (auto Player : TempVector)
	{
		std::cout << Player.GetRating() << " ";
	}
	std::cout << "]" << std::endl << std::endl;

}

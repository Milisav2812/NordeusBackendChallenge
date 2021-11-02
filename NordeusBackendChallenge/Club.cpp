#include "Club.h"

#include <iostream>
#include <vector>
#include <algorithm>

#define OUT

Club::Club(std::vector<Player> Team)
{
	if (Team.size() < 18 || Team.size() > 30)
	{
		std::cout << "ERROR: Number of Players in a Club must be between 18 and 30!" << std::endl;
		exit(1);
	}

	if (bIsClubValid(Team))
	{
		this->Team = Team;
		AveragePlayerRating = CalculateAverageRating(this->Team);
		this->StrongestTeam = FormStrongestTeam(this->Team);
		StrongestTeamRating = CalculateAverageRating(StrongestTeam);
	}
	else
	{
		std::cout << "ERROR: Not enough players of each Role to make one whole Team!" << std::endl;
		exit(1);
	}
}

/* Checks whether there are enough players in each role to create one whole team */
bool Club::bIsClubValid(const std::vector<Player>& Team)
{
	std::vector<Player> Temp;

	Temp = GetAllPlayersOfTheSameRole(Team, PlayerRole::Goalkeeper);
	if (Temp.size() < 1) return false;

	Temp = GetAllPlayersOfTheSameRole(Team, PlayerRole::Forward);
	if (Temp.size() < 2) return false;

	Temp = GetAllPlayersOfTheSameRole(Team, PlayerRole::MiddField);
	if (Temp.size() < 4) return false;

	Temp = GetAllPlayersOfTheSameRole(Team, PlayerRole::Back);
	if (Temp.size() < 4) return false;

	return true;
}

/* Form the strongest possible team using all the players */
std::vector<Player> Club::FormStrongestTeam(const std::vector<Player>& Team)
{
	std::vector<Player> StrongestTeam;

	// Goalkeeper
	AddNumberOfPlayersByRole(StrongestTeam, Team, PlayerRole::Goalkeeper, 1);
	// Forward
	AddNumberOfPlayersByRole(StrongestTeam, Team, PlayerRole::Forward, 2);
	// MiddField
	AddNumberOfPlayersByRole(StrongestTeam, Team, PlayerRole::MiddField, 4);
	// Back
	AddNumberOfPlayersByRole(StrongestTeam, Team, PlayerRole::Back, 4);

	return StrongestTeam;
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

/* Receive players from TeamIn and transfer them to TeamOut */
void Club::AddNumberOfPlayersByRole(OUT std::vector<Player>& TeamOut, const std::vector<Player>& TeamIn, PlayerRole Role, int NumOfPlayers)
{
	std::vector<Player> Players = GetAllPlayersOfTheSameRole(TeamIn, Role);

	for (int i = Players.size() - NumOfPlayers; (size_t)i <= Players.size() - 1; i++)
	{
		TeamOut.push_back(Players[i]);
	}
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
	PrintVector(StrongestTeam);
}
void Club::PrintWholeTeam()
{
	PrintVector(Team);
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

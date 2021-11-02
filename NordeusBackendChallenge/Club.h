#pragma once

#include "Player.h"
#include <vector>

class Club
{
public:
	// Constructors
	Club(std::vector<Player> Team);

	// Getters
	double GetAverageRating() { return AveragePlayerRating; }
	double GetStrongestAverageRating() { return StrongestTeamRating; }
	int GetNumberOfPlayers() { return Team.size(); }

	// Used for std::sort
	bool operator <(const Club& Club2) const;

	// Printing
	void PrintStrongestTeam();
	void PrintWholeTeam();
	
private:
	// Helper Functions
	std::vector<Player> FormStrongestTeam(const std::vector<Player>& Team);
	std::vector<Player> GetAllPlayersOfTheSameRole(const std::vector<Player>& Team, PlayerRole Role);
	void AddNumberOfPlayersByRole(std::vector<Player>& TeamOut, const std::vector<Player>& TeamIn, PlayerRole Role, int NumOfPlayers);
	double CalculateAverageRating(const std::vector<Player>& Team);
	bool bIsClubValid(const std::vector<Player>& Team);

	void PrintVector(const std::vector<Player>& Team);

	std::vector<Player> Team; // A vector containing all of the players
	double AveragePlayerRating;
	std::vector<Player> StrongestTeam; // A vector containing only the strongest team
	double StrongestTeamRating;
};
#pragma once

#include "Player.h"
#include "Team.h"
#include <vector>

class Club
{
public:
	// Constructors
	Club(std::vector<Player> Players);

	// Getters
	double GetAverageRating() const { return AveragePlayerRating; }
	double GetStrongestAverageRating() const { return StrongestTeamRating; }
	int GetNumberOfPlayers() const { return Players.size(); }
	int GetID() const { return ClubId; }

	// Used for std::sort
	bool operator <(const Club& Club2) const;

	// Printing
	void PrintStrongestTeam();
	void PrintWholeTeam();
	
private:
	// Helper Functions
	std::vector<Player> GetAllPlayersOfTheSameRole(const std::vector<Player>& Players, PlayerRole Role);
	void AddNumberOfPlayersByRole(std::vector<Player>& PlayersOut, const std::vector<Player>& PlayersIn, PlayerRole Role, int NumOfPlayers);
	double CalculateAverageRating(const std::vector<Player>& Players);
	Team FormStrongestTeam(const std::vector<Player>& Players);
	void PrintVector(const std::vector<Player>& Players);

	std::vector<Player> Players; // A vector containing all of the players
	double AveragePlayerRating;
	
	Team StrongestTeam; // A vector containing only the strongest team
	double StrongestTeamRating;

	static int ID;
	int ClubId;
};
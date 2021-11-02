#pragma once
#include "Player.h"

#include <vector>

#define NUM_OF_FORWARD 2
#define NUM_OF_MIDDFIELD 4
#define NUM_OF_BACK 4
#define NUM_OF_PLAYERS 11

class Team
{
public:
	Team() {}
	Team(std::vector<Player> Goalkeeper,
		 std::vector<Player> Forward,
		 std::vector<Player> Middfield,
		 std::vector<Player> Back);

	double CalculateAverageRating();
	void Print() const;

private:
	Player Goalkeeper;
	std::vector<Player> Forward;
	std::vector<Player> Middfield;
	std::vector<Player> Back;
};
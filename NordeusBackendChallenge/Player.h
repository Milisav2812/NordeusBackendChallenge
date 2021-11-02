#pragma once
// Forward - 2, MiddField - 4, Back - 4, Goalkeeper - 1
enum class PlayerRole {Forward, MiddField, Back, Goalkeeper};

class Player
{
public:
	// Construtor
	Player(int Rating, PlayerRole Role);

	// Getters
	int GetRating() { return Rating; }
	PlayerRole GetRole() { return Role; }

	// Used for std::sort
	bool operator <(const Player& Player2) const;

private:
	int Rating; // Between 0 and 100
	PlayerRole Role;
};
#pragma once
// Forward - 2, Midfield - 4, Back - 4, Goalkeeper - 1
enum class PlayerRole {Forward, MidField, Back, Goalkeeper};

class Player
{
public:
	// Construtor
	Player(int Rating, PlayerRole Role);
	Player():Rating(0),Role(PlayerRole::Forward) {}

	// Getters
	int GetRating() const { return Rating; }
	PlayerRole GetRole() const { return Role; }

	// Used for std::sort
	bool operator <(const Player& Player2) const;

private:
	int Rating; // Between 0 and 100
	PlayerRole Role;
};



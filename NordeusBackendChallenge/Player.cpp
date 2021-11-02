#include "Player.h"
#include <iostream>

Player::Player(int Rating, PlayerRole Role)
{
	if (Rating < 0 || Rating > 100)
	{
		std::cout << "ERROR: Rating for each player must be between 0 and 100!" << std::endl;
		exit(1);
	}

	this->Rating = Rating;
	this->Role = Role;
}

bool Player::operator<(const Player& Player2) const
{
	return (this->Rating < Player2.Rating);
}

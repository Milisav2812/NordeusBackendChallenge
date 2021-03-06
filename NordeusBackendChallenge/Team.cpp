#include "Team.h"

#include <iostream>

Team::Team(std::vector<Player> Goalkeeper,
		   std::vector<Player> Forward,
		   std::vector<Player> Midfield,
		   std::vector<Player> Back)
{
	this->Goalkeeper = Goalkeeper[0];
	this->Forward = Forward;
	this->Midfield = Midfield;
	this->Back = Back;
}

double Team::CalculateAverageRating()
{
	double Rating = 0.0;
	Rating += Goalkeeper.GetRating();
	for (int i = 0; i < Forward.size(); i++)
	{
		Rating += Forward[i].GetRating();
	}
	for (int i = 0; i < Midfield.size(); i++)
	{
		Rating += Midfield[i].GetRating();
	}
	for (int i = 0; i < Back.size(); i++)
	{
		Rating += Back[i].GetRating();
	}
	Rating = (double)(Rating / NUM_OF_PLAYERS);

	return Rating;
}
void Team::Print() const
{
	std::cout << "Goalkeeper: [ " << Goalkeeper.GetRating() << " ]" << std::endl;
	
	std::cout << "Forward [ ";
	for (auto Player : Forward)
	{
		std::cout << Player.GetRating() << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "Midfield [ ";
	for (auto Player : Midfield)
	{
		std::cout << Player.GetRating() << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "Back [ ";
	for (auto Player : Back)
	{
		std::cout << Player.GetRating() << " ";
	}
	std::cout << "]" << std::endl << std::endl;
}


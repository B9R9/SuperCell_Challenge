#pragma once

#include "Event.hpp"


class Game;

class Menu
{
	public:
	Menu();
	~Menu();
	bool initialise();
	bool display(sf::RenderWindow& render, Game& game);
	int getStep();
	void setStep(int newStep);
	bool dispacht(sf::RenderWindow& render, int& menuStep, int indexNav, Game& game);
	void displayTitle(sf::RenderWindow& render);
	void displayMenu(sf::RenderWindow& render, int indexNav);
	void displayOptions(sf::RenderWindow& render, int &menuStep);
	bool displayAboutMe(sf::RenderWindow&render, int& menuStep);
	void displayNG(sf::RenderWindow& render, int& menuStep);
	
	private:
	int menuStep;
	Event event;
};
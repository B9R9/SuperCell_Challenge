#pragma once

#include "sfml.hpp"
#include "Menu.hpp"
#include "Platform.hpp"

class Menu;

class Game
{
	public:
		Game();
		~Game();

		bool initialise(sf::RenderWindow& render);
		int getGameStep();
		bool setGameStep(int newStep);
		int getScreenWidth();
		int getScreenHeight();
		sf::Font getFont();
		void playIntro(sf::RenderWindow& render);
		Menu& getMenu();
	    const Menu& getMenu() const;
		void inGame(sf::RenderWindow&render, Game& game);

	private:
		sf::Font 	font;
		int 		gameStep;
		Menu 		menu;
		sf::Vector2u screenSize;
		Platform 	platforms;
		Event		event;

		/*
		Player 		player;
		Event		event;
		Coin		coins;*/
};
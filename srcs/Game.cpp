#include "Game.hpp"

#include "sfml.hpp"
#include "animation.hpp"
#include "Parameters.hpp"
#include "utils.hpp"
#include <iostream>


Game::Game()
{

};

Game::~Game(){

};

bool Game::initialise(sf::RenderWindow& render)
{
	if (!font.loadFromFile("assets/font/FATPRG__.TTF"))
    {
        std::cerr << "Error loading font" << "\n";
        return false;
    }
	gameStep = GameStep::INTRO;
	screenSize = render.getSize();
	menu.initialise();
	return true;
}

sf::Font Game::getFont()
{
	return font;
}

int Game::getGameStep()
{
	return (gameStep);
}

int Game::getScreenWidth()
{
	return (screenSize.x);
}

int Game::getScreenHeight()
{
	return (screenSize.y);
}

bool Game::setGameStep(int newStep)
{
	if (newStep != GameStep::INTRO && newStep != GameStep::INGAME &&\
	newStep != GameStep::MAINMENU && newStep != GameStep::QUIT)
		return false;
	gameStep = newStep;
	return true;
}

void Game::playIntro(sf::RenderWindow& render)
{
	sf::Texture texture;
	if (!texture.loadFromFile("assets/HiveLogo.bmp"))
		std::cerr << "Error Opening Hive Logo\n";
	fadeIn(texture, render, 2);
	fadeOut(texture, render, 2);
}

Menu& Game::getMenu() {
    return menu;
}

const Menu& Game::getMenu() const {
    return menu;
}

void Game::inGame(sf::RenderWindow& render, Game& game)
{
	std::vector<Platform> platforms;

	clearRender(render,SKYBLUE);
	platforms = buildScene(render, game.getScreenWidth(), game.getScreenHeight());
	while(1)
	{
		event.gameEvent(render);
		if (timeTo(5000))
			platforms = buildScene(render, game.getScreenWidth(), game.getScreenHeight());
		for (const auto& platform : platforms) {
			platform.draw(render);
		}
		render.display();
		clearRender(render, SKYBLUE);	
	}
}

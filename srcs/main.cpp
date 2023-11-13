#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Parameters.hpp"

int main()
{
	sf::RenderWindow render;
	render.create(sf::VideoMode::getFullscreenModes()[0], "Platform Survivor", sf::Style::Fullscreen);
	render.setFramerateLimit(60);

	Game game;
	if (!game.initialise(render))
		return (-1);
	
	while (render.isOpen())
	{
		switch(game.getGameStep())
		{
			case(GameStep::INTRO):
				game.playIntro(render);
				game.setGameStep(GameStep::MAINMENU);
				break;
			case(GameStep::MAINMENU):
				game.getMenu().display(render, game);
				break;
			case(GameStep::INGAME):
				game.inGame(render, game);
		}

	}

/*
	std::unique_ptr<Game> pGame = std::make_unique<Game>();
    if (!pGame->initialise(window.getView().getSize()))
    {
        std::cerr << "Game Failed to initialise" << std::endl;
        return 1;
    }
*/
	


	return (0);
}
#include "Event.hpp"
#include "sfml.hpp"
#include "Parameters.hpp"

Event::Event(){};

Event::~Event()
{

};

static void menuTitle(int& menuStatus, sf::Event event)
{
	if (event.key.scancode == sf::Keyboard::Scan::Space)
		menuStatus = MenuStep::MENU;
	if (event.key.scancode == sf::Keyboard::Scan::Escape)
		menuStatus = MenuStep::QUIT_M;
}

static void setIndexNavigationMenu(int &indexNavigation, int scancode)
{
	if (scancode == 88)
	{
		indexNavigation = indexNavigation + 1;
		if (indexNavigation > 3)
			indexNavigation = 0;
	}
	else if (scancode == 89)
	{
		indexNavigation = indexNavigation - 1;
		if (indexNavigation < 0)
			indexNavigation = 3;
	}
}

static void menuMenu(int& menuStatus, sf::Event event, int &indexNavigation)
{
	if (event.key.scancode == sf::Keyboard::Scan::Escape)
		menuStatus = MenuStep::QUIT_M;
	else if (event.key.scancode == sf::Keyboard::Scan::Backspace)
		menuStatus = MenuStep::TITLE;
	else if (event.key.scancode == sf::Keyboard::Scan::Space)
	{
		if (indexNavigation == 0)
			menuStatus = MenuStep::NEWGAME;
		if (indexNavigation == 1)
			menuStatus = MenuStep::OPTION;
		if (indexNavigation == 2)
			menuStatus = MenuStep::ABOUTME;
		if (indexNavigation == 3)
			menuStatus = MenuStep::QUIT_M;
		indexNavigation = 0;
	}
	else if (event.key.scancode == sf::Keyboard::Scan::Up)
		setIndexNavigationMenu(indexNavigation, 89);
	else if (event.key.scancode == sf::Keyboard::Scan::Down)
		setIndexNavigationMenu(indexNavigation, 88);

}

void Event::menu(sf::RenderWindow& render,int& indexNav, int& menuStep)
{
	sf::Event event;
        	while (render.pollEvent(event))
        	{
            	if (event.type == sf::Event::Closed)
    	            render.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (menuStep & MenuStep::TITLE)
						menuTitle(menuStep, event);
					else if (menuStep & MenuStep::MENU)
						menuMenu(menuStep, event, indexNav);
				}
        	}
}

void Event::goBackOrQuit(sf::RenderWindow& render, int& menuStep)
{
	sf::Event event;
        	while (render.pollEvent(event))
        	{
            // évènement "fermeture demandée" : on ferme la fenêtre
            	if (event.type == sf::Event::Closed)
    	            render.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.scancode == sf::Keyboard::Scan::Backspace)
						menuStep = MenuStep::MENU;
					if (event.key.scancode == sf::Keyboard::Scan::Escape)
						menuStep = MenuStep::QUIT_M;
				}
        	}
}

void Event::gameEvent(sf::RenderWindow& render)
{
	sf::Event event;
    while (render.pollEvent(event))
    {
    // évènement "fermeture demandée" : on ferme la fenêtre
        if (event.type == sf::Event::Closed)
    	    render.close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.scancode == sf::Keyboard::Scan::Escape)
			{	
				render.close();
				exit (0);
			}
		}
    }
}
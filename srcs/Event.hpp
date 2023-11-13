#pragma once

#include "sfml.hpp"

class Event
{
	public:
	Event();
	~Event();
	void menu(sf::RenderWindow& render,int& indexnav, int& menuStep);
	void goBackOrQuit(sf::RenderWindow& render, int& menuStep);
	void gameEvent(sf::RenderWindow& render);
	
	private:

};
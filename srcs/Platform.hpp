#pragma once
#include "sfml.hpp"
#include <vector>

enum class PlatformPosition {
    Left,
    Right,
    Center
};

class Platform
{
	public:
	Platform();
	Platform(float x, float y, float w, float h);
	~Platform();
	float getX()const;
	float getY()const;
	float getW()const;
	float getH()const;	
	void draw(sf::RenderWindow &render)const;
	std::vector<Platform> generate(PlatformPosition position, int totalPlatforms, sf::Vector2u screenSize);


	private:
	float x, y, w, h;

};
#include "Platform.hpp"
#include "sfml.hpp"
#include "Parameters.hpp"
#include "utils.hpp"
#include <random>

Platform::Platform(float x, float y, float w, float h): x(x), y(y), w(w), h(h){};

Platform::Platform() : x(0.0f), y(0.0f), w(0.0f), h(0.0f) {};

Platform::~Platform()
{

};

void Platform::draw(sf::RenderWindow &render) const
{
	sf::Color color;

	color = colorConverter(hexConverter(BRUN), 255);
	sf::RectangleShape platformShape(sf::Vector2f(w, h));
	platformShape.setPosition(x, y);
	platformShape.setFillColor(color);
	render.draw(platformShape);

}

float Platform::getX() const
{
	return(x);
}

float Platform::getY() const
{
	return(y);
}

float Platform::getW() const
{
	return(w);
}

float Platform::getH() const
{
	return(h);
}

std::vector<Platform> Platform::generate(PlatformPosition position, int totalPlatforms, sf::Vector2u screenSize)
{   
	std::random_device rd;
    std::mt19937 gen(rd());
	int i = 0;

    std::vector<Platform> platforms;

	while (i < totalPlatforms)
	{
        float abs, ord, width, height;

        // Générer la position x en fonction de l'option spécifiée
		ord = generateRandomNumber(50, screenSize.y - 100);
        width = generateRandomNumber(50, 600);
        switch (position) {
            case PlatformPosition::Left:
                abs = 0.0f;
                break;
            case PlatformPosition::Right:
                abs = screenSize.x - width;
                break;
            case PlatformPosition::Center:
				int oneThird = screenSize.x / 3;
                abs = generateRandomNumber(oneThird, oneThird * 2);
                break;
        }
        height = 50.0f;
		
		bool canAddPlatform = true;

        for (const auto& existingPlatform : platforms) {
            if (std::abs(ord - existingPlatform.getY()) < 0.15f * screenSize.y) {
                canAddPlatform = false;
                break;
            }
        }
        if (canAddPlatform) {
            platforms.push_back(Platform(abs, ord, width, height));
			i++;
        }	
	}
	return platforms;
}
#include "sfml.hpp"
#include "utils.hpp"
#include "Platform.hpp"
#include <iostream>
#include <random>

void clearRender(sf::RenderWindow &render, const char *colorName)
{
	sf::Color color;

	color =  colorConverter(hexConverter(colorName), 255);
	render.clear(color);
}

sf::Color colorConverter(u_int32_t hexValue, int alphaValue)
{
  sf::Color color;
  color.r = ((hexValue & 0xFF0000) >> 16);  // Extract the RR byte
  color.g = ((hexValue & 0xFF00) >> 8) ;   // Extract the GG byte
  color.b = ((hexValue & 0xFF)) ;        // Extract the BB byte
  color.a = alphaValue;
  return (color); 
}

/**
 * @brief Convertir un char * de type hexadecimal en valeur numerique
 * 
 * @param hexvalue : char *hexdecimal value
 * @return u_int32_t: la conversion du char * en u_int32_t
 */
u_int32_t hexConverter(const char *hexvalue)
{
    char hexDigits[16] = { '0', '1', '2', '3', '4', '5', '6', '7',\
                           '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    u_int32_t ret;
    int  i, j, power;

    ret = 0;
    power = 0;
    i = 0;
    i = strlen(hexvalue) -1;
    while (0 <= i)
    {
        j = 0;
        while (j < 16)
        {
            if (hexvalue[i] == hexDigits[j])
                ret += j * pow(16, power);
            j++;
        }
        power++;
        i--;
    }
    return (ret);
}

bool panic(const char* message)
{
    std::cerr << "Error in: " << message <<"\n";
    return false;
}

void setText(sf::Text* text, const char* message, int size, float x, float y, const sf::Color& color)
{
    text->setString(message);
    text->setCharacterSize(size);
    text->setPosition(x, y);
    text->setLetterSpacing(0);
    text->setScale(0.4, 0.4);
	text->setFillColor(color);
}

bool timeTo(int delay)
{
    static sf::Clock clock;
	int elapsedTime;

	elapsedTime = clock.getElapsedTime().asMilliseconds();
	if (elapsedTime > delay)
	{
		clock.restart();
		return true;
	}
	return false;
}

std::vector<Platform> buildScene(sf::RenderWindow &render, int screenW, int screenH)
{
	std::vector<Platform> platformsLeft;
	std::vector<Platform> platformsRight;
	std::vector<Platform> platformsCenter;
	Platform platform;

	platformsLeft = platform.generate(PlatformPosition::Left, 3, sf::Vector2u(screenW, screenH));
	platformsCenter = platform.generate(PlatformPosition::Center, 3, sf::Vector2u(screenW, screenH));
	platformsRight = platform.generate(PlatformPosition::Right, 3, sf::Vector2u(screenW, screenH));
	for (const auto& platform : platformsRight) {
		platformsCenter.push_back(platform);
        }
	for (const auto& platform : platformsLeft) {
		platformsCenter.push_back(platform);
        }
	return platformsCenter;
}

int generateRandomNumber(int min, int max)
{
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}
#include "Text.hpp"
#include "utils.hpp"

Text::Text(const char* message, int size, float x, float y, const sf::Color& color)
    : x(x), y(y), color(color)
{
    if (!font.loadFromFile("assets/font/FATPRG__.TTF")) {
        throw std::runtime_error("Impossible de charger la police");
    }

    myText.setFont(font);
    myText.setString(message);
    myText.setCharacterSize(size);
    myText.setPosition(x, y);
    myText.setFillColor(color);
    myText.setLetterSpacing(0);
    myText.setScale(0.4, 0.4);
}

Text::~Text()
{

}

void Text::draw(sf::RenderWindow& render)
{
    render.draw(myText);
}

bool Text::visible()
{
    static sf::Clock clock;
    int elapsedTime;

    elapsedTime = clock.getElapsedTime().asMilliseconds();
    if (elapsedTime > 1200)
        clock.restart();
    if (elapsedTime > 500)
        return true;
    return false;
}

void Text::setcolor(const char* color)
{
    myText.setFillColor(colorConverter(hexConverter(color), 255));
}

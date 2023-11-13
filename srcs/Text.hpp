
#pragma once

#include <SFML/Graphics.hpp>

class Text 
{
public:
    Text(const char* message, int size, float x, float y, const sf::Color& color);
    ~Text();
    void draw(sf::RenderWindow& render);
    bool visible();
    void setcolor(const char *color);
 
private:
    sf::Text myText;
    sf::Font font;  // Déplacer la déclaration de sf::Font ici
    float x;
    float y;
    sf::Color color;
};
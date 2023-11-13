#pragma once

#include "sfml.hpp"
#include "Platform.hpp"
#include <vector>


void clearRender(sf::RenderWindow &render, const char *colorName);
sf::Color colorConverter(u_int32_t hexValue, int alphaValue);
u_int32_t hexConverter(const char *hexvalue);
bool panic(const char* message);
void setText(sf::Text* text, const char* message, int size, float x, float y, const sf::Color& color);
std::vector<Platform> buildScene(sf::RenderWindow &render, int screenW, int screenH);
int generateRandomNumber(int min, int max);
bool timeTo(int delay);
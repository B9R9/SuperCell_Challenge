#include "Menu.hpp"
#include "Game.hpp"
#include "Parameters.hpp"
#include "sfml.hpp"
#include "utils.hpp"
#include "Text.hpp"
#include "Event.hpp"
#include "animation.hpp"
#include "sfml.hpp"

Menu::Menu(){};

Menu::~Menu()
{

};

bool Menu::initialise()
{
	menuStep = MenuStep::TITLE;
	return true;
}

int Menu::getStep()
{
	return (menuStep);
}

void Menu::setStep(int newStep)
{
	menuStep = newStep;
}

static bool checkMenuStatus(int menuStatus)
{
	if (menuStatus & QUIT_M)
		return false;
	if (menuStatus & RUNGAME)
		return false;
	return true;
}

bool  Menu::dispacht(sf::RenderWindow& render, int& menuStep, int indexNav, Game& game)
{
	(void)game;
	if (menuStep & MenuStep::TITLE)
		displayTitle(render);
	if (menuStep & MenuStep::MENU)
		displayMenu(render, indexNav);
	if (menuStep & MenuStep::OPTION)
		displayOptions(render, menuStep);
	if (menuStep & MenuStep::ABOUTME)
		if (displayAboutMe(render, menuStep) == false)
			return (panic("Menu::dispacht <return displayaboutme>\n"));
	if (menuStep & MenuStep::NEWGAME)
		displayNG(render, menuStep);
	return true;
}

bool Menu::display(sf::RenderWindow &render, Game& game)
{
	int indexNav;
	int menuStep;

	menuStep = MenuStep::TITLE;
	indexNav = 0;
	while(checkMenuStatus(getStep()))
	{
		event.menu(render, indexNav, menuStep);
		clearRender(render, SKYBLUE);
		if (!dispacht(render, menuStep,indexNav, game))
			return (panic("Menu::display <dispacht>"));
		render.display();
	}
	/*A redefinir*/
	if (menuStep & MenuStep::QUIT_M)
		game.setGameStep(GameStep::QUIT);
	if (menuStep & MenuStep::RUNGAME)
		game.setGameStep(GameStep::INGAME);
	return true;
}

void Menu::displayTitle(sf::RenderWindow&render)
{
	Text title("Platform Survivor", 250, 144.0f, 250.0f, colorConverter(hexConverter(ORANGE), 255));
	Text pressSpace("Press Space", 250 / 3, 600.0f, 360.0f, colorConverter(hexConverter(ORANGE), 255));

// Notez les points-virgules ajoutés à la fin des deux lignes ci-dessus.


	title.draw(render);
	if (pressSpace.visible())
		pressSpace.draw(render);
}

void Menu::displayMenu(sf::RenderWindow& render, int indexNav)
{
	Text newGame("NewGame", 75, 144.0f, 500.0f,colorConverter(hexConverter(ORANGE), 255));
	Text options("Options", 75, 144.0f, 550.0f,colorConverter(hexConverter(ORANGE), 255));
	Text aboutme("Aboutme", 75, 144.0f, 600.0f, colorConverter(hexConverter(ORANGE), 255));
	Text quit("quit", 75, 144.0f, 650.0f, colorConverter(hexConverter(ORANGE), 255));

	switch(indexNav)
    {
        case (0):
            newGame.setcolor(OCREYELLOW);
            options.setcolor(ORANGE);
            aboutme.setcolor(ORANGE);
            quit.setcolor(ORANGE);
            break;
        case (1):
            newGame.setcolor(ORANGE);
            options.setcolor(OCREYELLOW);
            aboutme.setcolor(ORANGE);
            quit.setcolor(ORANGE);
            break;
        case (2):
            newGame.setcolor(ORANGE);
            options.setcolor(ORANGE);
            aboutme.setcolor(OCREYELLOW);
            quit.setcolor(ORANGE);
            break;
        case (3):
            newGame.setcolor(ORANGE);
            options.setcolor(ORANGE);
            aboutme.setcolor(ORANGE);
            quit.setcolor(OCREYELLOW);
            break;
    }
	newGame.draw(render);
	options.draw(render);
	aboutme.draw(render);
	quit.draw(render);
}

void Menu::displayOptions(sf::RenderWindow& render, int& menuStep)
{
	Text text("In progress...", 100, 400.0f, 350.0f, colorConverter(hexConverter(ORANGE), 255));
	while(1)
	{
		clearRender(render, SKYBLUE);
		text.draw(render);
		render.display();
		event.goBackOrQuit(render, menuStep);
		if (menuStep != MenuStep::OPTION)
			break;
	}
}

bool Menu::displayAboutMe(sf::RenderWindow&render, int& menuStep)
{
	sf::Texture texture;
	if (!texture.loadFromFile("/Users/flagada/Desktop/LittleCloudProject/RESSOURCES/CV.jpg"))
		return panic("Menu::displayaboutme <Loadfrom file>\n");

    sf::Sprite sp_CV;
    sp_CV.setTexture(texture);
    sp_CV.setScale(0.2, 0.2);
    sp_CV.setPosition(400, 100);
    while (1)
	{
		render.clear();
		render.draw(sp_CV);
		render.display();
		event.goBackOrQuit(render, menuStep);
        if (menuStep != MenuStep::ABOUTME)
            break;
	}
	return true;
}

void Menu::displayNG(sf::RenderWindow& render, int& menuStep)
{
	sf::Font font;
    font.loadFromFile("/Users/flagada/Desktop/LittleCloudProject/RESSOURCES/font/FATPRG__.TTF"); // Charger une police SFML

    sf::Text text;
	text.setFillColor(colorConverter(hexConverter(ORANGE), 255));
	text.setFont(font);
	text.setCharacterSize(150);
	text.setLetterSpacing(0);
	text.setString("Instruction to print");
	text.setScale(0.4, 0.4);
	// setText(&text,"Instruction to print", 150, 0, 0, colorConverter(hexConverter(ORANGE), 255));

    // Création d'une texture de rendu
    sf::RenderTexture renderTexture;
    renderTexture.create(text.getLocalBounds().width, text.getLocalBounds().height);

    // Déplacement du texte dans la texture de rendu
    renderTexture.clear(sf::Color::Black);
    renderTexture.draw(text);
    renderTexture.display();

    // Obtention de la texture de rendu
    sf::Texture texture = renderTexture.getTexture();
	fadeIn(texture, render, 2);
	fadeOut(texture, render, 6);
    menuStep = MenuStep::RUNGAME;
}



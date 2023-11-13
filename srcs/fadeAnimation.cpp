#include "animation.hpp"
#include "sfml.hpp"

void checkEventIntro(sf::RenderWindow &render, bool *skip){
	sf::Event event;
        	while (render.pollEvent(event))
        	{
            // évènement "fermeture demandée" : on ferme la fenêtre
            	if (event.type == sf::Event::Closed)
    	            render.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.scancode == sf::Keyboard::Scan::Space)
						*skip = true;
				}
        	}
}

int calculateStepIncrement(int durationInSeconds, int framesPerSecond) {
    const int totalFrames = durationInSeconds * framesPerSecond;
    return 255 / totalFrames;
}

void fadeIn(sf::Texture texture, sf::RenderWindow &render, int duree){
	sf::Sprite	sprite;
	int 		alpha;
	int 		alphaIncrement;
	bool		skip;

	skip = false;
	alpha = 0;
	alphaIncrement = calculateStepIncrement(duree, 30);
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, alpha));
	sprite.setPosition(100.f, 100.f);
	while (alpha < 255)
	{
		render.clear();
		render.draw(sprite);
		render.display();
		alpha += alphaIncrement;
		sprite.setColor(sf::Color(255, 255, 255, alpha));
		checkEventIntro(render, &skip);
		if (skip)
			break;
	}

}

void fadeOut(sf::Texture texture, sf::RenderWindow &render, int duree){
	sf::Sprite	sprite;
	int 		alpha;
	int 		alphaIncrement;
	bool		skip;

	skip = false;
	alpha = 255;
	alphaIncrement = calculateStepIncrement(duree, 30);
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, alpha));
	sprite.setPosition(100.f, 100.f);
	while (alpha > 0)
	{
		render.clear();
		render.draw(sprite);
		render.display();
		alpha -= alphaIncrement;
		sprite.setColor(sf::Color(255, 255, 255, alpha));
		checkEventIntro(render, &skip);
		if (skip)
			break;
	}
}
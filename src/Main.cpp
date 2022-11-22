#include "Platform/Platform.hpp"
#include "Game.h"
#include "Player.h"
#include "Ball.h"
#include "GameDef.h"

int main()
{
	util::Platform platform;
	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(1024.0f * screenScalingFactor, 563.2f * screenScalingFactor), "Pong");
	platform.setIcon(window.getSystemHandle());

	sf::Event event;
	Game game(&window);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
			game.Update(CHAR_P);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			game.Update(CHAR_UP);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			game.Update(CHAR_DOWN);
		} else {
			game.Update(0);
		}
		game.DisplayGame();
	}

	return 0;
}

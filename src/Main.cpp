#include "Platform/Platform.hpp"
#include "Game.h"
#include "Player.h"

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				game.Update(0);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				game.Update(1);
			}
		game.DisplayGame();
	}

	return 0;
}

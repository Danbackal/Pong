#include "Platform/Platform.hpp"
#include "PlayerClass.cpp"

int main()
{

	// I want to set up a listener, to control the player bar
	// I do not need an observer pattern, I think, as I do not need to update
	// a large portion of items, as much as just the one bar?
	util::Platform platform;

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(200.0f * screenScalingFactor, 200.0f * screenScalingFactor), "Pong");
	platform.setIcon(window.getSystemHandle());

	sf::Event event;
	Player player(&window);


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			// for now, try keyboard, not event? and will probably use events for mouse clicks
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				player.Move(0);
			} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				player.Move(1);
			}
		}

	}

	return 0;
}

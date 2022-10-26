#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
	private:
		// window and boundaries
		sf::RenderWindow* window;
		int upperBound;
		int windowWidth;
		int windowHeight;
		// background
		sf::RectangleShape topBar;
		sf::RectangleShape net;
		// Players
		Player player;

	public:
		Game();
		Game(sf::RenderWindow* w);
		void DisplayGame();
		void Update(int move);
};

#endif
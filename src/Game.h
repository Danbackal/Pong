#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Ball.h"
#include "GameDef.h"

class Game {
	private:
		// window and boundaries
		sf::RenderWindow* _window;
		int _upperBound;
		int _windowWidth;
		int _windowHeight;
		// background
		sf::RectangleShape _topBar;
		sf::RectangleShape _net;
		// Players
		Player _player;
		// Computer _computer;
		int _p1Score; // p1 is left, always a real player
		int _p2Score;
		// Ball
		Ball _ball;
		int _ballSize;
		// Gamestate
		int _gameState;
		void CheckCollision();

	public:
		Game();
		Game(sf::RenderWindow* w);
		void DisplayGame();
		void Update(int move);
};

#endif
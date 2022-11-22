#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Computer.h"
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
		int _leftPaddle;
		int _rightPaddle;
		// Computer _computer;
		Computer _computer;
		int _p1Score; // p1 is left, always a real player
		int _p2Score;
		sf::Font _font;
		sf::Text _p1Text;
		sf::Text _p2Text;
		void SetScores();
		// will need to set positioning depending on text box because numbers are all different sizes, need this stored
		int _textY;
		int _p1TextX; // dont need p2 x, as it goes left to right
		// Ball
		Ball _ball;
		int _ballSize;
		// Gamestate
		int _gameState;
		void CheckCollision();
		bool PaddleCollision(sf::Vector2f ballPos);
		void SetUpBoundaries(sf::RenderWindow* w);

	public:
		Game();
		Game(sf::RenderWindow* w);
		void DisplayGame();
		void Update(int move);
};

#endif
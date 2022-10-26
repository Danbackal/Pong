#ifndef PLAYER_H
#define PLAYER_H

#include "GameDef.h"

class Player {
	private:
		int _windowWidth;
		int _windowHeight;
		sf::RectangleShape _paddle;
		int _paddleResetX;
		int _paddleResetY;
		void PaddleReset();

	public:
		Player();
		Player(int x, int y, int upperBound);
		sf::RectangleShape* GetPaddle();
		void Move(float move);
		sf::Vector2f getPosition();
};

#endif
#ifndef BALL_H
#define BALL_H

#include "GameDef.h"

class Ball {
	private:
		sf::CircleShape _ball;
		float _xVelocity;
		float _yVelocity;
		int _ballResetX;
		int _ballResetY;
		void BallReset();
	public:
		Ball();
		Ball(int x, int y, int upperBound);
		void Serve();
		// Maybe needs inputs, like collision - unsure rn
		void Move(int collision);
		sf::Vector2f GetPosition();
		sf::CircleShape* GetBall();
		int GetBallSize();
};

#endif
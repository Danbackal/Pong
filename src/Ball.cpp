#include "Platform/Platform.hpp"
#include "Ball.h"

Ball::Ball() {}

Ball::Ball(int x, int y, int upperBound) {
	_ball = sf::CircleShape(x/192); // Looks like its supposed to be smaller than paddle but bigger than net so... 1.5?
	_ballResetX = x/2 - _ball.getRadius();
	_ballResetY = y/2 + upperBound - _ball.getRadius();
	_yVelocity = 0;
	_xVelocity = 0;
	BallReset();
}

void Ball::BallReset() {
	_ball.setPosition(_ballResetX, _ballResetY);
	_xVelocity = 0;
	_yVelocity = 0;
}

void Ball::Serve() {
	std::cout << "ball is served" << std:: endl;
	// ratio of ball to paddle speed is up to 7/4 according to an online source?
	// changing this because fast is too fast and slow is too slow
	float x = std::rand() % 5 + 3;
	float y = std::rand() % 8;
	int up = std::rand() % 2;
	int left = std::rand() % 2;
	_xVelocity = (x * ((-2*left) + 1)) / (5 * MOVE_SPEED);
	_yVelocity = (y * ((-2*up) + 1)) / (5 * MOVE_SPEED);
	std::cout << "balls speed is " << _xVelocity << "," << _yVelocity << std::endl;
}

void Ball::Move(int collision) {
	switch (collision) {
		case RESET:
			BallReset();
			break;
		case WALL_COLLISION:
			_yVelocity = _yVelocity * -1;
			break;
		case NO_COLLISION:
			_ball.move(_xVelocity, _yVelocity);
			break;
		case PADDLE_COLLISION:
			_xVelocity = _xVelocity * -1;
			std::cout << "Paddle Collision" << std::endl;
			break;
		default:
			break;
	}
}

sf::Vector2f Ball::GetPosition() {
	return _ball.getPosition();
}

sf::CircleShape* Ball::GetBall() {
	return &_ball;
}

int Ball::GetBallSize() {
	return 2*_ball.getRadius();
}
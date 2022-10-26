#include "Platform/Platform.hpp"
#include "Player.h"

Player::Player() {
}

Player::Player(int x, int y, int upperBound) {
	// Might eventually need to know if it's player 1 or player 2
	_windowWidth = x;
	_windowHeight = y - upperBound;
	_paddle = sf::RectangleShape(sf::Vector2f(x/128, y/9));
	_paddleResetX = x/10;
	_paddleResetY = y/2 - y/18 + upperBound;
	PaddleReset();
}

sf::RectangleShape* Player::GetPaddle() {
	return &_paddle;
}

void Player::PaddleReset() {
	_paddle.setPosition(_paddleResetX, _paddleResetY);
}

void Player::Move(float move) {
	if (move == RESET) {
		PaddleReset();
	} else {
		_paddle.move(0, move/MOVE_SPEED);
	}
}

sf::Vector2f Player::getPosition() {
	return sf::Vector2f(_paddle.getPosition().y, _paddle.getPosition().y+_paddle.getSize().y);
}
#include "Platform/Platform.hpp"
#include "Player.h"

Player::Player() {
}

Player::Player(int x, int y, int upperBound, bool playerOne) {
	// Might eventually need to know if it's player 1 or player 2
	_playerOne = playerOne;
	_windowWidth = x;
	_windowHeight = y - upperBound;
	_upperBound = upperBound;
	_paddle = sf::RectangleShape(sf::Vector2f(x/128, y/9));
	if (playerOne) {
		_paddleResetX = x/10 - x/256;
	} else {
		_paddleResetX = (9*x)/10 - x/256;
	}
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

sf::Vector2f Player::GetPosition() {
	return sf::Vector2f(_paddle.getPosition().y, _paddle.getPosition().y+_paddle.getSize().y);
}

int Player::SetPaddleCoord() {
	if (_playerOne) {
		return _paddle.getSize().x + _paddle.getPosition().x;
	} else {
		return _paddle.getPosition().x;
	}
}
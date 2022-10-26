#include "Platform/Platform.hpp"
#include "Player.h"

Player::Player() {
}

Player::Player(int x, int y, int upperBound) {
	// Might eventually need to know if it's player 1 or player 2
	windowWidth = x;
	windowHeight = y - upperBound;
	paddle = sf::RectangleShape(sf::Vector2f(x/128, y/9));
	paddleResetX = x/10;
	paddleResetY = y/2 - y/18 + upperBound;
	PaddleReset();
}

sf::RectangleShape* Player::GetPaddle() {
	return &paddle;
}

void Player::PaddleReset() {
	paddle.setPosition(paddleResetX, paddleResetY);
}

void Player::Move(float move) {
	paddle.move(0, move/20);
}

sf::Vector2f Player::getPosition() {
	return sf::Vector2f(paddle.getPosition().y, paddle.getPosition().y+paddle.getSize().y);
}
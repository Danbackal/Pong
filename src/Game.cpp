#include "Platform/Platform.hpp"
#include "Game.h"
#include "Player.h"

Game::Game(sf::RenderWindow* w) {
	window = w;
	windowHeight = window->getSize().y;
	windowWidth = window->getSize().x;
	upperBound = windowHeight/10;
	topBar = sf::RectangleShape(sf::Vector2f(windowWidth, windowHeight/100));
	topBar.setPosition(0, windowHeight/10-windowHeight/100);
	net = sf::RectangleShape(sf::Vector2f(windowWidth/256, windowHeight-windowHeight/10));
	net.setPosition(windowWidth/2-windowWidth/512, windowHeight/10);
	player = Player(windowWidth, windowHeight, upperBound);
}

void Game::DisplayGame() {
	window->clear();
	window->draw(topBar);
	window->draw(net);
	window->draw(*player.GetPaddle());

	window->display();
}

void Game::Update(int move) {
	switch (move) {
		case 0:
			if (player.getPosition().x >= upperBound) {
				player.Move(-1);
			}
			break;
		case 1:
			if (player.getPosition().y <= windowHeight) {
				player.Move(1);
			}
			break;
		default:
			break;
	}
}
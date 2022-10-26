#include "Platform/Platform.hpp"
#include "Game.h"

Game::Game(sf::RenderWindow* w) {
	_gameState = NEW_GAME;
	_window = w;
	_windowHeight = _window->getSize().y;
	_windowWidth = _window->getSize().x;
	_upperBound = _windowHeight/10;
	_topBar = sf::RectangleShape(sf::Vector2f(_windowWidth, _windowHeight/100));
	_topBar.setPosition(0, _windowHeight/10-_windowHeight/100);
	_net = sf::RectangleShape(sf::Vector2f(_windowWidth/256, _windowHeight-_windowHeight/10));
	_net.setPosition(_windowWidth/2-_windowWidth/512, _windowHeight/10);
	_player = Player(_windowWidth, _windowHeight, _upperBound);
	_ball = Ball(_windowWidth, _windowHeight, _upperBound);
	_ballSize = _ball.GetBallSize();
}

void Game::DisplayGame() {
	_window->clear();
	_window->draw(_topBar);
	_window->draw(_net);
	_window->draw(*_player.GetPaddle());
	_window->draw(*_ball.GetBall());

	_window->display();
}

void Game::Update(int input) {
	switch (_gameState) {
		case NEW_GAME:
			// In case the last game ended and a new one began
			_player.Move(RESET);
			_ball.Move(RESET);
			//wait for player input, then start the game
			if (input == CHAR_P) {
				_gameState = SERVE;
			}
			break;
		case RESET:
			_player.Move(RESET);
			_ball.Move(RESET);
			_gameState = SERVE;
			break;
		case SERVE:
			std::cout << "entered serve" << std::endl;
			_ball.Serve();
			_gameState = MOVE;
			break;
		case MOVE:
			switch (input) {
				case CHAR_UP:
					if (_player.getPosition().x >= _upperBound) {
						_player.Move(-1);
					}
					break;
				case CHAR_DOWN:
					if (_player.getPosition().y <= _windowHeight) {
						_player.Move(1);
					}
					break;
				default:
					break;
			}
			// Ball logic
			_ball.Move(NO_COLLISION);
			CheckCollision();
			// Check to see if score
			break;
		case SCORE:
			// check to see if someone won
			// if someone won
			// _gameState = NEW_GAME
			// else
			_gameState = RESET;
			break;
		default:
			break;
	}

}

void Game::CheckCollision() {
	sf::Vector2f ballPos = _ball.GetPosition();
	if ((ballPos.y <= _upperBound) || (ballPos.y + _ballSize >= _windowHeight)) {
		_ball.Move(WALL_COLLISION);
	}
	if (ballPos.x <= 0) {
		_gameState = RESET;
		//scores
	} else if (ballPos.x >= _windowWidth) {
		_gameState = RESET;
		//scores
	}
	// not yet doing paddle collisions
}
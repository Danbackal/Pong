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
	_player = Player(_windowWidth, _windowHeight, _upperBound, true);
	_computer = Computer(_windowWidth, _windowHeight, _upperBound, false);
	_ball = Ball(_windowWidth, _windowHeight, _upperBound);
	_ballSize = _ball.GetBallSize();
	_leftPaddle = _player.SetPaddleCoord();
	_rightPaddle = _computer.SetPaddleCoord();
}

void Game::DisplayGame() {
	_window->clear();
	_window->draw(_topBar);
	_window->draw(_net);
	_window->draw(*_player.GetPaddle());
	_window->draw(*_computer.GetPaddle());
	_window->draw(*_ball.GetBall());

	_window->display();
}

void Game::Update(int input) {
	switch (_gameState) {
		case NEW_GAME:
			// In case the last game ended and a new one began
			_player.Move(RESET);
			_computer.Move(RESET);
			_ball.Move(RESET);
			//wait for player input, then start the game
			if (input == CHAR_P) {
				_gameState = SERVE;
			}
			break;
		case RESET:
			_player.Move(RESET);
			_computer.Move(RESET);
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
					if (_player.GetPosition().x >= _upperBound) {
						_player.Move(-1);
					}
					break;
				case CHAR_DOWN:
					if (_player.GetPosition().y <= _windowHeight) {
						_player.Move(1);
					}
					break;
				default:
					break;
			}
			// need a check to see if p2 is computer or player... for now, assume computer
			_computer.Move(_ball.GetPosition().y);
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
	if (PaddleCollision(ballPos)) {
		_ball.Move(PADDLE_COLLISION);
	}
}

bool Game::PaddleCollision(sf::Vector2f ballPos) {
	if ((ballPos.x <= _leftPaddle) && (ballPos.x + _ballSize >= _leftPaddle)) {
		if ((ballPos.y < _player.GetPosition().y) && (ballPos.y + _ballSize > _player.GetPosition().x)) {
			return true;
		}
	} else if ((ballPos.x + _ballSize >= _rightPaddle) && (ballPos.x <= _rightPaddle)) {
		if ((ballPos.y < _computer.GetPosition().y) && (ballPos.y + _ballSize > _computer.GetPosition().x)) {
			return true;
		}
	}
	return false;
}
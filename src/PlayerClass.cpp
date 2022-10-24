#include "Platform/Platform.hpp"

class Player {
	/*
	Player needs a paddle
	Player also needs paddle location, to listen to keyboard inputs
	Player needs things like a score
	Lets start with Paddle
	*/
	private:
		// Screen Boundary for movement
		int y;
		// top left corner of paddle
		int paddleX;
		int paddleY;
		sf::RectangleShape paddle;
		// pointer to window, for redrawing paddle
		sf::RenderWindow* w;

		void Draw() {
			w->clear();
			w->draw(paddle);
			// in future, display will be handled by game.
			// Similarly, draw should not clear everything, but...
			// Honestly this whole thing can probably be handled by Move() and Reset() later
			w->display();
		}

		// we need a start of game function, but for now lets work on just moving the paddle
	public:
		Player(sf::RenderWindow* window) {
			w = window;
			int x = w->getSize().x;
			y = w->getSize().y;
			paddle = sf::RectangleShape(sf::Vector2f(x/20, y/6));
			paddle.setFillColor(sf::Color::White);
			paddle.setOrigin(x/40, y/12);
			paddleX = x/10;
			paddleY = y/2;
			paddle.setPosition(paddleX, paddleY);
			Draw();
		}

		void Move(int move) {
			switch (move) {
			case 0:
				if (paddleY != 0) {
					paddleY--;
					paddle.move(0, -1);
				}
				break;

			case 1:
				if (paddleY != y) {
					paddleY++;
					paddle.move(0, 1);
				}
				break;

			default:
				break;
			}
			Draw();
		}


};
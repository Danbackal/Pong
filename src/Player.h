#ifndef PLAYER_H
#define PLAYER_H

class Player {
	private:
		int windowWidth;
		int windowHeight;
		sf::RectangleShape paddle;
		int paddleResetX;
		int paddleResetY;
		void PaddleReset();

	public:
		Player();
		Player(int x, int y, int upperBound);
		sf::RectangleShape* GetPaddle();
		void Move(float move);
		sf::Vector2f getPosition();
};

#endif
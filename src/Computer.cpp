#include "Platform/Platform.hpp"
#include "Computer.h"

Computer::Computer() {
}

Computer::Computer(int x, int y, int upperBound, bool playerOne): Player(x, y, upperBound, playerOne) {}

void Computer::Move(float move) {
	if (move == RESET) {
		PaddleReset();
	} else {
		//move towards ball
		if ((move < _paddle.getPosition().y + _paddle.getSize().y/2) && (_paddle.getPosition().y > _upperBound)) {
			_paddle.move(0, (float)-1/MOVE_SPEED);
		} else {
			if (_paddle.getPosition().y + _paddle.getSize().y < _upperBound + _windowHeight) {
				_paddle.move(0, (float)1/MOVE_SPEED);
			}
		}
	}
}

#ifndef COMPUTER_H
#define COMPUTER_H

#include "GameDef.h"
#include "Player.h"

class Computer: public Player {
	public:
		Computer();
		Computer(int x, int y, int upperBound, bool playerOne);
		void Move(float move);
};

#endif
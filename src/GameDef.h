#ifndef GAMEDEF_H
#define GAMEDEF_H

// Gamestate info
#define NEW_GAME 10 // resets paddles and ball, scores to 0, waits for player input?
#define RESET 11 // resets just paddles and ball, no wait
#define SERVE 12 // starts the round
#define MOVE 13 // allows paddle and ball to move, will also be checking for collisions/score
#define SCORE 14 // will check game score to see if someone won, then switch to reset

// Char info
#define CHAR_P 112
#define CHAR_W 119
#define CHAR_S 115
#define CHAR_UP 128
#define CHAR_DOWN 129

// Extra Stuff?
#define MAX_SCORE 25
#define WALL_COLLISION 20 // top and bottom, need something for goals
#define NO_COLLISION 21
#define MOVE_SPEED 20
// wil figure out paddle collision math later

#endif
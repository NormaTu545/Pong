#pragma once
#include <SFML\Graphics.hpp>

#define PLAYER_1 1
#define PLAYER_2 2
#define PADDLE_PART_WIDTH 100
#define PADDLE_PART_HEIGHT 100

class Paddle {
public:
	Paddle(int playerNum);
	~Paddle();
	
	// Paddle can only move up or down
	void move(bool up);

	// Invisible thirds of the paddle object 
	// for collision detection of ball to parts of the paddle
	sf::FloatRect top;
	sf::FloatRect middle;
	sf::FloatRect bottom;

	// Actual rectangle for the paddle
	sf::RectangleShape paddle;

	// value of 1, for player 1 on the left side,
	// value of 2, for player 2 on the right side
	int player;
};


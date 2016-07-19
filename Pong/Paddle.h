#pragma once
#include <SFML\Graphics.hpp>

//#define PADDLE_PART_WIDTH 100
//#define PADDLE_PART_HEIGHT 100

using namespace sf;

class Paddle {

private:
	Vector2f position;

	// A RectangleShape object
	RectangleShape paddleShape;

	const float paddleSpeed = 2.0f;

public:
	// value of 1, for player 1 on the left side,
	// value of 2, for player 2 on the right side
	int player;

	Paddle(int whichPlayer); //Constructor here~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	FloatRect getPosition(); //will use in Pong.cpp to detect if ball has hit paddle

	RectangleShape getShape(); //getter function for copy of paddleShape

	void moveUp(); //adds paddleSpeed to y position

	void moveDown(); //subtracts paddleSpeed from y position

	void update();
};


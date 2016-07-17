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

	float paddleSpeed = .3f;

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
	/*
	// Paddle can only move up or down
	void move(bool up);

	// Invisible thirds of the paddle object 
	// for collision detection of ball to parts of the paddle
	sf::FloatRect top;
	sf::FloatRect middle;
	sf::FloatRect bottom;

	// Actual rectangle for the paddle
	sf::RectangleShape paddle;
	*/
};


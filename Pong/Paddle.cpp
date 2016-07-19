#include "stdafx.h"
#include "Paddle.h"

#define PLAYER_1 1
#define PLAYER_2 2
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500
#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 100
//Constructor, returns POINTER to object Paddle
Paddle::Paddle(int whichPlayer) {
	//Paddle position
	player = whichPlayer;

	if (player == PLAYER_1) {
		//Initialize X position on LEFT side of screen for player 1
		position.x = 0; 
	}
	else { 
		//Initialize X position to RIGHT side for player 2
		position.x = WINDOW_WIDTH - PADDLE_WIDTH; 
	}
	//Initializes Y position halfway down the screen (for both players)
	position.y = WINDOW_HEIGHT / 2;
	
	paddleShape.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
	paddleShape.setPosition(position);
}

FloatRect Paddle::getPosition()
{
	return paddleShape.getGlobalBounds();
}

RectangleShape Paddle::getShape()
{
	return paddleShape;
}

void Paddle::moveUp()
{
	position.y -= paddleSpeed;
}

void Paddle::moveDown()
{
	position.y += paddleSpeed;
}

void Paddle::update()
{
	paddleShape.setPosition(position);
}
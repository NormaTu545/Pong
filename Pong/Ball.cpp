#include "stdafx.h"
#include "Ball.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500

//~~Constructor here~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
Ball::Ball(float startX, float startY) {
	//Initial position varies, unlike paddles
	position.x = startX; 
	position.y = startY;

	//Ball is a 40x40 square
	ballShape.setSize(sf::Vector2f(BALL_SIDE_LENGTH, BALL_SIDE_LENGTH)); 
	ballShape.setPosition(position);
}

//~~Getter Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
FloatRect Ball::getPosition() {
	return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape() {
	return ballShape;
}

float Ball::getXVelocity() {
	return xVelocity; //MARK: DON'T KNOW WHAT THIS IS FOR YET.
}

//~~When ball hits something~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Ball::hitTopOrBottom() {
	yVelocity = -yVelocity;
}

void Ball::hitPaddle() {
	//Alters by 30 frames of movement
	position.x -= (xVelocity * 30); //prevents bug where ball sticks to paddle
	xVelocity = -xVelocity;

}

void Ball::hitSides() {
	//Resets position of the ball to start next round
	position.x = WINDOW_WIDTH / 2;
	position.y = WINDOW_HEIGHT / 2;

	//NOTE: THIS IS WHEN A SCORE OUGHT TO BE INCREMENTED JUST SAYIN' DON'T FORGET.
} 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void Ball::update() {
	//Update the ball position variables
	position.y += yVelocity;
	position.x += xVelocity;

	//Move the ball and the paddle
	ballShape.setPosition(position);
}
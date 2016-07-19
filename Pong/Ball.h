#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
#define BALL_SIDE_LENGTH 40
class Ball {

private:
	Vector2f position;

	// A RectangleShape object called ref
	RectangleShape ballShape;

	float xVelocity = 3.0f;
	float yVelocity = 3.0f;

public:
	Ball(float startX, float startY); //Constructor

	FloatRect getPosition(); //will use in Pong.cpp for collision detection

	RectangleShape getShape(); //passes copy of shape for drawing

	float getXVelocity(); //getter function of private xVelocity variable

						  //"reboundSides" code here
	void hitTopOrBottom();  //Flips sign of yVelocity

							//Code for BAT from "bat or top" here
	void hitPaddle(); //Alters yPosition of ball so it won't get "stuck" to the paddle

					  //THis has been fixed by my dearest love
	void hitSides(); //Gives point & repositions ball

	void update();
};
// Pong.cpp : Defines the entry point for the console application.
// Is essentially Main.

#include "stdafx.h"
#include "Paddle.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500
#define PLAYER_1 1
#define PLAYER_2 2

//using namespace sf //avoids having to say sf:: for all SFML functions/classes
//but I'm choosing to not do this^ so I can learn first

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PONGBALLS");
	
	//~~Loading in data~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	int score_P1 = 0; //Left of net
	int score_P2 = 0; //Right of net

	//Creat two instances of the paddle
	Paddle paddle_P1(PLAYER_1); //Left
	Paddle paddle_P2(PLAYER_2); //Right

	//Create a ball instance in the middle of the window
	Ball ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	//Create a "Text" object 
	Text hud; //aka Heads Up Dispay

	//Font is "karmic_arcade" from dafont.com
	Font font;
	font.loadFromFile("kaFont.ttf");

	//Set the font to our message
	hud.setFont(font);

	//Make it kinda big
	hud.setCharacterSize(50);

	//Choose a color 
	hud.setColor(sf::Color::White);

	//Draws the Pong "net" at the middle of the window
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(WINDOW_WIDTH/2, 0)), 
		sf::Vertex(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT))
	};

	//Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	//Start Game Loop
	while (window.isOpen()) {  //~~~~~~~~~CODE BODY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//~~Clear/Draw/Display: Completely refreshes everything at each iteration of main~~
		//Mandatory so things from previous frames go away at next frames
		window.clear();

		window.draw(line, 2, sf::Lines); //NET IN MIDDLE
		window.draw(paddle); //Paddle Test

		//Mandatory double-buffering, takes what was drawn & displays to window from hidden buffer
		window.display();
	} //~~~~~~~~~~~~~~~~~~~~~~~~~CODE BODY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	return EXIT_SUCCESS;
} //End of main
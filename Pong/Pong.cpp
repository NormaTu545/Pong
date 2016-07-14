// Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Paddle.h"
#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PONG");
	
	//Draws the Pong "net" at the middle of the window
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(WINDOW_WIDTH/2, 0)), 
		sf::Vertex(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT))
	};

	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	//RECTANGLE TEST (width, height)
	sf::RectangleShape paddle(sf::Vector2f(20, 100));

	//Start Game Loop
	while (window.isOpen()) {  //~~~~~~~~~CODE BODY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
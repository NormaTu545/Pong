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

	//~~[Loading in data]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	int score_P1 = 0; //Left of net
	int score_P2 = 0; //Right of net
	bool gameEnded = false;

					  //Creat two instances of the paddle
	Paddle paddle_P1(PLAYER_1); //Left
	Paddle paddle_P2(PLAYER_2); //Right

								//Create a ball instance in the middle of the window
	Ball ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	//Create a "Text" object 
	Text hud; //aka Heads Up Dispay

			  //Font is "karmatic_arcade" from dafont.com
	Font font;
	font.loadFromFile("kaFont.ttf");

	//Set the font to our message
	hud.setFont(font);

	//Make it kinda big
	hud.setCharacterSize(40);

	//Choose a color 
	hud.setColor(sf::Color::White);

	//Load the Pong "net" at the middle of the window
	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(WINDOW_WIDTH / 2, 0)),
		sf::Vertex(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT))
	};

	//Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	//~~~[Start Game Loop]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		} //Stops everything if window is closed by user

		  //~~[KEY EVENT HANDLING]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			//move player 1's paddle up
			paddle_P1.moveUp();
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			//move player 1's paddle down
			paddle_P1.moveDown();
		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			//fire a pongball from player 1
			//[TO BE IMPLEMENTED]
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			//move player 2's paddle up
			paddle_P2.moveUp();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			//move player 2's paddle down
			paddle_P2.moveDown();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			//fire a pongball from player 2 
			//[TO BE IMPLEMENTED]
		}
		else if (Keyboard::isKeyPressed(Keyboard::Space)) {
			//[SPACE TO RESTART GAME AFTER SOMEONE WINS]
			if (gameEnded) { gameEnded = false; }
			score_P1 = 0; //resets to 0
			score_P2 = 0; //resets to 0
			ball.hitSides(); //Recenters ball
		}

		/*
		*********************************************************************
		[Event Handling]
		*********************************************************************
		*/

		bool player2scored = ball.getPosition().left < 0;
		bool player1scored = ball.getPosition().left + 40 > WINDOW_WIDTH;

		//~~[Handle ball hitting sides/going past a paddle]~~~~~~~~~~~~~~~~~~~//
		if (player1scored || player2scored) {
			if (player2scored) {
				//Give player 2 a point
				score_P2++;
			}
			else {
				//Give player 1 a point
				score_P1++;
			}
			//Reposition ball for next round
			ball.hitSides();
		}

		//~~[Handle ball hitting top or bottom of window]~~~~~~~~~~~~~~~~~~~~~~~~//
		bool hit_top = ball.getPosition().top < 0;
		bool hit_bottom = ball.getPosition().top > WINDOW_HEIGHT - BALL_SIDE_LENGTH;

		if (hit_top || hit_bottom) {
			//Flips sign of y component so ball rebounds
			ball.hitTopOrBottom();
		}

		//~~[Handle ball hitting a paddle]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
		bool hitPaddleP1 = ball.getPosition().intersects(paddle_P1.getPosition());
		bool hitPaddleP2 = ball.getPosition().intersects(paddle_P2.getPosition());

		if (hitPaddleP1 || hitPaddleP2) {
			// Hit detected so reverse the ball X direction
			ball.hitPaddle();
		}
		//~~~~~~~~~~~~~~~~~~~~~~~[UPDATE]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
		if (!gameEnded) {
			ball.update();
			paddle_P1.update();
			paddle_P2.update();
		}
		// Update the HUD scores
		std::stringstream ss; //for concatenation
		ss << "                                        " << score_P1 << "    " << score_P2;
		hud.setString(ss.str());
		

		//Check for win (Someone gets 7 points)
		if (score_P1 == 7 || score_P2 == 7) {
			int winnerNumber = 0; //initialize to 0

			if (score_P1 == 7) winnerNumber = PLAYER_1;
			if (score_P2 == 7) winnerNumber = PLAYER_2;

			std::stringstream winMsg; //To take place of "ss"
			winMsg << "PLAYER " << winnerNumber << " WINS! (Space) to play again.";

			gameEnded = true;

			//stops the game
			if (gameEnded) {
				hud.setString(winMsg.str());
				ball.stayStill();
			}
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

		/*Clear/Draw/Display: Completely refreshes
		*everything at each execution of main
		*Mandatory so things from previous frames
		*go away at next frames
		*/
		//window.clear(); //defaults to black

		// Clear everything from the last frame
		window.clear(Color(26, 128, 182, 255)); //pretty blue background

		window.draw(paddle_P1.getShape());
		window.draw(paddle_P2.getShape());
		window.draw(ball.getShape());

		// Draw our score
		window.draw(hud);
		window.draw(line, 2, sf::Lines); //NET IN MIDDLE

										 //Mandatory double-buffering, takes what was 
										 //drawn & displays to window from hidden buffer
		window.display();
	} //~~~~~~~~~~~~~~~~~~~~~~[END OF CODE BODY]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	return EXIT_SUCCESS;
} //End of main
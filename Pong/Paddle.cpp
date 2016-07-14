#include "stdafx.h"
#include "Paddle.h"

//Constructor, returns POINTER to object Paddle
Paddle::Paddle(int playerNum) {
 
	//Make top FloatRect
	top.top = 0.f;
	top.left = 0.f;
	top.width = PADDLE_PART_WIDTH;
	top.height = PADDLE_PART_HEIGHT;

	middle.top = 5.f;
	middle.left = 10.f;



}

//Destructor
Paddle::~Paddle() {
	//Leaving blank since we don't need to destroy paddle
}

void Paddle::move(bool up) {

}
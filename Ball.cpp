#include "Ball.h"
#include "pch.h"

Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	ballShape.setRadius(20);
	ballShape.setPosition(position);

}


FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

CircleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getXVelocity()
{
	return xVelocity;
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop()
{
	position.y -= (yVelocity * 30);
	yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
	position.y = 1;
	position.x = 500;
}

void Ball::setColor(int score)
{
	if (score == 0)
		ballShape.setFillColor(Color(255, 255, 255));
	else if (score == 1)
		ballShape.setFillColor(Color(242, 129, 72));
	else if (score == 2)
		ballShape.setFillColor(Color(255, 255, 133));
	else if (score == 3)
		ballShape.setFillColor(Color(51, 255, 153));
	else if (score == 4)
		ballShape.setFillColor(Color(102, 255, 255));
	else
		ballShape.setFillColor(Color(51, 102, 255));
}

void Ball::update()
{
	position.y += yVelocity;
	position.x += xVelocity;

	ballShape.setPosition(position);
}
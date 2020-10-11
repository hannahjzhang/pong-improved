#include "Bat.h"
#include "pch.h"

Bat::Bat(float startX, float startY)
{

	position.x = startX;
	position.y = startY;
	batShape.setSize(sf::Vector2f(100, 15));
	batShape.setPosition(position);

}

FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return batShape;
}

void Bat::moveLeft()
{
	position.x -= batSpeed;
	// stops on the left side
	if (getPosition().left < 0)
		position.x = 0;
}

void Bat::moveRight()
{
	position.x += batSpeed;
	// stops on the right side
	if (getPosition().left + 100 > 1024)
		position.x = 1024 - 100;
}

void Bat::setColor(int score)
{
	if (score == 0)
		batShape.setFillColor(Color(255, 255, 255));
	else if (score == 1)
		batShape.setFillColor(Color(242, 129, 72));
	else if (score == 2)
		batShape.setFillColor(Color(255, 255, 133));
	else if (score == 3)
		batShape.setFillColor(Color(51, 255, 153));
	else if (score == 4)
		batShape.setFillColor(Color(102, 255, 255));
	else
		batShape.setFillColor(Color(51, 102, 255));
}


void Bat::update()
{
	batShape.setPosition(position);
}
#pragma once
#include <SFML/Graphics.hpp>
#include "pch.h"

using namespace sf;


class Bat
{
private:
	Vector2f position;
	RectangleShape batShape;

	float xVelocity = .5f;
	float yVelocity = .5f;

	float batSpeed = .8f;

public:
	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void setColor(int score);
	void update();

};
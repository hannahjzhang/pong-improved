#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f position;
	// change ball shape to a circle (also 2 other places)
	CircleShape ballShape;

	float xVelocity = .8f;
	float yVelocity = .8f;

public:
	Ball(float startX, float startY);
	FloatRect getPosition();
	CircleShape getShape();

	float getXVelocity();
	void reboundSides();
	void reboundBatOrTop();
	void hitBottom();
	void setColor(int score);
	void update();
};
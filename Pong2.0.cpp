// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "pch.cpp"
#include <sstream>
#include <cstdlib>
#include "bat.h"
#include "ball.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Hannah's Pong Game");

	Bat bat(windowWidth / 2, windowHeight - 60);
	Ball ball(windowWidth / 2, 1);

	sf::Texture playerTex;
	playerTex.loadFromFile("Textures/sunbeach.jpg");

	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTex);

	int score = 0;
	
	Text scoreboard;
	// scoreboard.setColor(sf::Color::White);

	// scoreboard.setColor(sf::Color::White);
	//scoreboard.setPosition(500, 10);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}

		// Ball hit the top of the window
		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();
		}

		// Ball hit the bottom of the window
		if (ball.getPosition().top > windowHeight)
		{
			ball.hitBottom();
			// update score
			if (score >= 5)
				score = 5;
			else
				score += 1;
		}

		// display game over
		if (score == 5)
			scoreboard.setString("Game Over");

		// Ball hits the sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.reboundSides();
		}

		// Ball hit the bat
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			ball.reboundBatOrTop();
		}

		// draw score or game over
		if (score == 5)
			scoreboard.setString("Game Over");
		else
			scoreboard.setString(std::to_string(score));

		// Draw scoreboard
		// std::string str = std::to_string(score);
		// std::cout << score << " ==> " << str << std::endl;


		ball.update();
		bat.update();

		window.clear(Color(140, 216, 255));
		window.draw(playerSprite);
		ball.setColor(score);
		bat.setColor(score);
		window.draw(scoreboard);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

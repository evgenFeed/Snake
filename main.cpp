//
//  main.cpp
//  Snake
//
//  Created by Evgen on 15.10.2018.
//  Copyright © 2018 Evgen Inc. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"
#include "time.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SNAKE!");
	window.setFramerateLimit(10);
	Snake snake;
	Apple apple;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		std::cout << " size " << snake.getNodes().size() << std::endl << std::endl;
		snake.ChangeDirection();
		snake.Move();
		for (int i = 0; i < snake.getNodes().size(); i++)
		{
			std::cout <<"X = "<< snake.getNodes()[i].getX() <<"Y = "<< snake.getNodes()[i].getY() << std::endl;
		}
		if (snake.getNodes().front().getShape().getGlobalBounds().intersects(apple.appleShape().getGlobalBounds()))
		{
			apple.reGenerate();
			snake.addNewNode();
		}
		apple.draw(window);
		snake.draw(window);
		window.display();
	}
	return 0;
}

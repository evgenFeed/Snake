#pragma once
#include <vector>
#include <iostream>


class Apple
{
public:
	Apple()
	{
		srand(time(NULL));
		apple.setPosition(rand()% 300+20 * 20,rand()% 200+20 * 20);
		apple.setSize(sf::Vector2f(20.0f, 20.0f));
		apple.setOrigin(10, 10);
		apple.setFillColor(sf::Color::Red);
	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(apple);
	}
	sf::RectangleShape appleShape()
	{
		return apple;
	}
	void reGenerate()
	{
		
		apple.setPosition(rand() % 300 + 20 * 20, rand() % 200 + 20 * 20);
	}
private:
	sf::RectangleShape apple;
};

class Zveno
{
public:
	Zveno(int x, int y)
	{
		this->x = x;
		this->y = y;
		zven.setSize(sf::Vector2f(20, 20));
		zven.setOrigin(10, 10);
		zven.setPosition(this->x * STEP, this->y * STEP);
		zven.setFillColor(sf::Color::Green);
	}
	void draw(sf::RenderWindow& window)
	{
		zven.setPosition(x*STEP, y*STEP);
		window.draw(zven);
	}
	sf::RectangleShape& getShape()
	{
		return zven;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	void setXY(int x, int y)
	{
		this->y = y;
		this->x = x;
	}
private:
	const short int STEP = 20;
	sf::RectangleShape zven;
	int x;
	int y;
};

class Snake
{
public:
	Snake()
	{
		nodes.push_back({10, 10});
	}
	~Snake() {}
	void ChangeDirection()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != RIGHT)
		{
			direction = LEFT;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != LEFT)
		{
			direction = RIGHT;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != DOWN)
		{
			direction = UP;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != UP)
		{
			direction = DOWN;
		}
	}
	void Move()
	{	
		/*
		int tmpX = nodes.front().getX();
		int tmpY = nodes.front().getY();
		*/
		
		if (nodes.front().getShape().getPosition().x <= 760 && direction != RIGHT)
		{
			nodes.front().setX(nodes.front().getX() - 1);
		}
		if (nodes.front().getShape().getPosition().x >=40 && direction != LEFT)
		{
			nodes.front().setX(nodes.front().getX() + 1);
		}
		if (nodes.front().getShape().getPosition().y >= 40 && direction != DOWN)
		{
			nodes.front().setY(nodes.front().getY() - 1);
		}
		if (nodes.front().getShape().getPosition().y <= 560 && direction != UP)
		{
			nodes.front().setY(nodes.front().getY() + 1);
		}
		
		if (nodes.size() > 1)
		{
			for (int i = nodes.size()-1; i >= 1; i-- )
			{
				nodes[i].setXY(nodes[i - 1].getX(), nodes[i - 1].getY());
			}
		}
		
		
	}
	void draw(sf::RenderWindow& window)
	{
		//nodes.front().getShape().setPosition(nodes.front().getX()*STEP, nodes.front().getY()*STEP);
		/*int i = 0;
		for (i; i <= nodes.size()-1; i++)
		{
			nodes[i].draw(window, nodes[i].getX(),nodes[i].getY());
		}*/
		//cout << "Head x = " << nodes.front().getX() << "\ty - " << nodes.front().getY() << endl;
		//cout << "Real Head x = " << nodes.front().getShape().getPosition().x << "\ty - " << nodes.front().getShape().getPosition().y << endl;
		for (auto& n : nodes)
		{
			n.draw(window);
		}
	}
	std::vector<Zveno>& getNodes()
	{
		return nodes;
	}
	void addNewNode()
	{
		if (nodes.size() == 1)
		{
			if (direction == UP)
			{
				Zveno tmp(nodes.front().getX(),nodes.front().getY() + 1);
				nodes.push_back(tmp);
			}
			else if (direction == DOWN)
			{
				Zveno tmp(nodes.front().getX(), nodes.front().getY() - 1);
				nodes.push_back(tmp);
			}
			else if (direction == LEFT)
			{
				Zveno tmp(nodes.front().getX() + 1, nodes.front().getY());
				nodes.push_back(tmp);
			}
			else if (direction == RIGHT)
			{
				Zveno tmp(nodes.front().getX() - 1, nodes.front().getY());
				nodes.push_back(tmp);
			} 
		}
		else
		{
			
			Zveno tmp(nodes.back().getX(), nodes.back().getY());
			nodes.push_back(tmp);
			//cout << nodes.size() << endl;
		}
	}
private:
	enum directions { UP, RIGHT, DOWN, LEFT };
	int direction;
	const float STEP = 20;
	std::vector<Zveno> nodes;
};

#pragma once
// Author Dr. Noel O'Hara
// Particle.h
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
class Particle
{
public:
	int timetoLive;
	sf::Vector2f velocity;
	sf::RectangleShape shape;
	
	void Draw(sf::RenderWindow& win)
	{
		if (timetoLive>0)
		{
			win.draw(shape);
		}
	}
	void Update()
	{
		if (timetoLive>0)
		{
			shape.move(velocity);
		
			timetoLive--;
		}
	}

	Particle(){}

	Particle(sf::Vector2f pos, sf::Vector2f vel)
	{
		shape.setSize(sf::Vector2f(6,6));
		shape.setPosition(pos);
		shape.setFillColor(sf::Color::Blue);

		velocity=vel;
		//timetoLive = 200;
		timetoLive=rand()%150;

	}
};

	
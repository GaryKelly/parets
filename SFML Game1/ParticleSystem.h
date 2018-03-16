#pragma once
// Author Dr. Noel O'Hara
// ParticleSystem.h
#include "Particle.h"
#define maxParticles 50
class ParticleSystem
{
public:
	
	Particle particles[maxParticles];
	sf::Vector2f position;
	void Initialise(sf::Vector2f pos)
	{
		position=pos;
		for (int i =0;i<maxParticles;i++)
		{
			particles[i] = Particle(position,sf::Vector2f(rand() / double(RAND_MAX)*4-2,rand() / double(RAND_MAX)*4-2));
		}
	}
	void Update()
	{
		for (int i =0;i<maxParticles;i++)
		{
			
			particles[i].Update();
			
		
		}
	}
	void Draw(sf::RenderWindow &win )
	{
		for (int i =0;i<maxParticles;i++)
		{
			particles[i].Draw(win);
		}
	}

	ParticleSystem(){}
};


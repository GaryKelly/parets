#pragma once
// Author Dr. Noel O'Hara
// Particle.h
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>




// Author Noel O'Hara
// part of Game.cpp for particles

#include "Game.h"

#include "Particle.h"
#include "ParticleSystem.h"
#include "fire.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{ false } //when true game will exit
{
	pauseCounter = 0;
	fire.Initialise(sf::Vector2f(100, 100));
	for (int i = 0; i < 5; i++)
	{
		fires[i].Initialise(sf::Vector2f(100 + 120 * i, 300));
	}
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	if (pauseCounter > 0)
	{
		pauseCounter--;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pauseCounter <= 0)
	{
		sf::Vector2i localPosition = sf::Mouse::getPosition(m_window);
		pauseCounter = 60;
		particleSystem.Initialise(sf::Vector2f(localPosition.x, localPosition.y));
	}



	particleSystem.Update();
	fire.Update();
	for (int i = 0; i < 5; i++)
	{
		fires[i].Update();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	particleSystem.Draw(m_window);
	fire.Draw(m_window);
	for (int i = 0; i < 5; i++)
	{
		fires[i].Draw(m_window);
	}
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{


}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{

}

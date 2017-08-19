#include "TestGame.hpp"
#include <iostream>
#include "States/StatePlaying.hpp"
#include "States/StatePaused.hpp"

namespace tg
{
	void TestGame::begin()
	{
		m_title = "MoleEngine test game";
		createWindow(800, 600);
		m_fixedUpdateInterval = sf::seconds(1.0f / 120.0f); //120fps

		m_stateManager.addState("PLAYING", new StatePlaying());
		m_stateManager.transitionTo("PLAYING");
		m_stateManager.addState("PAUSED", new StatePaused());
		
		Game::begin();
	}

	void TestGame::continuousUpdate(sf::Time timeElapsed)
	{
		m_stateManager.continuousUpdate(timeElapsed);
	}

	void TestGame::fixedUpdate()
	{
		m_stateManager.fixedUpdate();
	}

	void TestGame::draw()
	{
		m_mainWindow.clear(sf::Color::Cyan);
		
		m_stateManager.draw(m_mainWindow, sf::RenderStates());

		m_mainWindow.display();
	}

	TestGame::TestGame()
	{
	}

	TestGame::~TestGame()
	{
	}
}

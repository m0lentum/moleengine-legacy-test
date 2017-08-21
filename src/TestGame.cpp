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

		StatePlaying* playing = new StatePlaying();
		playing->registerAssetManager(&m_assetManager);
		m_stateManager.addState("PLAYING", playing);
		playing->load(); //TODO this is a clumsy way to setup the states, figure out something better
		
		StatePaused* paused = new StatePaused();
		paused->registerAssetManager(&m_assetManager);
		m_stateManager.addState("PAUSED", paused);
		paused->load();
		
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

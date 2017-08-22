#include "TestGame.hpp"
#include <iostream>
#include "States/StatePlaying.hpp"
#include "States/StatePaused.hpp"
#include <ME/Space.hpp>
#include "Objects/ObjTest.hpp"

namespace tg
{
	void TestGame::begin()
	{
		m_title = "MoleEngine test game";
		createWindow(800, 600);
		m_fixedUpdateInterval = sf::seconds(1.0f / 120.0f); //120fps

		m_assetManager.loadTexture("assets/Sprite-0001.png", "Sprite0001");

		std::shared_ptr<me::Space> space = std::make_shared<me::Space>();
		space->addObject(new ObjTest(&m_assetManager));

		//Setup the game states. TODO: make this process more readable / easier to remember
		StatePlaying *playing = new StatePlaying();
		playing->registerAssetManager(&m_assetManager);
		playing->loadSpace(space);
		m_stateManager.addState("PLAYING", playing); 
		
		StatePaused *paused = new StatePaused();
		paused->registerAssetManager(&m_assetManager);
		paused->loadSpace(space);
		m_stateManager.addState("PAUSED", paused);

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

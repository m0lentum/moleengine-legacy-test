#include "TestGame.hpp"
#include "States/StatePlaying.hpp"
#include "States/StatePaused.hpp"
#include <ME/Space.hpp>
#include <ME/Physics/VectorMath.hpp>
#include <ME/Input/Keyboard.hpp>
#include <ME/GameObject.hpp>
#include <ME/Graphics/Graphic.hpp>
#include <iostream>

void printVector(const sf::Vector2f &vec)
{
	std::cout << "(" << vec.x << ", " << vec.y << ")" << std::endl;
}

namespace tg
{
	void TestGame::begin()
	{
		m_title = "MoleEngine test game";
		createWindow(800, 600);
		m_fixedUpdateInterval = sf::seconds(1.0f / 120.0f); //120fps

		m_assetManager.loadTexture("assets/Sprite-0001.png", "Sprite0001");

		me::Space *space = new me::Space();

		me::GameObject *obj = new me::GameObject();
		obj->addBehavior(me::Graphic::makeCircle(50, 30, sf::Color::Green));
		space->addObject(obj);

		me::GameObject *obj2 = new me::GameObject();
		obj2->addBehavior(me::Graphic::makeCircle(100, 30, sf::Color::Blue));
		obj2->setPosition(300, 200);
		obj2->setScale(2.0f, 1.5f);
		space->addObject(obj2);


		// Setup the game states.
		m_statePlaying.registerAssetManager(&m_assetManager);
		m_statePlaying.registerStateManager(&m_stateManager);
		m_statePlaying.loadSpace(space);
		m_statePlaying.registerStatePaused(&m_statePaused);

		m_statePaused.registerAssetManager(&m_assetManager);
		m_statePaused.registerStateManager(&m_stateManager);
		m_statePaused.loadSpace(space);
		m_statePaused.registerStatePlaying(&m_statePlaying);

		m_stateManager.transitionTo(&m_statePlaying);

		me::Keyboard::trackKey(me::Keyboard::Space);
		me::Keyboard::trackKey(me::Keyboard::Return);
		me::Keyboard::trackKey(me::Keyboard::M);

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

#include "TestGame.hpp"
#include "States/StatePlaying.hpp"
#include "States/StatePaused.hpp"
#include <ME/Space.hpp>
#include "Objects/AllObjects.hpp"
#include <ME/Physics/VectorMath.hpp>
#include <ME/Input/Keyboard.hpp>
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

		std::shared_ptr<me::Space> space = std::make_shared<me::Space>();
		space->addObject(std::make_shared<ObjTest>(&m_assetManager));
		std::shared_ptr<PhysObjTest> po1 = std::make_shared<PhysObjTest>(80);
		po1->setPosition(300, 300);
		space->addObject(po1);
		std::shared_ptr<PhysObjMoving> po2 = std::make_shared<PhysObjMoving>(100);
		po2->setPosition(500, 200);
		space->addObject(po2);


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

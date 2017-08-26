#include "TestGame.hpp"
#include "States/StatePlaying.hpp"
#include "States/StatePaused.hpp"
#include <ME/Space.hpp>
#include "Objects/ObjTest.hpp"
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

		//Setup the game states.
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

		// print out some vector math for ghetto unit testing
		sf::Vector2f vec(10, 0);
		sf::Vector2f v2(-5, 10);
		printVector(vec);
		printVector(-vec);
		std::cout << me::VectorMath::dot(vec, v2) << std::endl;
		std::cout << me::VectorMath::getLength(v2) << std::endl;
		printVector(me::VectorMath::normalize(v2));
		printVector(me::VectorMath::projectToVector(vec, v2));
		printVector(me::VectorMath::rotateRad(vec, 3.1415927f / 2));
		printVector(me::VectorMath::rotateDeg(vec, 90));
		printVector(me::VectorMath::rotateDeg(vec, 45));
		printVector(me::VectorMath::leftNormal(v2));
		printVector(me::VectorMath::rightNormal(v2));

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

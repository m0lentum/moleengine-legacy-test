#include "TestGame.hpp"
#include <ME/Space.hpp>
#include <ME/Physics/VectorMath.hpp>
#include <ME/Input/Keyboard.hpp>
#include <ME/GameObject.hpp>
#include <ME/Graphics/Graphic.hpp>
#include <ME/Graphics/AnimatedSprite.hpp>
#include <ME/Graphics/GraphicController.hpp>
#include <ME/ComponentContainer.hpp>
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

		obj = space->createObject();
		obj->addComponent<me::Graphic>(me::Graphic::makeCircle(70, 20, sf::Color::Black));
		obj->setPosition(200, 300);
		obj->addComponent<me::Graphic>(me::Graphic::makeRect(100, 70));
		obj->addComponent<me::AnimatedSprite>(m_assetManager.getTexture("Sprite0001"), 
					sf::Vector2i(), sf::Vector2i(100, 100), 5, sf::milliseconds(400));

		for (int i = 0; i < 100; i++)
		{
			me::GameObject *o = space->createObject();
			o->addComponent<me::Graphic>(me::Graphic::makeRect(500, 20, sf::Color::Green));
			o->removeComponent<me::Graphic>();
		}

		obj->removeComponent<me::Graphic>();

		std::cout << space->getContainer<me::Graphic>()->getSize() << std::endl;
		std::cout << space->getContainer<me::AnimatedSprite>()->getSize() << std::endl;
		

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

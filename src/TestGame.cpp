#include "TestGame.hpp"
#include <ME/Space.hpp>
#include <ME/Physics/VectorMath.hpp>
#include <ME/Physics/Physics.hpp>
#include <ME/Input/Keyboard.hpp>
#include <ME/GameObject.hpp>
#include <ME/Graphics/Graphic.hpp>
#include <ME/Graphics/AnimatedSprite.hpp>
#include <ME/Graphics/Renderer.hpp>
#include <ME/ComponentContainer.hpp>
#include <ME/Physics/RigidBody.hpp>
#include <ME/Physics/ColliderCircle.hpp>
#include <ME/Physics/ColliderRect.hpp>
#include <ME/Physics/ColliderPolygon.hpp>
#include <initializer_list>
#include <ME/Input/KeyboardController.hpp>
#include <ME/Input/MouseController.hpp>
#include "ObjectFactory.hpp"
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

		ObjectFactory::makePlayer(&m_mainSpace);

		for (int i = 1; i < 10; i++)
		{
			me::GameObject *obj = ObjectFactory::makeBox(&m_mainSpace, 30 + 5 * i, 80 - 5 * i);
			obj->setPosition(600 - i * 50, i * 50);
			obj->getComponent<me::RigidBody>()->angularVelocity = i % 2 == 0 ? 2 : -2;
		}

		me::GameObject *floor = ObjectFactory::makeBox(&m_mainSpace, 1000, 50);
		floor->setPosition(400.0f, 550.0f);
		floor->getComponent<me::RigidBody>()->isStatic = true;


		m_mainSpace.createSystem<me::Renderer>();
		m_mainSpace.createSystem<me::Physics>(sf::Vector2f(0, 0.005f));
		

		// Setup the game states.
		StatePlaying *playing = m_stateManager.createState<StatePlaying>();
		playing->loadSpace(&m_mainSpace);
		StatePaused *paused = m_stateManager.createState<StatePaused>();
		paused->loadSpace(&m_mainSpace);

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

	TestGame::TestGame() :
		m_mainSpace(100)
	{
	}

	TestGame::~TestGame()
	{
	}
}

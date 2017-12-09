#include "TestGame.hpp"
#include <ME/Space.hpp>
#include <ME/Physics/VectorMath.hpp>
#include <ME/Input/Keyboard.hpp>
#include <ME/GameObject.hpp>
#include <ME/Graphics/Graphic.hpp>
#include <ME/Graphics/AnimatedSprite.hpp>
#include <ME/Graphics/Renderer.hpp>
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

		me::GameObject *obj = m_mainSpace.createObject();
		obj->addComponent<me::Graphic>(me::Graphic::makeCircle(70, 20, sf::Color::Black));
		obj->setPosition(200, 300);
		obj->addComponent<me::Graphic>(me::Graphic::makeRect(100, 70));
		obj->addComponent<me::AnimatedSprite>(m_assetManager.getTexture("Sprite0001"), 
					sf::Vector2i(), sf::Vector2i(100, 100), 5, sf::milliseconds(400));
		obj->removeComponent<me::Graphic>();

		sf::Clock clock;
		for (int i = 0; i < 10000; i++)
		{
			me::GameObject *obj = m_mainSpace.createObject();
			obj->addComponent<me::Graphic>(me::Graphic::makeCircle(2, 20, sf::Color::Black));
			obj->move(sf::Vector2f((i % 300) * 4, (i / 300) * 4));
			if (i % 100 == 0) obj->destroy();
		}
		std::cout << "Time to make objects: " << clock.getElapsedTime().asMilliseconds() << " ms" << std::endl;

		m_mainSpace.createObject();

		m_mainSpace.createSystem<me::Renderer>();
		

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
		m_mainSpace(9901)
	{
	}

	TestGame::~TestGame()
	{
	}
}

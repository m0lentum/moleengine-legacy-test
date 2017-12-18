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
		obj->addComponent<me::RigidBody>();
		me::ColliderRect *coll = obj->addComponent<me::ColliderRect>(60, 80);
		obj->addComponent<me::Graphic>(coll->toVertexArray());

		me::RigidBody *rb = obj->getComponent<me::RigidBody>();
		//rb->accelerate(sf::Vector2f(2.0f, 0));
		rb->angularVelocity = 5.0f;
		rb->isKinematic = true;
		obj->setPosition(10, 300);
		me::KeyboardController *cont = obj->addComponent<me::KeyboardController>();
		cont->onKeyPressed = [obj](const sf::Event::KeyEvent &evt)
		{
			if (evt.code == sf::Keyboard::Right) obj->getComponent<me::RigidBody>()->accelerate(sf::Vector2f(2.0f, 0));
		};
		me::MouseController *mcont = obj->addComponent<me::MouseController>();
		mcont->onMouseButtonPressed = [obj](const sf::Event::MouseButtonEvent &evt)
		{
			obj->getComponent<me::RigidBody>()->accelerate(sf::Vector2f(-1.0f, 0));
		};

		me::GameObject *obj2 = m_mainSpace.createObject();
		obj2->addComponent<me::RigidBody>()->angularVelocity = 3;
		me::ColliderRect *coll2 = obj2->addComponent<me::ColliderRect>(50, 90);
		obj2->addComponent<me::Graphic>(coll2->toVertexArray(sf::Color::Black));
		obj2->setPosition(400, 310);


		m_mainSpace.createSystem<me::Renderer>();
		m_mainSpace.createSystem<me::Physics>();
		

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

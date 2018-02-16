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
#include <ME/Utility/TimerSystem.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>
#include <iostream>

void printVector(const sf::Vector2f &vec)
{
	std::cout << "(" << vec.x << ", " << vec.y << ")" << std::endl;
}

namespace tg
{
	void TestGame::init()
	{
		m_title = "MoleEngine test game";
		createWindow(800, 600);
		m_fixedUpdateInterval = sf::seconds(1.0f / 120.0f);

		m_assetManager.loadTexture("assets/Sprite-0001.png", "Sprite0001");

		ObjectFactory::makePlayer(&m_mainSpace);

		for (int i = 1; i < 5; i++)
		{
			me::GameObject *obj = ObjectFactory::makeBall(&m_mainSpace, 30 + 3 * i);
			obj->setPosition(400 - i * 100, i * 100);
		}

		for (int j = 1; j < 5; j++)
		{
			me::GameObject *obj = ObjectFactory::makeBox(&m_mainSpace, 80 + 15 * j, 100 - 15 * j);
			obj->setPosition(600 - j * 100, j * 100);
			obj->setRotation(30 * j);
		}

		me::GameObject *poly1 = ObjectFactory::makePolygon(&m_mainSpace, { 0, 10, 50, 20, 80, -10, 0, -20, -30, -10 }, sf::Color::White);
		poly1->setPosition(600, 300);

		me::GameObject *poly2 = ObjectFactory::makePolygon(&m_mainSpace, { 500, 600, 400, 600, 450, 650 }, sf::Color::White);
		poly2->setPosition(450, 400);

		me::GameObject *floor = ObjectFactory::makeBox(&m_mainSpace, 700, 50);
		floor->setPosition(400.0f, 550.0f);
		floor->getComponent<me::RigidBody>()->isStatic = true;


		m_mainSpace.createSystem<me::Renderer>();
		m_mainSpace.createSystem<me::Physics>();
		m_mainSpace.createSystem<me::TimerSystem>();
		

		// Setup the game states.
		StatePlaying *playing = m_stateManager.createState<StatePlaying>();
		playing->loadSpace(&m_mainSpace);
		StatePaused *paused = m_stateManager.createState<StatePaused>();
		paused->loadSpace(&m_mainSpace);

		me::Keyboard::trackKey(me::Keyboard::Space);
		me::Keyboard::trackKey(me::Keyboard::Return);
		me::Keyboard::trackKey(me::Keyboard::M);
	}

	void TestGame::continuousUpdate(sf::Time timeElapsed)
	{
		m_stateManager.continuousUpdate(timeElapsed);

		ImGui::SFML::Update(m_mainWindow, timeElapsed);
		ImGui::Begin("Test window");
		ImGui::InputText("Test field", m_testTextBuffer, 255);
		if (ImGui::Button("Poop"))
		{
			std::cout << "Poop" << std::endl;
		}
		ImGui::End();

		ImGui::EndFrame();
	}

	void TestGame::fixedUpdate()
	{
		m_stateManager.fixedUpdate();
	}

	void TestGame::draw()
	{
		m_mainWindow.clear(sf::Color::Cyan);
		
		m_stateManager.draw(m_mainWindow, sf::RenderStates());
		ImGui::SFML::Render(m_mainWindow);
		
		m_mainWindow.display();
	}

	TestGame::TestGame() :
		m_mainSpace(100),
		m_testTextBuffer("Testing this thing out")
	{
	}

	TestGame::~TestGame()
	{
	}
}

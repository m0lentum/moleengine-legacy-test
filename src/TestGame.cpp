#include "TestGame.hpp"
#include <iostream>

namespace tg
{
	void TestGame::begin()
	{
		m_title = "MoleEngine test game";
		createWindow(800, 600);
		m_fixedUpdateInterval = sf::seconds(1.0f / 120.0f); //120fps

		Game::begin();
	}

	void TestGame::continuousUpdate(sf::Time timeElapsed)
	{
		obj.continuousUpdate(timeElapsed);
	}

	void TestGame::fixedUpdate()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) m_view.zoom(0.95f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) m_view.move(2.0f, 0.5f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) m_view.move(-2.0f, -0.5f);

		obj.rotate(2);
	}

	void TestGame::draw()
	{
		m_mainWindow.clear(sf::Color::Cyan);
		m_mainWindow.setView(m_view);
		m_mainWindow.draw(obj);
		m_mainWindow.display();
	}

	TestGame::TestGame() :
		obj(new me::AnimatedSprite(&mainTexture, sf::Vector2i(), sf::Vector2i(100, 100), 5, sf::milliseconds(200)))
	{
		mainTexture.loadFromFile("assets/Sprite-0001.png");
		obj.setOrigin(50, 50);
		obj.setPosition(200, 300);
	}
}
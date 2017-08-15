#include "TestGame.hpp"

namespace tg
{
	void TestGame::begin()
	{
		m_title = "MoleEngine test game";
		createWindow(800, 600);
		//m_mainWindow.setFramerateLimit(60);

		Game::begin();
	}

	void TestGame::update(sf::Time timeElapsed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) m_view.zoom(0.95f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) m_view.move(2.0f, 0.5f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) m_view.move(-2.0f, -0.5f);

		anim.update(timeElapsed);
		anim.rotate(2);
	}

	void TestGame::draw()
	{
		m_mainWindow.clear(sf::Color::Cyan);
		m_mainWindow.setView(m_view);
		m_mainWindow.draw(anim);
		m_mainWindow.display();
	}

	TestGame::TestGame() :
		anim(&mainTexture, sf::Vector2i(), sf::Vector2i(100, 100), 5, sf::milliseconds(200))
	{
		mainTexture.loadFromFile("assets/Sprite-0001.png");
		anim.setOrigin(50, 50);
		anim.setPosition(200, 300);
	}
}
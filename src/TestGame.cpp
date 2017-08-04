#include <TestGame.hpp>

namespace tg
{
	void TestGame::begin()
	{
		title = "MoleEngine test game";
		createWindow(800, 600);
		mainWindow.setFramerateLimit(60);

		Game::begin();
	}

	void TestGame::update()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) view.zoom(0.95f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) view.move(2.0f, 0.5f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) view.move(-2.0f, -0.5f);

		objAnim.update();
		objAnim.rotate(2);
	}

	void TestGame::draw()
	{
		mainWindow.clear(sf::Color::Cyan);
		mainWindow.setView(view);
		mainWindow.draw(objAnim);
		mainWindow.draw(objStatic);
		mainWindow.display();
	}

	TestGame::TestGame() :
		objAnim(me::AnimatedSprite(mainTexture, sf::Vector2i(), sf::Vector2i(100, 100), 5, 10)),
		objStatic(new sf::CircleShape(100.0f))
	{
		mainTexture.loadFromFile("assets/Sprite-0001.png");
		objAnim.setOrigin(50, 50);
		objAnim.setPosition(200, 300);
		objStatic.setOrigin(50, 50);
		objStatic.setPosition(400, 300);
	}
}
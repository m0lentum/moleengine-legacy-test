#include "ObjTest.hpp"
#include <ME/Graphics/AnimatedSprite.hpp>

namespace tg
{
	void ObjTest::fixedUpdate()
	{
		rotate(2);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) move(2.0f, 0.0f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) move(-2.0f, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) move(0.0f, -2.0f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) move(0.0f, 2.0f);
	}


	ObjTest::ObjTest(me::AssetManager *assetManager)
	{
		setGraphic(std::make_shared<me::AnimatedSprite>(assetManager->getTexture("Sprite0001"), sf::Vector2i(0, 0),
			sf::Vector2i(100, 100), 5, sf::milliseconds(200)));
		setOrigin(50, 50);
		setPosition(300, 300);
	}

	ObjTest::~ObjTest()
	{
	}
}
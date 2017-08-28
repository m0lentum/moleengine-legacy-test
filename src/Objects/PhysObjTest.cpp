#include "PhysObjTest.hpp"
#include <ME/Graphics/AnimatedSprite.hpp>

namespace tg
{
	void PhysObjTest::fixedUpdate()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) destroy();
	}


	PhysObjTest::PhysObjTest(me::AssetManager *assetManager)
	{
		setGraphic(std::make_shared<me::AnimatedSprite>(assetManager->getTexture("Sprite0001"), sf::Vector2i(0, 0),
			sf::Vector2i(100, 100), 5, sf::milliseconds(200)));
		setOrigin(50, 50);
		setScale(2.5f, 2.5f);
		setPosition(600, 400);
	}

	PhysObjTest::~PhysObjTest()
	{
	}
}
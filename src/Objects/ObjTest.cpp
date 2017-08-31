#include "ObjTest.hpp"
#include <ME/Graphics/AnimatedSprite.hpp>

namespace tg
{
	void ObjTest::fixedUpdate()
	{
		rotate(2);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) destroy();
	}


	ObjTest::ObjTest(me::AssetManager *assetManager)
	{
		setGraphic(std::make_shared<me::AnimatedSprite>(assetManager->getTexture("Sprite0001"), sf::Vector2i(0, 0),
			sf::Vector2i(100, 100), 5, sf::milliseconds(200)));
		setOrigin(50, 50);
		setPosition(100, 500);
	}

	ObjTest::~ObjTest()
	{
	}
}
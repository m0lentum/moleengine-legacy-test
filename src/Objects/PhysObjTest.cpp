#include "PhysObjTest.hpp"
#include <ME/Graphics/AnimatedSprite.hpp>
#include <ME/Physics/ColliderRect.hpp>

namespace tg
{
	void PhysObjTest::fixedUpdate()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) rotate(-1);
	}


	PhysObjTest::PhysObjTest(float radius) :
		me::PhysicsObject(new me::ColliderRect(60, 130))
	{
		setGraphicFromCollider();
	}

	PhysObjTest::~PhysObjTest()
	{
	}
}
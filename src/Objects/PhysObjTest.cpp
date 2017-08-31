#include "PhysObjTest.hpp"
#include <ME/Graphics/AnimatedSprite.hpp>
#include <ME/Physics/ColliderCircle.hpp>

namespace tg
{
	void PhysObjTest::fixedUpdate()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) destroy();
	}


	PhysObjTest::PhysObjTest(float radius) :
		me::PhysicsObject(new me::ColliderCircle(radius))
	{
		setGraphicFromCollider();
	}

	PhysObjTest::~PhysObjTest()
	{
	}
}
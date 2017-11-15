#include "PhysObjTest.hpp"
#include <ME/Graphics/AnimatedSprite.hpp>
#include <ME/Physics/ColliderPolygon.hpp>

namespace tg
{
	void PhysObjTest::fixedUpdate()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) rotate(-1);
	}


	PhysObjTest::PhysObjTest(float radius) :
		me::PhysicsObject(new me::ColliderPolygon({ 10, -20, -20, 30, 70, 80, 100, 0 }))
	{
		setGraphicFromCollider();
	}

	PhysObjTest::~PhysObjTest()
	{
	}
}
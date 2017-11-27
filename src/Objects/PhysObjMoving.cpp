#include "PhysObjMoving.hpp"
#include <ME/Graphics/Graphic.hpp>
#include <ME/Physics/ColliderCircle.hpp>

namespace tg
{
	void PhysObjMoving::fixedUpdate()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) move(2.0f, 0.0f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) move(-2.0f, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) move(0.0f, -2.0f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) move(0.0f, 2.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) rotate(1);
	}


	PhysObjMoving::PhysObjMoving(float radius) :
		me::PhysicsObject(new me::ColliderCircle(50))
	{
		//rotate(60);
		setGraphicFromCollider(sf::Color::Black);
	}

	PhysObjMoving::~PhysObjMoving()
	{
	}
}
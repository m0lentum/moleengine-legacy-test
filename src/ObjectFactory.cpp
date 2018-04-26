#include "ObjectFactory.hpp"
#include <ME/Graphics/Graphic.hpp>
#include <ME/Physics/ColliderCircle.hpp>
#include <ME/Physics/RigidBody.hpp>
#include <ME/Input/MouseController.hpp>
#include <ME/Physics/ColliderCircle.hpp>
#include <ME/Physics/ColliderRect.hpp>
#include <ME/Physics/ColliderPolygon.hpp>
#include <ME/Utility/UpdateLoopComponent.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace tg
{
    me::GameObject* ObjectFactory::makePlayer(me::Space *space)
    {
        me::GameObject *obj = space->createObject();
        me::RigidBody *rb = obj->addComponent<me::RigidBody>();
		//rb->angularVelocity = 0.5f;
		rb->gravityMultiplier = 0;
		rb->isKinematic = true;
		me::ColliderRect *coll = obj->addComponent<me::ColliderRect>(80.0f, 40.0f);
		coll->linkRigidBody(rb);
        obj->addComponent<me::Graphic>(coll->toVertexArray(sf::Color::Black));

		obj->addComponent<me::FixedUpdateLoop>([rb]()
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) rb->angularVelocity = -0.02f;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) rb->angularVelocity = 0.02f;
			else rb->angularVelocity = 0;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) rb->velocity.x = 3.0f;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) rb->velocity.x = -3.0f;
			else rb->velocity.x = 0;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) rb->velocity.y = -3.0f;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) rb->velocity.y = 3.0f;
			else rb->velocity.y = 0;
		});

        return obj;
    }

    me::GameObject* ObjectFactory::makeBox(me::Space *space, float width, float height)
    {
        me::GameObject *obj = space->createObject();
        me::RigidBody *rb = obj->addComponent<me::RigidBody>();
		//rb->isStatic = true;
        me::ColliderRect *coll = obj->addComponent<me::ColliderRect>(width, height);
		coll->linkRigidBody(rb);
        obj->addComponent<me::Graphic>(coll->toVertexArray());

        return obj;
    }

	me::GameObject* ObjectFactory::makeBall(me::Space *space, float radius)
	{
		me::GameObject *obj = space->createObject();
		me::RigidBody *rb = obj->addComponent<me::RigidBody>();
		me::ColliderCircle *coll = obj->addComponent<me::ColliderCircle>(radius);
		coll->linkRigidBody(rb);
		obj->addComponent<me::Graphic>(coll->toVertexArray());

		return obj;
	}

    me::GameObject* ObjectFactory::makePolygon(me::Space *space, std::initializer_list<float> coords, sf::Color color)
    {
        me::GameObject *obj = space->createObject();
        me::RigidBody *rb = obj->addComponent<me::RigidBody>();
        me::ColliderPolygon *coll = obj->addComponent<me::ColliderPolygon>(coords);
		coll->linkRigidBody(rb);
        obj->addComponent<me::Graphic>(coll->toVertexArray(color));

        return obj;
    }

	void ObjectFactory::makeWalls(me::Space *space, float x, float y, float width, float height, float thickness)
	{
		me::GameObject *left = makeBox(space, thickness, height + 2 * thickness);
		left->setPosition(x - 0.5f * thickness, y + 0.5f * height);
		left->getComponent<me::RigidBody>()->isKinematic = true;
		me::GameObject *right = makeBox(space, thickness, height + 2 * thickness);
		right->setPosition(x + width + 0.5f * thickness, y + 0.5f * height);
		right->getComponent<me::RigidBody>()->isKinematic = true;
		me::GameObject *top = makeBox(space, width + 2 * thickness, thickness);
		top->setPosition(x + 0.5f * width, y - 0.5f * thickness);
		top->getComponent<me::RigidBody>()->isKinematic = true;
		me::GameObject *bottom = makeBox(space, width + 2 * thickness, thickness);
		bottom->setPosition(x + 0.5f * width, y + height + 0.5f * thickness);
		bottom->getComponent<me::RigidBody>()->isKinematic = true;
	}
}
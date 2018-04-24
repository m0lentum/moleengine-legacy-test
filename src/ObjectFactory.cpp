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
		me::ColliderRect *coll = obj->addComponent<me::ColliderRect>(80.0f, 40.0f);
		coll->linkRigidBody(rb);
        obj->addComponent<me::Graphic>(coll->toVertexArray(sf::Color::Black));

		obj->addComponent<me::FixedUpdateLoop>([rb]()
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) rb->angularVelocity = -0.5f;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) rb->angularVelocity = 0.5f;
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
		rb->isStatic = true;
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
}
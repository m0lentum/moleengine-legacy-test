#include "ObjectFactory.hpp"
#include <ME/Graphics/Graphic.hpp>
#include <ME/Physics/ColliderCircle.hpp>
#include <ME/Physics/RigidBody.hpp>
#include <ME/Input/MouseController.hpp>
#include <ME/Physics/ColliderCircle.hpp>
#include <ME/Physics/ColliderRect.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace tg
{
    me::GameObject* ObjectFactory::makePlayer(me::Space *space)
    {
        me::GameObject *obj = space->createObject();
        me::RigidBody *rb = obj->addComponent<me::RigidBody>();
        rb->isKinematic = true;
        me::ColliderCircle *coll = obj->addComponent<me::ColliderCircle>(50.0f);
        obj->addComponent<me::Graphic>(coll->toVertexArray(sf::Color::Green));
        me::MouseController *cont = obj->addComponent<me::MouseController>();
        cont->onMouseMoved = [obj](const sf::Event::MouseMoveEvent &evt)
        {
            obj->setPosition(evt.x, evt.y);
        };

        return obj;
    }

    me::GameObject* ObjectFactory::makeBox(me::Space *space, float width, float height)
    {
        me::GameObject *obj = space->createObject();
        me::RigidBody *rb = obj->addComponent<me::RigidBody>();
        me::ColliderRect *coll = obj->addComponent<me::ColliderRect>(width, height);
        obj->addComponent<me::Graphic>(coll->toVertexArray());

        return obj;
    }

	me::GameObject* ObjectFactory::makeBall(me::Space *space, float radius)
	{
		me::GameObject *obj = space->createObject();
		me::RigidBody *rb = obj->addComponent<me::RigidBody>();
		me::ColliderCircle *coll = obj->addComponent<me::ColliderCircle>(radius);
		obj->addComponent<me::Graphic>(coll->toVertexArray());

		return obj;
	}
}
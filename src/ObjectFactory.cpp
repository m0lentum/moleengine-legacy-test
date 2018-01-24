#include "ObjectFactory.hpp"
#include <ME/Graphics/Graphic.hpp>
#include <ME/Physics/ColliderCircle.hpp>
#include <ME/Physics/RigidBody.hpp>
#include <ME/Input/MouseController.hpp>
#include <ME/Physics/ColliderCircle.hpp>
#include <ME/Physics/ColliderRect.hpp>
#include <ME/Physics/ColliderPolygon.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace tg
{
    me::GameObject* ObjectFactory::makePlayer(me::Space *space)
    {
        me::GameObject *obj = space->createObject();
        me::RigidBody *rb = obj->addComponent<me::RigidBody>();
        rb->isKinematic = true;
		//rb->angularVelocity = 0.5f;
		me::ColliderPolygon *coll = obj->addComponent<me::ColliderPolygon>(std::initializer_list<float>({ 130.0f, 80.0f, 0, 50.0f, -50.0f, 0 }));
        obj->addComponent<me::Graphic>(coll->toVertexArray(sf::Color::Black));
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

    me::GameObject* ObjectFactory::makePolygon(me::Space *space, std::initializer_list<float> coords, sf::Color color)
    {
        me::GameObject *obj = space->createObject();
        me::RigidBody *rb = obj->addComponent<me::RigidBody>();
        me::ColliderPolygon *coll = obj->addComponent<me::ColliderPolygon>(coords);
        obj->addComponent<me::Graphic>(coll->toVertexArray(color));

        return obj;
    }
}
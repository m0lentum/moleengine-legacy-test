#ifndef OBJECT_FACTORY_HPP
#define OBJECT_FACTORY_HPP

#include <ME/GameObject.hpp>
#include <ME/Space.hpp>

namespace tg
{
    namespace ObjectFactory
    {
        me::GameObject* makePlayer(me::Space *space);
        me::GameObject* makeBox(me::Space *space, float width, float height);
		me::GameObject* makeBall(me::Space *space, float radius);
    };
}

#endif // OBJECT_FACTORY_HPP
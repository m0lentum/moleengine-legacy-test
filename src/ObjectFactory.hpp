#ifndef OBJECT_FACTORY_HPP
#define OBJECT_FACTORY_HPP

#include <ME/GameObject.hpp>
#include <ME/Space.hpp>

namespace tg
{
    class ObjectFactory
    {
    public:

        static me::GameObject* makePlayer(me::Space *space);

        static me::GameObject* makeBox(me::Space *space, float width, float height);
    };
}

#endif // OBJECT_FACTORY_HPP
#ifndef OBJECT_FACTORY_HPP
#define OBJECT_FACTORY_HPP

#include <ME/GameObject.hpp>
#include <ME/Space.hpp>
#include <initializer_list>
#include <SFML/Graphics/Color.hpp>

namespace tg
{
    namespace ObjectFactory
    {
        me::GameObject* makePlayer(me::Space *space);
        me::GameObject* makeBox(me::Space *space, float width, float height);
		me::GameObject* makeBall(me::Space *space, float radius);
        me::GameObject* makePolygon(me::Space *space, std::initializer_list<float> coords, sf::Color color);
		void makeWalls(me::Space *space, float left, float top, float width, float height, float thickness);
    };
}

#endif // OBJECT_FACTORY_HPP
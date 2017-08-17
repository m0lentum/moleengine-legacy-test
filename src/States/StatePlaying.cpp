#include "StatePlaying.hpp"
#include <ME/AnimatedSprite.hpp>
#include <SFML/System/Vector2.hpp>
//#include <iostream>

namespace tg
{
	void StatePlaying::continuousUpdate(const sf::Time &timeElapsed)
	{
		m_obj.continuousUpdate(timeElapsed);
	}

	void StatePlaying::fixedUpdate()
	{
		m_obj.rotate(2);
	}

	void StatePlaying::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_obj, states);
	}


	StatePlaying::StatePlaying() :
		m_obj(new me::AnimatedSprite(&m_mainTexture, sf::Vector2i(), sf::Vector2i(100, 100), 5, sf::milliseconds(200)))
	{
		m_mainTexture.loadFromFile("assets/Sprite-0001.png");
		m_obj.setOrigin(50, 50);
		m_obj.setPosition(200, 300);
	}

	StatePlaying::~StatePlaying()
	{
	}
}
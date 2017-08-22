#include "StatePaused.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <ME/Graphics/AnimatedSprite.hpp>
#include "StatePlaying.hpp"
//#include <iostream>

namespace tg
{
	void StatePaused::loadSpace(std::shared_ptr<me::Space> space)
	{
		m_space = space;
	}

	void StatePaused::continuousUpdate(const sf::Time &timeElapsed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			m_stateManager->transitionTo("PLAYING");
		}
	}

	void StatePaused::fixedUpdate()
	{

	}

	void StatePaused::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		m_space->draw(target, states);
	}

	StatePaused::StatePaused()
	{
	}

	StatePaused::~StatePaused()
	{
	}
}

#include "StatePaused.hpp"
#include <ME/Input/Keyboard.hpp>
#include <ME/Graphics/AnimatedSprite.hpp>
#include "StatePlaying.hpp"
//#include <iostream>

namespace tg
{
	void StatePaused::loadSpace(me::Space *space)
	{
		m_space = space;
	}

	void StatePaused::continuousUpdate(const sf::Time &timeElapsed)
	{

	}

	void StatePaused::fixedUpdate()
	{
		if (me::Keyboard::isKeyJustPressed(me::Keyboard::Space))
			m_stateManager->transitionTo(m_statePlaying);
		if (me::Keyboard::wasKeyPressed(me::Keyboard::Return))
			m_space->fixedUpdate();
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

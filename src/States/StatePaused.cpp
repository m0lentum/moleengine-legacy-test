#include "StatePaused.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <ME/Graphics/AnimatedSprite.hpp>

namespace tg
{
	void StatePaused::load()
	{
		m_obj = me::GameObject(new me::AnimatedSprite(m_assetManager->getTexture("Sprite0001"), sf::Vector2i(), sf::Vector2i(100, 100), 5, sf::milliseconds(200)));
		m_obj.setOrigin(50, 50);
		m_obj.setPosition(200, 300);
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
		target.draw(m_obj, states);
	}

	StatePaused::StatePaused()
	{

	}

	StatePaused::~StatePaused()
	{

	}
}

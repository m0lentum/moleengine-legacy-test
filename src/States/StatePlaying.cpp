#include "StatePlaying.hpp"
#include <ME/Graphics/AnimatedSprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

namespace tg
{
	void StatePlaying::load()
	{
		m_assetManager->loadTexture("assets/Sprite-0001.png", "Sprite0001");

		m_obj = me::GameObject(new me::AnimatedSprite(m_assetManager->getTexture("Sprite0001"), sf::Vector2i(), sf::Vector2i(100, 100), 5, sf::milliseconds(200)));
		m_obj.setOrigin(50, 50);
		m_obj.setPosition(200, 300);
	}

	void StatePlaying::onTransitionIn()
	{
		std::cout << "Transition into StatePlaying" << std::endl;
	}

	void StatePlaying::onTransitionOut()
	{
		std::cout << "Transition out of StatePlaying" << std::endl;
	}

	void StatePlaying::continuousUpdate(const sf::Time &timeElapsed)
	{
		m_obj.continuousUpdate(timeElapsed);
	}

	void StatePlaying::fixedUpdate()
	{
		m_obj.rotate(2);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) m_stateManager->transitionTo("PAUSED");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) m_view.move(2.0f, 0.0f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) m_view.move(-2.0f, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) m_view.move(0.0f, -2.0f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) m_view.move(0.0f, 2.0f);
	}

	void StatePlaying::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.setView(m_view);
		target.draw(m_obj, states);
	}


	StatePlaying::StatePlaying()
	{
	}

	StatePlaying::~StatePlaying()
	{
	}
}

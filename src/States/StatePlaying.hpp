#ifndef STATE_PLAYING_HPP
#define STATE_PLAYING_HPP

#include <ME/GameStateManager.hpp>
#include <ME/GameObject.hpp>

namespace tg
{
	class StatePlaying : public me::GameState
	{
	private:
		me::GameObject m_obj;
		sf::Texture m_mainTexture;

	public:
		virtual void continuousUpdate(const sf::Time &timeElapsed);
		virtual void fixedUpdate();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		StatePlaying();
		~StatePlaying();
	};
}


#endif //STATE_PLAYING_HPP
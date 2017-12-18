#ifndef STATE_PLAYING_HPP
#define STATE_PLAYING_HPP

#include <ME/GameStateManager.hpp>
#include <ME/Space.hpp>

namespace tg
{
	class StatePaused;

	class StatePlaying : public me::IGameState
	{
	private:
		me::Space *m_space;
		sf::View m_view;

	public:
		void loadSpace(me::Space *space);

		virtual void onTransitionIn();
		virtual void onTransitionOut();

		// update loops
		virtual void continuousUpdate(const sf::Time &timeElapsed);
		virtual void fixedUpdate();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		virtual void handleWindowEvent(const sf::Event &evt);

		StatePlaying();
		~StatePlaying();
	};
}


#endif //STATE_PLAYING_HPP

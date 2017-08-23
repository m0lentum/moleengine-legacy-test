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
		std::shared_ptr<me::Space> m_space;
		sf::View m_view;
		StatePaused *m_statePaused;

	public:
		void loadSpace(std::shared_ptr<me::Space> space);
		inline void registerStatePaused(StatePaused *state) { m_statePaused = state; }

		virtual void onTransitionIn();
		virtual void onTransitionOut();

		// IComponent update loops
		virtual void continuousUpdate(const sf::Time &timeElapsed);
		virtual void fixedUpdate();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		StatePlaying();
		~StatePlaying();
	};
}


#endif //STATE_PLAYING_HPP

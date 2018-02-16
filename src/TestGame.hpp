#ifndef TEST_GAME_HPP
#define TEST_GAME_HPP

#include <ME/Game.hpp>
#include "States/AllStates.hpp"
#include <ME/GameObject.hpp>

namespace tg
{
	class TestGame : public me::Game
	{
	private:

		me::Space m_mainSpace;
		char m_testTextBuffer[255];

	public:
		virtual void init();

		TestGame();
		~TestGame();

	private:
		virtual void continuousUpdate(sf::Time timeElapsed);
		virtual void fixedUpdate();
		virtual void draw();

	};
}
#endif //TEST_GAME_HPP
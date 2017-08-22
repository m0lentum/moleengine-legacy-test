#ifndef TEST_GAME_HPP
#define TEST_GAME_HPP

#include <ME/Game.hpp>
#include <ME/GameObject.hpp>
#include <ME/Graphics/AnimatedSprite.hpp>

namespace tg
{
	class TestGame : public me::Game
	{
	public:
		virtual void begin();

		TestGame();
		~TestGame();

	private:
		virtual void continuousUpdate(sf::Time timeElapsed);
		virtual void fixedUpdate();
		virtual void draw();

	};
}
#endif //TEST_GAME_HPP
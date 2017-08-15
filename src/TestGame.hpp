#ifndef TEST_GAME_HPP
#define TEST_GAME_HPP

#include <ME/Game.hpp>
#include <ME/AnimatedSprite.hpp>

namespace tg
{
	class TestGame : public me::Game
	{
	public:

		void begin();

		TestGame();

	private:

		me::AnimatedSprite anim;
		sf::Texture mainTexture;

		virtual void update(sf::Time timeElapsed);
		virtual void draw();

	};
}
#endif //TEST_GAME_HPP
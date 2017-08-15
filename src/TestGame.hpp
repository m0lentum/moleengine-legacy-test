#ifndef TEST_GAME_HPP
#define TEST_GAME_HPP

#include <ME/Game.hpp>
#include <ME/GameObject.hpp>
#include <ME/AnimatedSprite.hpp>

namespace tg
{
	class TestGame : public me::Game
	{
	public:

		void begin();

		TestGame();

	private:

		me::GameObject obj;
		sf::Texture mainTexture;

		virtual void continuousUpdate(sf::Time timeElapsed);
		virtual void fixedUpdate();
		virtual void draw();

	};
}
#endif //TEST_GAME_HPP
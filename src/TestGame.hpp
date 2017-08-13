#ifndef TEST_GAME_HPP
#define TEST_GAME_HPP

#include <ME/Game.hpp>
#include <ME/AnimatedSprite.hpp>
#include <ME/GameObject.hpp>

namespace tg
{
	class TestGame : public me::Game
	{
	public:

		void begin();

		TestGame();

	private:

		me::GameObjectAnimated objAnim;
		me::GameObjectStatic objStatic;
		sf::Texture mainTexture;

		void update();
		void draw();

	};
}
#endif //TEST_GAME_HPP
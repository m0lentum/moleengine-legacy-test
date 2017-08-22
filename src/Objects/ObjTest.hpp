#ifndef OBJ_TEST_HPP
#define OBJ_TEST_HPP

#include <ME/GameObject.hpp>
#include <ME/AssetManager.hpp>

namespace tg
{
	class ObjTest : public me::GameObject
	{
	public:
		virtual void fixedUpdate();

		ObjTest(me::AssetManager *assetManager);
		virtual ~ObjTest();
	};
}



#endif //OBJ_TEST_HPP
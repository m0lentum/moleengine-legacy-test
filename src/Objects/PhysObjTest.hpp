#ifndef PHYS_OBJ_TEST_HPP
#define PHYS_OBJ_TEST_HPP

#include <ME/Physics/PhysicsObject.hpp>
#include <ME/AssetManager.hpp>

namespace tg
{
	class PhysObjTest : public me::PhysicsObject
	{
	public:
		virtual void fixedUpdate();

		PhysObjTest(me::AssetManager *assetManager);
		virtual ~PhysObjTest();
	};
}



#endif // PHYS_OBJ_TEST_HPP
#ifndef PHYS_OBJ_MOVING_HPP
#define PHYS_OBJ_MOVING_HPP

#include <ME/Physics/PhysicsObject.hpp>

namespace tg
{
	class PhysObjMoving : public me::PhysicsObject
	{
	public:
		virtual void fixedUpdate();

		PhysObjMoving(float radius);
		virtual ~PhysObjMoving();
	};
}



#endif // PHYS_OBJ_MOVING_HPP
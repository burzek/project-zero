#ifndef COLLISION_H
#define COLLISION_H

#include "sprites/sprite.h"

class CollisionDetector {
	private:
		CollisionDetector();
		virtual ~CollisionDetector();
	public:
		static bool collide(const Sprite* spriteA, const Sprite* spriteB);
};

#endif /* COLLISION_H */

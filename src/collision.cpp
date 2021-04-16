#include "collision.h"

CollisionDetector::CollisionDetector()
{
}

CollisionDetector::~CollisionDetector()
{
}

bool CollisionDetector::collide(const Sprite* spriteA, const Sprite* spriteB) 
{
	//basic box collision
	int aLeft = spriteA->GetSpriteData()->sprite_position.x;
	int aRight = aLeft + spriteA->GetSpriteData()->sprite_size.w;
	int aTop = spriteA->GetSpriteData()->sprite_position.y;
	int aBottom = aTop + spriteA->GetSpriteData()->sprite_size.h;
	
	int bLeft = spriteB->GetSpriteData()->sprite_position.x;
	int bRight = bLeft + spriteB->GetSpriteData()->sprite_size.w;
	int bTop = spriteB->GetSpriteData()->sprite_position.y;
	int bBottom = bTop + spriteB->GetSpriteData()->sprite_size.h;

	return aRight > bLeft && aLeft < bRight &&
       aTop < bBottom && aBottom > bTop;


}

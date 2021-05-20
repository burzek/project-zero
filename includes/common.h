#ifndef COMMON_H
#define COMMON_H

#include <string>

enum SpriteId
{
	PLAYER,
	CROW,
	PLASMA_BULLET,
	NEW_GUN_ICON
};

enum GunId {
    ELECTRO_GUN,
    PLASMA_CANNON,
    NUCLEAR_BLAST,
    GUIDED_ROCKET
};

enum LevelId {
  INTRO
};

#define LEVEL_PATH "resources/levels"



#endif /*COMMON_H*/


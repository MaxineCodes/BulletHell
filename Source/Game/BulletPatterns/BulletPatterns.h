#pragma once

#include "../GameGlobals.h"
#include "../Datatypes/Vector2.h"



namespace BulletPatterns
{
	static void instantCirclePattern(Vector2 position, const int bulletCount);
	static void instantShootTargetPattern(Vector2 position, Vector2 targetPosition, const int bulletCount);
}
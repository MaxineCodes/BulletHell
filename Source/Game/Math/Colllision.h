#pragma once

#include "../Datatypes/Vector2.h"
#include "GameMath.h"


// Check if you have collided with entity of a certain type
bool hasCollided(const char* collidedEntityType, Vector2 position, float collisionRange);

// Bools for checking which edge is touched
// Used for movement checks of the player mostly
static bool IsTouchingLeft(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f)
{
	if (position.x <= 0.0f + padding) 
		return true;

	return false;
}
static bool IsTouchingRight(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f)
{
	if (position.x >= float(WINDOWWIDTH) - padding) 
		return true;

	return false;
}
static bool IsTouchingUp(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f)
{
	if (position.y <= 0.0f + padding) 
		return true;

	return false;
}
static bool IsTouchingDown(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f)
{
	if (position.y >= float(WINDOWHEIGHT) - padding) 
		return true;

	return false;
}
#pragma once

#include "../Datatypes/Vector2.h"



// Bools for checking which edge is touched
// Used for movement checks
static bool IsTouchingLeft(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f)
{
	if (position.x <= 0.0f + padding) return true;
	return false;
}
static bool IsTouchingRight(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f)
{
	if (position.x >= float(WINDOWWIDTH) - padding) return true;
	return false;
}
static bool IsTouchingUp(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f)
{
	if (position.y <= 0.0f + padding) return true;
	return false;
}
static bool IsTouchingDown(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f)
{
	if (position.y >= float(WINDOWHEIGHT) - padding) return true;
	return false;
}
#pragma once

#include <cmath>


// Constant numbers
const float pi = 3.141592f;

struct Vector2 
{
	float x;
	float y;
};

// Normalize vector
static Vector2 Normalize(Vector2 vector)
{
	// If vector is not 0 on either axis
	if (vector.x != 0.0f || vector.y != 0.0f)
	{
		// Calculate vector length aka magnitude
		float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
		// normalize vector
		vector.x /= magnitude;
		vector.y /= magnitude;
		// Return new normalized vector
		return Vector2(vector);
	}
	// Return inputted vector if no normalization needs to happen
	return vector;
};

// Whether object is in the game area
static bool IsInGameArea(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f)
{
	if (position.x <= 0.0f + padding) return false;
	if (position.x >= float(WINDOWWIDTH) - padding) return false;
	if (position.y <= 0.0f + padding) return false;
	if (position.y >= float(WINDOWHEIGHT) - padding) return false;
	return true;
}

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
#include "GameMath.h"

const int* getTextureDimensions(sf::Texture texture)
{
	static int dimensions[2];
	dimensions[0] = texture.getSize().x;
	dimensions[1] = texture.getSize().y;
	return dimensions;
}

const float getDistance(Vector2 a, Vector2 b)
{
	// Return the distance between 2 vectors
	return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2) * 1.0);
}

bool IsInGameArea(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding)
{
	if (position.x <= 0.0f + padding) 
		return false;

	if (position.x >= float(WINDOWWIDTH) - padding) 
		return false;

	if (position.y <= 0.0f + padding) 
		return false;

	if (position.y >= float(WINDOWHEIGHT) - padding) 
		return false;

	return true;
}

Vector2 Normalize(Vector2 vector)
{
	if (vector.x != 0.0f || vector.y != 0.0f)
	{
		float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

		vector.x /= magnitude;
		vector.y /= magnitude;

		return Vector2(vector);
	}
	return vector;
}

float getMagnitude(Vector2& vector)
{
	return std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

Vector2 moveTowards(Vector2& current, Vector2& target, float speed)
{
	float ax = target.x - target.x;
	float ay = target.y - target.y;
	Vector2 a(ax, ay);
	float magnitude = getMagnitude(a);

	if (magnitude <= speed || magnitude == 0.0f)
	{
		return target;
	}

	float x = current.x + a.x / magnitude * speed;
	float y = current.y + a.y / magnitude * speed;
	return Vector2(x, y);
}
;
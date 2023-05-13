#include "GameMath.h"

const int* getTextureDimensions(sf::Texture texture)
{
	static int dimensions[2];
	dimensions[0] = texture.getSize().x;
	dimensions[1] = texture.getSize().y;
	return dimensions;
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
};
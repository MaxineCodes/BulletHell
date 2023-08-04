#include "GameMath.h"
#include "../GameGlobals.h"


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


bool isInGameArea(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding)
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


Vector2 normalize(Vector2 vector)
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


Vector2 applicationCoordinatesFromPercent(const int percentageX, const int percentageY)
{
	const float multiplierX = GAME_SETTINGS.WINDOWWIDTH  / 100;
	const float multiplierY = GAME_SETTINGS.WINDOWHEIGHT / 100;

	const float pixelCoordinateX = float(multiplierX * percentageX);
	const float pixelCoordinateY = float(multiplierY * percentageY);

	return Vector2(pixelCoordinateX, pixelCoordinateY);
}

Vector2 gameCoordinatesFromPercent(const int percentageX, const int percentageY)
{
	const float multiplierX = GAME_SETTINGS.GAME_WINDOWWIDTH  / 100;
	const float multiplierY = GAME_SETTINGS.GAME_WINDOWHEIGHT / 100;

	const float pixelCoordinateX = float(multiplierX * percentageX);
	const float pixelCoordinateY = float(multiplierY * percentageY);

	return Vector2(pixelCoordinateX, pixelCoordinateY);
}

Vector2 guiCoordinatesFromPercent(const int percentageX, const int percentageY)
{
	const float multiplierX = GAME_SETTINGS.WINDOWWIDTH - GAME_SETTINGS.GAME_WINDOWWIDTH / 100;
	const float multiplierY = GAME_SETTINGS.WINDOWHEIGHT / 100;

	const float pixelCoordinateX = float(multiplierX * percentageX) + float(GAME_SETTINGS.GAME_WINDOWWIDTH);
	const float pixelCoordinateY = float(multiplierY * percentageY);

	return Vector2(pixelCoordinateX, pixelCoordinateY);
}

float vector2CrossProduct(Vector2& vectorA, Vector2& vectorB)
{
	float crossProduct = vectorA.x * vectorB.y - vectorB.x * vectorA.y;
	return crossProduct;
}

const float radiantsToDegrees(const float radiants)
{
	return 0.0f;
}

const float getRotationByDirectionVector(Vector2& directionVector)
{
	Vector2 normalizedVector = normalize(directionVector);






	return 0.0f;
}

const Vector2 rotateVector(const Vector2& vector, const float rotation)
{
	const float x = vector.x * cos(rotation) - vector.y * sin(rotation);
	const float y = vector.x * sin(rotation) - vector.y * cos(rotation);
	return Vector2(x,y);
}

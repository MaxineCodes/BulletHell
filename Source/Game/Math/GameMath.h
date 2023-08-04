#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

#include "../Datatypes/Vector2.h"


// Constant numbers
const float pi = 3.141592f;

extern const int* getTextureDimensions(sf::Texture texture);
extern const float getDistance(Vector2 a, Vector2 b);
extern bool isInGameArea(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f);
extern Vector2 normalize(Vector2 vector);
extern float getMagnitude(Vector2& vector);
extern Vector2 moveTowards(Vector2& current, Vector2& target, float speed);
extern Vector2 applicationCoordinatesFromPercent(const int percentageX, const int percentageY);
extern Vector2 gameCoordinatesFromPercent(const int percentageX, const int percentageY);
extern Vector2 guiCoordinatesFromPercent(const int percentageX, const int percentageY);
extern float vector2CrossProduct(Vector2& vectorA, Vector2& vectorB);
extern const float radiantsToDegrees(const float radiants);
extern const float getRotationByDirectionVector(Vector2& directionVector);
extern const Vector2 rotateVector(const Vector2& vector, const float rotation);
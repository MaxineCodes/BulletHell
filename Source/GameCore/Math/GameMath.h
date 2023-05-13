#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

#include "../Datatypes/Vector2.h"


// Constant numbers
const float pi = 3.141592f;

extern const int* getTextureDimensions(sf::Texture texture);
extern bool IsInGameArea(Vector2 position, int WINDOWWIDTH, int WINDOWHEIGHT, float padding = 0.0f);
extern Vector2 Normalize(Vector2 vector);
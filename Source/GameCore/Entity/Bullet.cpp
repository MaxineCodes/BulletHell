#include "Bullet.h"

#include "../Math/Colllision.h"
#include "../Math/GameMath.h"
#include "../GameGlobals.h"


// Constructor
Bullet::Bullet(Vector2 startPosition, Vector2 startDirection, float speed, float size, const char* textureName)
{
	std::cout << "Bullet Created" << std::endl;

	m_direction = startDirection;
	m_speed = speed;
	m_size = size;

	m_bulletTexture = GAME_RESOURCEMANAGER->getTexture(textureName);
	m_bulletSprite.setTexture(m_bulletTexture);

	const float textureSize = float(getTextureDimensions(m_bulletTexture)[0]);
	m_bulletSprite.setOrigin(textureSize / 2, textureSize / 2 + textureSize / 6);
	m_bulletSprite.setScale(m_size, m_size);
	m_bulletSprite.setPosition(startPosition.x, startPosition.y);
}

void Bullet::update(float deltaTime)
{
	// Store sprite position
	m_position.x = m_bulletSprite.getPosition().x;
	m_position.y = m_bulletSprite.getPosition().y;
	
	// Normalize direction vector
	m_direction = Normalize(m_direction);
	
	// Move bullet to direction
	m_bulletSprite.move((m_direction.x * m_speed) * deltaTime, (m_direction.y * m_speed) * deltaTime);
}

sf::Sprite Bullet::getSprite()
{
	return m_bulletSprite;
}

std::string Bullet::getType()
{
	return m_type;
}

const int Bullet::getRenderLayer()
{
	return renderLayer;
}

Vector2 Bullet::getPosition()
{
	return Vector2(m_bulletSprite.getPosition().x, m_bulletSprite.getPosition().y);
}

bool Bullet::shouldBeDestroyed()
{
	//extern int GAME_WINDOWWIDTH;
	//extern int GAME_WINDOWHEIGHT;

	if (!IsInGameArea(m_position, GAME_WINDOWWIDTH, GAME_WINDOWHEIGHT))
		return true;

	return false;
}
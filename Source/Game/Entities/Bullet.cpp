#include "Bullet.h"

#include "../Math/Colllision.h"
#include "../GameGlobals.h"
#include "../Math/GameMath.h"


// Constructor
Bullet::Bullet(Vector2 startPosition, Vector2 startDirection, float speed, float size, const char* textureName)
{
	//std::cout << "Bullet Created" << std::endl;

	m_direction = startDirection;
	m_speed = speed;
	m_size = size;
	const int textureSize = GAME_RESOURCEMANAGER->getTextureSize(m_bulletTexture);

	m_bulletTexture = GAME_RESOURCEMANAGER->getTexture(textureName);
	m_bulletSprite.setTexture(m_bulletTexture);

	m_bulletSprite.setOrigin(float(textureSize / 2), float(textureSize / 2));
	m_bulletSprite.setScale(m_size * GAME_SCALE, m_size * GAME_SCALE);
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

void Bullet::lateUpdate(float deltaTime)
{

}

void Bullet::draw()
{
	GAME_RENDERER->draw(m_bulletSprite);
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
	return m_renderLayer;
}

Vector2 Bullet::getPosition()
{
	// Get the sprite position and add 16 (half the width of the sprite) multiplied by the sprite size multiplier.
	// This will get the "center" position of the sprite.
	//return Vector2(m_bulletSprite.getPosition().x + (float(m_textureSize)/2 * m_size), m_bulletSprite.getPosition().y + (float(m_textureSize)/2 * m_size));

	return Vector2(m_bulletSprite.getPosition().x, m_bulletSprite.getPosition().y);
}

float Bullet::getCollisionRange()
{
	return m_collisionRange;
}

bool Bullet::shouldBeDestroyed()
{
	//extern int GAME_WINDOWWIDTH;
	//extern int GAME_WINDOWHEIGHT;

	if (!IsInGameArea(m_position, GAME_SETTINGS.GAME_WINDOWWIDTH, GAME_SETTINGS.GAME_WINDOWHEIGHT))
		return true;

	return false;
}
#include "Bullet.h"

// Constructor
Bullet::Bullet(Vector2 startPosition, Vector2 startDirection, float speed, float size, ResourceManager* resourceManager, const char* textureName)
{
	std::cout << "Bullet Created" << std::endl;

	resourceManager_ptr = resourceManager;
	m_direction = startDirection;
	m_speed = speed;
	m_size = size;

	m_bulletTexture = resourceManager_ptr->getTexture(textureName);
	m_bulletSprite.setTexture(m_bulletTexture);

	m_bulletSprite.setOrigin(32 / 2, 32 / 2 + 32 / 6);
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
	Vector2 blep(m_bulletSprite.getPosition().x, m_bulletSprite.getPosition().y);
	return blep;
}

bool Bullet::shouldBeDestroyed()
{
	if (m_position.y < -100.0f)
		return true;

	return false;
}
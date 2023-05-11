#include "Bullet.h"

// Constructor
Bullet::Bullet(Vector2 startPosition, Vector2 startDirection, float speed, float size, sf::Texture& texture)
{
	std::cout << "Bullet::Bullet" << std::endl;

	//m_bulletTexture = texture;
	//m_bulletSprite.setTexture(texture);
	m_bulletSprite.setPosition(startPosition.x, startPosition.y);
	m_direction = startDirection;
	m_speed = speed;
	m_size = size;

	init();
}

void Bullet::init()
{
	m_bulletSprite.setOrigin(32 / 2, 32 / 2 + 32 / 6);
	m_bulletSprite.setScale(m_size, m_size);

	loadResources();
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

Vector2 Bullet::getPosition()
{
	Vector2 blep(m_bulletSprite.getPosition().x, m_bulletSprite.getPosition().y);
	return blep;
}

void Bullet::Delete()
{
	std::cout << "Bullet::Delete()" << std::endl;
}

void Bullet::loadResources()
{
	if (!m_bulletTexture.loadFromFile("Res/BulletPointBlue.png"))
	{
		std::cout << "Texture not found" << std::endl;
	}
	m_bulletSprite.setTexture(m_bulletTexture);
}
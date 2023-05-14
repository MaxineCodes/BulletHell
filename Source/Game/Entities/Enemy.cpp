#include "Enemy.h"

Enemy::Enemy(Vector2 position)
{
	m_position = position;
}

void Enemy::update(float deltaTime)
{

}

void Enemy::lateUpdate(float deltaTime)
{

}

bool Enemy::shouldBeDestroyed()
{
	if (m_health <= 1)
		return true;

	return false;
}

sf::Sprite Enemy::getSprite()
{
	return m_sprite;
}

std::string Enemy::getType()
{
	return m_type;
}

const int Enemy::getRenderLayer()
{
	return m_renderLayer;
}

Vector2 Enemy::getPosition()
{
	return m_position;
}

float Enemy::getCollisionRange()
{
	return m_collisionRange;
}

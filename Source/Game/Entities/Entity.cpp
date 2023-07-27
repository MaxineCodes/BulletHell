#include "Entity.h"

void Entity::update(float deltaTime)
{
	std::cout << "Entity::update()" << std::endl;
}

void Entity::lateUpdate(float deltaTime)
{
	std::cout << "Entity::lateUpdate()" << std::endl;
}

void Entity::draw()
{
	//std::cout << "Entity::draw()" << std::endl;
}

sf::Sprite Entity::getSprite()
{
	std::cout << "Entity::getSprite()" << std::endl;
	return entitySprite;
}

std::string Entity::getType()
{
	return m_type;
}

const int Entity::getRenderLayer()
{
	return m_renderLayer;
}

Vector2 Entity::getPosition()
{
	return m_position;
}

float Entity::getCollisionRange()
{
	return m_collisionRange;
}

bool Entity::shouldBeDestroyed()
{
	return false;
}

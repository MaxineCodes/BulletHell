#include "Entity.h"


void Entity::init()
{
	std::cout << "Entity::Init()" << std::endl;
}

void Entity::loadResources()
{
	std::cout << "Entity::loadResources()" << std::endl;
}

void Entity::update(float deltaTime)
{
	std::cout << "Entity::Update()" << std::endl;
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
	return renderLayer;
}

Vector2 Entity::getPosition()
{
	return m_position;
}

void Entity::Delete() 
{
	std::cout << "Entity::Delete()" << std::endl;
}

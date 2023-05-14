/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	Enemy.h
//
//	Description:
//	 Base enemy class.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Entity.h"


class Enemy : public Entity
{
private:
	const int m_renderLayer = 6;
	std::string m_type = "Enemy";
	const float m_size = 2.5f;
	float m_collisionRange = 3;

	int m_health = 1000;

	Vector2 m_position = Vector2(0.0f, 0.0f);
	Vector2 m_direction = Vector2(0.0f, 0.0f);

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	sf::Clock clock;
	sf::Time elapsedTime;
	sf::Time frameTime;

public:
	Enemy() {}
	Enemy(Vector2 position);
	~Enemy() {}

	virtual void update(float deltaTime);
	virtual void lateUpdate(float deltaTime);
	virtual bool shouldBeDestroyed();

	virtual sf::Sprite getSprite();
	virtual std::string getType();
	virtual const int getRenderLayer();
	virtual Vector2 getPosition();
	virtual float getCollisionRange();
};


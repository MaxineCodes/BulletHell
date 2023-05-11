/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	Bullet.h
//
//	Description:
//	 Main class for the bullet entity. This class should generally only be created by an entity
//	 which spawns the bullet, such as an enemy or a player.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Entity.h"


class Bullet : public Entity
{
// Public variables
public:
	std::string m_type = "Bullet";
	Vector2 m_position = Vector2(0.0f, 0.0f);

	bool canHurtPlayer = true;
	bool canHurtEnemy = false;

// Private variables
private:
	sf::Texture m_bulletTexture;
	sf::Sprite m_bulletSprite;

	float m_speed = 0.0f;
	float m_size = 0.0f;
	Vector2 m_direction = Vector2(0.0f, 0.0f);

// Public functions
public:
	Bullet(Vector2 startPosition, Vector2 startDirection, float speed, float size, sf::Texture& texture);
	~Bullet() {}

	void init();
	void update(float deltaTime);
	sf::Sprite getSprite();
	std::string getType();
	Vector2 getPosition();
	void Delete();

private:
	void loadResources();
};
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
private:
	const int m_renderLayer = 6;
	std::string m_type = "Bullet";
	Vector2 m_position = Vector2(0.0f, 0.0f);
	float m_collisionRange = 1;

	std::string m_textureName;
	sf::Texture m_bulletTexture;
	sf::Sprite m_bulletSprite;

	float m_speed = 0.0f;
	float m_size = 0.0f;
	Vector2 m_direction = Vector2(0.0f, 0.0f);

public:
	Bullet() {}
	Bullet(Vector2 startPosition, 
		   Vector2 startDirection, 
		   float speed, 
		   float size, 
		   const char* textureName);

	~Bullet() { std::cout << "Bullet destroyed" << std::endl; }

	void update(float deltaTime);
	void lateUpdate(float deltaTime);
	bool shouldBeDestroyed();

	sf::Sprite getSprite();
	std::string getType();
	const int getRenderLayer();
	Vector2 getPosition();
	float getCollisionRange();
};
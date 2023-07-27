/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	Player.h
//
//	Description:
//	 Main player class and the most complex entity. It is spawned on start, before the first update.
//	 This class handles user input, movement, shooting bullets, etc.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Entity.h"


class Player : public Entity
{
private:
	const int m_renderLayer = 3;
	std::string m_type = "Player";
	Vector2 m_position = Vector2(0.0f, 0.0f);
	float m_collisionRange = 2;

	const int m_shootDelay = 75; // <- in miliseconds
	const float m_size = 1.5f;
	const float m_hitboxSpriteScale = 3.0f;
	const float m_normalSpeed = 0.065f;
	const float m_slowSpeed = 0.020f;
	const float m_wallpadding = 15.0f;

	sf::Sprite m_playerSprite;
	sf::Sprite m_hitboxSprite;

	sf::Texture m_playerTexture;
	sf::Texture m_hitboxTexture;
	sf::Texture m_smallBulletTexture;
	sf::Texture m_largeBulletTexture;

	sf::Clock clock;
	sf::Time elapsedTime;
	sf::Time frameTime;

	Vector2 m_direction = Vector2(0.0f, 0.0f);

	bool m_slowmode = false;
	bool m_shooting = false;

public:
	Player();
	~Player() {}

	void update(float deltaTime);
	void lateUpdate(float deltaTime);
	void draw();

	bool shouldBeDestroyed();
	sf::Sprite getSprite();
	std::string getType();
	const int getRenderLayer();
	Vector2 getPosition();
	float getCollisionRange();

private:
	void init();
	void loadResources();
	void shoot();
	void movement(float SPEED, int WINDOWWIDTH, int WINDOWHEIGHT, float deltaTime);
	bool isShooting();
};
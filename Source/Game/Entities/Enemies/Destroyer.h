/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	Destroyer.h
//
//	Description:
//	 An enemy! It shoots very large bullets all around in random intervals.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../Entity.h"


class Destroyer : public Enemy
{
	const int m_renderLayer = 6;
	std::string m_type = "Enemy";
	const float m_size = 2.5f;
	float m_collisionRange = 40;
	const int m_damageFlashTimer = 50;

	int m_health = 1000000;

	Vector2 m_position = Vector2(0.0f, 0.0f);
	Vector2 m_direction = Vector2(0.0f, 0.0f);

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	sf::Clock hitClock;
	sf::Clock attackClock;
	sf::Clock clock;

public:
	Destroyer(Vector2 position);
	~Destroyer() {}

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
	Vector2 moveTo(Vector2 moveTarget, float speed);
	void attack(const int state);
};


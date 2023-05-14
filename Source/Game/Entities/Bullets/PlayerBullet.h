#pragma once

#include "../Bullet.h"

class PlayerBullet : public Bullet
{
	const int m_renderLayer = 2;
	std::string m_type = "PlayerBullet";
	Vector2 m_position = Vector2(0.0f, 0.0f);
	float m_collisionRange = 0.5;

	std::string m_textureName;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	float m_speed = 0.0f;
	float m_size = 0.0f;
	Vector2 m_direction = Vector2(0.0f, 0.0f);

public:
	PlayerBullet(Vector2 startPosition,
				 Vector2 startDirection,
				 float speed,
				 float size,
				 const char* textureName);
	~PlayerBullet() {}

	void update(float deltaTime);
	void lateUpdate(float deltaTime);
	bool shouldBeDestroyed();

	sf::Sprite getSprite();
	std::string getType();
	const int getRenderLayer();
	Vector2 getPosition();
	float getCollisionRange();
};


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
#include "../EntityList.h"

class EntityList;


class Player : public Entity
{
public:

	std::string m_type = "Player";
	Vector2 m_position = Vector2(0.0f, 0.0f);

private:

	const sf::Time m_shootDelay = sf::milliseconds(10);
	const float m_playerScale = 1.5f;
	const float m_hitboxSpriteScale = 3.0f;
	const float m_normalSpeed = 0.055f;
	const float m_slowSpeed = 0.015f;
	const float m_wallpadding = 0.0f;//15.0f;

	sf::Sprite m_playerSprite;

	sf::Texture m_playerTexture;
	sf::Texture m_hitBoxTexture;
	sf::Texture m_smallBulletTexture;
	sf::Texture m_largeBulletTexture;

	sf::Clock clock;
	sf::Time elapsedTime;
	sf::Time frameTime;

	EntityList* m_gameEntityList;

	int m_gameWindowWidth;
	int m_gameWindowHeight;

	Vector2 m_direction = Vector2(0.0f, 0.0f);

	bool m_slowmode = false;
	bool m_shooting = false;

// Public functions
public:
	Player(int windowWidth, int windowHeight, EntityList *gameEntityList);
	void init();
	sf::Sprite getSprite();
	std::string getType();
	Vector2 getPosition();
	void update(float deltaTime);
	void Delete();

//Private functions
private:
	void loadResources();
	sf::Time shoot();
	void movement(float SPEED, int WINDOWWIDTH, int WINDOWHEIGHT, float deltaTime);
	bool isShooting();
};
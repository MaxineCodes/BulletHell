/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	Entity.h
//
//	Description:
//	 Main entity interface class.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../ResourceManagement/ResourceManager.h"
#include "../Datatypes/Vector2.h"


// Entity base interface
class Entity
{
public:
	const int m_renderLayer = 0;
	std::string m_type = "Entity";
	Vector2 m_position = Vector2(0.0f, 0.0f);
	float m_collisionRange = 0;

private:
	sf::Texture entityTexture;
	sf::Sprite entitySprite;

public:
	Entity() {}
	~Entity() {}

	virtual void update(float deltaTime);
	virtual void lateUpdate(float deltaTime);
	virtual bool shouldBeDestroyed();

	virtual sf::Sprite getSprite();
	virtual std::string getType();
	virtual const int getRenderLayer();
	virtual Vector2 getPosition();
	virtual float getCollisionRange();
};

// Sub classes includes
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
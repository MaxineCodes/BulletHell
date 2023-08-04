#include "PlayerBullet.h"

#include "../../Math/Colllision.h"
#include "../../Math/GameMath.h"
#include "../../GameGlobals.h"


PlayerBullet::PlayerBullet(Vector2 startPosition, Vector2 startDirection, float speed, float size, const char* textureName)
{
	//std::cout << "PlayerBullet Created" << std::endl;

	m_direction = startDirection;
	m_speed = speed;
	m_size = size;
	m_collisionRange = m_collisionRange * GAME_SCALE;

	m_texture = GAME_RESOURCEMANAGER->getTexture(textureName);
	m_sprite.setTexture(m_texture);

	const float textureSize = float(getTextureDimensions(m_texture)[0]);
	m_sprite.setOrigin(textureSize / 2, textureSize / 2 + textureSize / 6);
	m_sprite.setScale(m_size * GAME_SCALE, m_size * GAME_SCALE);
	m_sprite.setPosition(startPosition.x, startPosition.y);
}

void PlayerBullet::update(float deltaTime)
{
	m_position.x = m_sprite.getPosition().x;
	m_position.y = m_sprite.getPosition().y;

	// lag machine
	//const float textureSize = float(getTextureDimensions(m_texture)[0]);

	m_direction = normalize(m_direction);

	m_sprite.move((m_direction.x * m_speed) * deltaTime, (m_direction.y * m_speed) * deltaTime);
}

void PlayerBullet::lateUpdate(float deltaTime)
{
}

void PlayerBullet::draw()
{
	GAME_RENDERER->draw(m_sprite);
}

bool PlayerBullet::shouldBeDestroyed()
{
	if (!isInGameArea(m_position, GAME_SETTINGS.GAME_WINDOWWIDTH, GAME_SETTINGS.GAME_WINDOWHEIGHT))
		return true;

	if (hasCollided("Enemy", m_position, m_collisionRange))
		return true;

	return false;
}

sf::Sprite PlayerBullet::getSprite()
{
	return m_sprite;
}

std::string PlayerBullet::getType()
{
	return m_type;
}

const int PlayerBullet::getRenderLayer()
{
	return m_renderLayer;
}

Vector2 PlayerBullet::getPosition()
{
	return m_position;
}

float PlayerBullet::getCollisionRange()
{
	return m_collisionRange;
}

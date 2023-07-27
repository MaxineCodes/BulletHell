#include "Player.h"
#include "Bullet.h"

#include "../Math/Colllision.h"
#include "../Math/GameMath.h"
#include "Bullets/PlayerBullet.h"

#include "../GameGlobals.h"
#include "../../Settings/GameSettings.h"

// Constructor
Player::Player()
{
	loadResources();
	init();
}

// Initialize
void Player::init()
{
	const int playerTextureSize = GAME_RESOURCEMANAGER->getTextureSize(m_playerTexture);
	const int hitboxTextureSize = GAME_RESOURCEMANAGER->getTextureSize(m_hitboxTexture);

	// Set player sprite scale and set origin aka pivot to center
	m_playerSprite.setOrigin(float(playerTextureSize / 2), float(playerTextureSize / 2 + playerTextureSize / 6));
	m_playerSprite.setScale(m_size * GAME_SCALE, m_size * GAME_SCALE);

	m_hitboxSprite.setOrigin(float(hitboxTextureSize / 2), float(hitboxTextureSize / 2 + hitboxTextureSize / 24));
	m_hitboxSprite.setScale(m_collisionRange*2 * GAME_SCALE, m_collisionRange*2 * GAME_SCALE);

	// Set starting position of player
	const float startPositionX = static_cast<float>(GAME_SETTINGS.GAME_WINDOWWIDTH)  / 2 * 1; // 2:1 ratio
	const float startPositionY = static_cast<float>(GAME_SETTINGS.GAME_WINDOWHEIGHT) / 5 * 4; // 5:4 ratio
	m_playerSprite.setPosition(startPositionX, startPositionY);
	m_hitboxSprite.setPosition(startPositionX, startPositionY);
}

sf::Sprite Player::getSprite()
{
	return m_playerSprite;
}

std::string Player::getType()
{
	return m_type;
}

const int Player::getRenderLayer()
{
	return m_renderLayer;
}

Vector2 Player::getPosition()
{
	//return sprite position + half the sprite size in pixels, multiplied by the sprite size multiplier
	//return Vector2(m_hitboxSprite.getPosition().x + float(16 * m_size), m_hitboxSprite.getPosition().y + float(16 * m_size));

	return Vector2(m_hitboxSprite.getPosition().x, m_hitboxSprite.getPosition().y);
}

float Player::getCollisionRange()
{
	return m_collisionRange;
}

// Every update
void Player::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(GAME_SETTINGS.KEYBINDS.SLOW))
		 m_slowmode = true;
	else m_slowmode = false;

	if (m_slowmode) 
		movement(m_slowSpeed, GAME_SETTINGS.GAME_WINDOWWIDTH, GAME_SETTINGS.GAME_WINDOWHEIGHT, deltaTime);
	else 
		movement(m_normalSpeed, GAME_SETTINGS.GAME_WINDOWWIDTH, GAME_SETTINGS.GAME_WINDOWHEIGHT, deltaTime);

	if (sf::Keyboard::isKeyPressed(GAME_SETTINGS.KEYBINDS.SHOOT))
	{
		if (clock.getElapsedTime().asMilliseconds() >= m_shootDelay)
		{
			shoot();
			clock.restart();
		}
	}

	if (hasCollided("Bullet", getPosition(), m_collisionRange))
		std::cout << "I am hit!!" << std::endl;
	//else
	//	std::cout << "" << std::endl;

}

void Player::lateUpdate(float deltaTime)
{

}

void Player::draw()
{
	GAME_RENDERER->draw(m_playerSprite);

	if (m_slowmode)
		GAME_RENDERER->draw(m_hitboxSprite);
}

bool Player::shouldBeDestroyed()
{
	return false;
}

// Load player resources
void Player::loadResources()
{
	m_playerTexture = GAME_RESOURCEMANAGER->getTexture("Cirno.png");
	m_playerSprite.setTexture(m_playerTexture);

	m_hitboxTexture = GAME_RESOURCEMANAGER->getTexture("Hitbox.png");
	m_hitboxSprite.setTexture(m_hitboxTexture);
}

void Player::shoot()
{
	float bulletSpeed = 0.35f;
	float bulletSize = 2.5f;
	float bulletSpread = 0.055f;
	float bulletOffset = 15.0f * GAME_SCALE;
	float bulletHeightOffset = 2.0f;
	const char* texture = "PlayerBulletLarge.png";
	if (m_slowmode) 
	{
		texture = "PlayerBulletSmall.png";
		bulletSpeed = 0.35f;
		bulletSpread = 0.005f;
		bulletSize = 4.0f;
		float bulletOffset = 5.0f;
	}
	
	Vector2 pos0(m_position.x, m_position.y - bulletHeightOffset*2);
	Vector2 pos1(m_position.x - bulletOffset, m_position.y - bulletHeightOffset);
	Vector2 pos2(m_position.x - bulletOffset*2, m_position.y);
	Vector2 pos3(m_position.x + bulletOffset, m_position.y - bulletHeightOffset);
	Vector2 pos4(m_position.x + bulletOffset*2, m_position.y);
	
	auto bullet0 = std::make_shared<PlayerBullet>(pos0, Vector2(0.0f, -1.0f), bulletSpeed, bulletSize, texture);
	GAME_ENTITYLIST->add(bullet0);
	
	auto bullet1 = std::make_shared<PlayerBullet>(pos1, Vector2(-bulletSpread, -0.9f), bulletSpeed, bulletSize, texture);
	GAME_ENTITYLIST->add(bullet1);
	
	auto bullet2 = std::make_shared<PlayerBullet>(pos2, Vector2(-bulletSpread*2, -0.8f), bulletSpeed, bulletSize, texture);
	GAME_ENTITYLIST->add(bullet2);
	
	auto bullet3 = std::make_shared<PlayerBullet>(pos3, Vector2(bulletSpread, -0.9f), bulletSpeed, bulletSize, texture);
	GAME_ENTITYLIST->add(bullet3);
	
	auto bullet4 = std::make_shared<PlayerBullet>(pos4, Vector2(bulletSpread*2, -0.8f), bulletSpeed, bulletSize, texture);
	GAME_ENTITYLIST->add(bullet4);

}

// Movement inputs
void Player::movement(float SPEED, int WINDOWWIDTH, int WINDOWHEIGHT, float deltaTime)
{
	// Store sprite position
	m_position.x = m_playerSprite.getPosition().x;
	m_position.y = m_playerSprite.getPosition().y;

	// Setting direction vector through input
	// and checks if player is not touching a edge
	if (sf::Keyboard::isKeyPressed(GAME_SETTINGS.KEYBINDS.MOVE_LEFT) && !IsTouchingLeft(m_position, WINDOWWIDTH, WINDOWHEIGHT, m_wallpadding)) {
		m_direction.x =	-1.0f; }
	if (sf::Keyboard::isKeyPressed(GAME_SETTINGS.KEYBINDS.MOVE_RIGHT) && !IsTouchingRight(m_position, WINDOWWIDTH, WINDOWHEIGHT, m_wallpadding)) {
		m_direction.x =	 1.0f; }
	if (sf::Keyboard::isKeyPressed(GAME_SETTINGS.KEYBINDS.MOVE_UP) && !IsTouchingUp(m_position, WINDOWWIDTH, WINDOWHEIGHT, m_wallpadding)) {
		m_direction.y =	-1.0f; }
	if (sf::Keyboard::isKeyPressed(GAME_SETTINGS.KEYBINDS.MOVE_DOWN) && !IsTouchingDown(m_position, WINDOWWIDTH, WINDOWHEIGHT, m_wallpadding)) {
		m_direction.y =	 1.0f; }

	// Normalize direction vector
	m_direction = Normalize(m_direction);

	// Move player to direction vector
	m_playerSprite.move((m_direction.x * SPEED) * deltaTime, (m_direction.y * SPEED) * deltaTime);
	m_hitboxSprite.setPosition(m_playerSprite.getPosition());

	// Reset direction
	m_direction = Vector2(0.0f, 0.0f);
}

bool Player::isShooting() 
{
	if (m_shooting) { return true; }
	else { return false; }
}
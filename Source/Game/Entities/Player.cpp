#include "Player.h"
#include "Bullet.h"

#include "../Math/Colllision.h"
#include "../Math/GameMath.h"
#include "Bullets/PlayerBullet.h"

#include "../GameGlobals.h"

// Constructor
Player::Player()
{
	loadResources();
	init();
}

// Initialize
void Player::init()
{
	// Set player sprite scale and set origin aka pivot to center
	m_playerSprite.setOrigin(float(32 / 2), float(32 / 2 + 32 / 6));
	m_playerSprite.setScale(m_size * GAME_SCALE, m_size * GAME_SCALE);

	// Set starting position of player
	const float startPositionX = static_cast<float>(GAME_WINDOWWIDTH)  / 2 * 1; // 2:1 ratio
	const float startPositionY = static_cast<float>(GAME_WINDOWHEIGHT) / 5 * 4; // 5:4 ratio
	m_playerSprite.setPosition(startPositionX, startPositionY);
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
	return m_position;
}

float Player::getCollisionRange()
{
	return m_collisionRange;
}

// Every update
void Player::update(float deltaTime)
{
	//sf::Time frameTime = clock.getElapsedTime();
	//sf::Time elapsedTime; //= clock.restart();
	//elapsedTime += clock.restart();
	//const unsigned int seconds = static_cast<unsigned int>(elapsedTime.asMilliseconds());
	//timer.value -= elapsed.asMiliseconds();
	sf::Time timeOfLastBullet;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) m_slowmode = true;
	else m_slowmode = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) m_shooting = true;
	else m_shooting = false;

	if (m_slowmode) 
	{
		movement(m_slowSpeed, GAME_WINDOWWIDTH, GAME_WINDOWHEIGHT, deltaTime);
		m_playerSprite.setTexture(m_hitBoxTexture);
	}
	else
	{
		movement(m_normalSpeed, GAME_WINDOWWIDTH, GAME_WINDOWHEIGHT, deltaTime);
		m_playerSprite.setTexture(m_playerTexture);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		if (clock.getElapsedTime().asMilliseconds() >= m_shootDelay)
		{
			shoot();
			clock.restart();
		}
	}

	if (hasCollided("Bullet", m_position, m_collisionRange))
		std::cout << "I am hit!!" << std::endl;
}

void Player::lateUpdate(float deltaTime)
{

}

bool Player::shouldBeDestroyed()
{
	return false;
}

// Load player resources
void Player::loadResources()
{
	m_playerTexture = GAME_RESOURCEMANAGER->getTexture("Cirno.png");
	m_hitBoxTexture = GAME_RESOURCEMANAGER->getTexture("Flandre.png");
	m_playerSprite.setTexture(m_playerTexture);
}

void Player::shoot()
{
	float bulletSpeed = 0.55f;
	float bulletSize = 2.5f;
	float bulletSpread = 0.055f;
	float bulletOffset = 15.0f;
	float bulletHeightOffset = 2.0f;
	const char* texture = "PlayerBulletLarge.png";
	if (m_slowmode) 
	{
		texture = "PlayerBulletSmall.png";
		bulletSpeed = 0.55f;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !IsTouchingLeft(m_position, WINDOWWIDTH, WINDOWHEIGHT, m_wallpadding)) {
		m_direction.x =	-1.0f; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !IsTouchingRight(m_position, WINDOWWIDTH, WINDOWHEIGHT, m_wallpadding)) {
		m_direction.x =	 1.0f; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !IsTouchingUp(m_position, WINDOWWIDTH, WINDOWHEIGHT, m_wallpadding)) {
		m_direction.y =	-1.0f; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !IsTouchingDown(m_position, WINDOWWIDTH, WINDOWHEIGHT, m_wallpadding)) {
		m_direction.y =	 1.0f; }

	// Normalize direction vector
	m_direction = Normalize(m_direction);

	// Move player to direction vector
	m_playerSprite.move((m_direction.x * SPEED) * deltaTime, (m_direction.y * SPEED) * deltaTime);

	// Reset direction
	m_direction = Vector2(0.0f, 0.0f);
}

bool Player::isShooting() 
{
	if (m_shooting) { return true; }
	else { return false; }
}
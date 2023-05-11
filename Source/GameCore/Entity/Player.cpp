#include "Player.h"
#include "Bullet.h"

// Constructor
Player::Player(int windowWidth, int windowHeight, EntityList *gameEntityList)
{
	m_gameWindowWidth = windowWidth;
	m_gameWindowHeight = windowHeight;
	m_gameEntityList = gameEntityList;

	init();
}

// Initialize
void Player::init()
{
	// Set player sprite scale and set origin aka pivot to center
	m_playerSprite.setOrigin(32 / 2, 32 / 2 + 32 / 6);
	m_playerSprite.setScale(m_playerScale, m_playerScale);
	//hitBoxSprite.setOrigin(32 / 2, 32 / 2);
	//hitBoxSprite.setScale(HITBOXSPRITESCALE, HITBOXSPRITESCALE);

	// Set starting position of player
	const float startPositionX = static_cast<float>(m_gameWindowWidth)  / 2 * 1; // 2:1 ratio
	const float startPositionY = static_cast<float>(m_gameWindowHeight) / 5 * 4; // 5:4 ratio
	m_playerSprite.setPosition(startPositionX, startPositionY);

	// Load player resources on initialization
	loadResources();
}

sf::Sprite Player::getSprite()
{
	return m_playerSprite;
}

std::string Player::getType()
{
	return m_type;
}

Vector2 Player::getPosition()
{
	return m_position;
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
		movement(m_slowSpeed, m_gameWindowWidth, m_gameWindowHeight, deltaTime);
		//hitBoxSprite.setPosition(position.x, position.y);
	}
	else movement(m_normalSpeed, m_gameWindowWidth, m_gameWindowHeight, deltaTime);

	if (m_shooting) 
	{
		timeOfLastBullet = shoot();
	}
}

void Player::Delete()
{

}

// Load player resources
void Player::loadResources()
{
	std::cout << "Player::LoadResources()" << std::endl;

	// Player Sprite
	if (!m_playerTexture.loadFromFile("Res/Cirno.png"))
		std::cout << "Texture not found: Cirno.png" << std::endl;

	m_playerSprite.setTexture(m_playerTexture);

	// Hitbox Sprite
	if (!m_hitBoxTexture.loadFromFile("Res/Hitbox.png"))
		std::cout << "Texture not found: Hitbox.png" << std::endl;

	// Large Bullet Texture
	if (!m_largeBulletTexture.loadFromFile("Res/PlayerBulletLarge.png"))
		std::cout << "Texture not found: PlayerBulletLarge.png" << std::endl;


	// Small Bullet Texture
	if (!m_largeBulletTexture.loadFromFile("Res/PlayerBulletSmall.png"))
		std::cout << "Texture not found: PlayerBulletSmall.png" << std::endl;
}

sf::Time Player::shoot()
{
	frameTime = clock.getElapsedTime();
	elapsedTime += clock.restart();

	if (frameTime >= m_shootDelay)
	{	
		// Shoot
		float bulletSpeed = 0.05f;
		float bulletSize = 2.0f;
		float bulletSpread = 0.05f;

		auto bullet0 = std::make_shared<Bullet>(m_position, Vector2(0.0f, -1.0f), bulletSpeed, bulletSize, m_smallBulletTexture);
		bullet0.get()->canHurtPlayer = false;
		bullet0.get()->canHurtEnemy = true;
		m_gameEntityList->add(bullet0);

		auto bullet1 = std::make_shared<Bullet>(m_position, Vector2(-bulletSpread, -0.9f), bulletSpeed, bulletSize, m_smallBulletTexture);
		bullet1.get()->canHurtPlayer = false;
		bullet1.get()->canHurtEnemy = true;
		m_gameEntityList->add(bullet1);

		auto bullet2 = std::make_shared<Bullet>(m_position, Vector2(-bulletSpread*2, -0.8f), bulletSpeed, bulletSize, m_smallBulletTexture);
		bullet2.get()->canHurtPlayer = false;
		bullet2.get()->canHurtEnemy = true;
		m_gameEntityList->add(bullet2);

		auto bullet3 = std::make_shared<Bullet>(m_position, Vector2(bulletSpread, -0.9f), bulletSpeed, bulletSize, m_smallBulletTexture);
		bullet3.get()->canHurtPlayer = false;
		bullet3.get()->canHurtEnemy = true;
		m_gameEntityList->add(bullet3);

		auto bullet4 = std::make_shared<Bullet>(m_position, Vector2(bulletSpread*2, -0.8f), bulletSpeed, bulletSize, m_smallBulletTexture);
		bullet4.get()->canHurtPlayer = false;
		bullet4.get()->canHurtEnemy = true;
		m_gameEntityList->add(bullet4);

		frameTime = clock.restart();
	}

	return frameTime;
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
#include "Destroyer.h"

#include "../../Math/Colllision.h"
#include "../../Math/GameMath.h"
#include "../../GameGlobals.h"

Destroyer::Destroyer(Vector2 position)
{
	m_position = position;

	m_texture = GAME_RESOURCEMANAGER->getTexture("Flandre.png");
	m_sprite.setTexture(m_texture);

	const float textureSize = float(getTextureDimensions(m_texture)[0]);
	m_sprite.setOrigin(textureSize / 2, textureSize / 2 + textureSize / 6);
	m_sprite.setScale(m_size * GAME_SCALE, m_size * GAME_SCALE);
	m_sprite.setPosition(position.x, position.y);
}

void Destroyer::update(float deltaTime)
{
	sf::Time elapsed = clock.getElapsedTime();
	const int secondsElapsed = elapsed.asSeconds();

	sf::Time hitElapsed = hitClock.getElapsedTime();

	if (hitElapsed.asMilliseconds() > m_damageFlashTimer)
		m_sprite.setColor(sf::Color::White);


	// Start of scripted events, a loop
	int state = 0;

	if (secondsElapsed >= 2 && secondsElapsed <= 4)
	{
		state = 1;
		Vector2 target(static_cast<float>(GAME_SETTINGS.GAME_WINDOWWIDTH) / 3*1, static_cast<float>(GAME_SETTINGS.GAME_WINDOWHEIGHT) / 2*1);
		m_position = moveTo(target, 0.05f * deltaTime);
	}

	if (secondsElapsed >= 2 && secondsElapsed <= 6)
	{
		state = 2;
	}

	else if (secondsElapsed >= 6 && secondsElapsed <= 24)
	{
		state = 3;
		Vector2 target(static_cast<float>(GAME_SETTINGS.GAME_WINDOWWIDTH) / 2 * 1, static_cast<float>(GAME_SETTINGS.GAME_WINDOWHEIGHT) / 5 * 1);
		m_position = moveTo(target, 0.05f * deltaTime);
	}

	else if (secondsElapsed >= 24)
	{
		int state = 0;
		clock.restart();
	}

	m_sprite.setPosition(m_position.x, m_position.y);



	attack(state);
}

void Destroyer::lateUpdate(float deltaTime)
{
	if (hasCollided("PlayerBullet", m_position, m_collisionRange))
	{
		//std::cout << "Enemy is hit!!" << std::endl;

		m_health = m_health - 750;

		m_sprite.setColor(sf::Color::Cyan);
		hitClock.restart();
	}
}

void Destroyer::draw()
{
	GAME_RENDERER->draw(m_sprite);
}

bool Destroyer::shouldBeDestroyed()
{
	if (m_health <= 1)
		return true;

	return false;
}

sf::Sprite Destroyer::getSprite()
{
	return m_sprite;
}

std::string Destroyer::getType()
{
	return m_type;
}

const int Destroyer::getRenderLayer()
{
	return m_renderLayer;
}

Vector2 Destroyer::getPosition()
{
	return m_position;
}

float Destroyer::getCollisionRange()
{
	return m_collisionRange;
}

Vector2 Destroyer::moveTo(Vector2 moveTarget, float speed)
{
	float ax = moveTarget.x - m_position.x;
	float ay = moveTarget.y - m_position.y;
	Vector2 a(ax, ay);
	float magnitude = getMagnitude(a);
	
	if (magnitude <= speed || magnitude == 0.0f)
	{
		return moveTarget;
	}
	
	float x = m_position.x + a.x / magnitude * speed;
	float y = m_position.y + a.y / magnitude * speed;
	return Vector2(x, y);
}

void Destroyer::attack(const int state)
{
	//std::cout << state << std::endl;
	int shootDelay = 125;

	if (state == 1)
	{
		const int bulletCount = 100;


		if (attackClock.getElapsedTime().asMilliseconds() >= shootDelay)
		{
			for (int i = 0; i < bulletCount; i++)
			{

			}

			attackClock.restart();
		}
	}
}

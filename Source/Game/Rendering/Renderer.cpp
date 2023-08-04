#include "Renderer.h"
#include "../GameGlobals.h"

Renderer::Renderer(std::shared_ptr<sf::RenderWindow> gameRenderWindow)
{
	m_gameWindow_ptr = gameRenderWindow;

	updateBackground();
}

void Renderer::draw(sf::Sprite sprite)
{
	m_gameWindow_ptr->draw(sprite);
}

void Renderer::draw(sf::CircleShape circleShape)
{
	m_gameWindow_ptr->draw(circleShape);
}

void Renderer::updateBackground()
{
	if (!GAME_SETTINGS.DEBUG_COLLISION_CIRCLES)
	{
		const char* backGroundTextureName = GAME_SESSIONSTATE.get()->getBackgroundTextureName();
		m_backgroundTexture = GAME_RESOURCEMANAGER.get()->getTexture(backGroundTextureName);
		m_backgroundSprite.setTexture(m_backgroundTexture);
		m_backgroundSprite.setScale(GAME_SCALE * 2, GAME_SCALE * 2);
	}

	if (GAME_SETTINGS.DEBUG_COLLISION_CIRCLES)
		clear(sf::Color::Black);
}

void Renderer::clear(sf::Color colour)
{
	m_gameWindow_ptr->clear(colour);
	m_gameWindow_ptr->draw(m_backgroundSprite);
}

void Renderer::display()
{
	m_gameWindow_ptr->display();
}

void Renderer::render()
{
	clear(sf::Color::Black);

	if (!GAME_SETTINGS.DEBUG_DISABLE_ART)
		GAME_ENTITYLIST->draw();

	if (GAME_SETTINGS.DEBUG_COLLISION_CIRCLES)
	{
		GAME_ENTITYLIST->drawCollisionCircles();
	}

	display();
}

void Renderer::renderGameUI()
{

}

void Renderer::drawAllEntities()
{
	// Iterate over every layer
	for (int i = 0; i < m_layerCount; i++)
	{
		for (std::shared_ptr<Entity> entity : GAME_ENTITYLIST->getList())
		{
			if (entity->getRenderLayer() == i)
				m_gameWindow_ptr->draw(entity->getSprite());
		}
	}
}
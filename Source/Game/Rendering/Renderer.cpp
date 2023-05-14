#include "Renderer.h"
#include "../GameGlobals.h"

Renderer::Renderer(std::shared_ptr<sf::RenderWindow> gameRenderWindow)
{
	m_gameWindow_ptr = gameRenderWindow;

	setBackground();
}

void Renderer::draw(sf::Sprite sprite)
{
	m_gameWindow_ptr->draw(sprite);
}

void Renderer::setBackground()
{
	const char* backGroundTextureName = GAME_SESSIONSTATE.get()->getBackgroundTextureName();
	m_backgroundTexture = GAME_RESOURCEMANAGER.get()->getTexture(backGroundTextureName);
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setScale(2, 2);
}

void Renderer::render()
{
	m_gameWindow_ptr->clear(sf::Color::Black);

	m_gameWindow_ptr->draw(m_backgroundSprite);

	// Iterate over every layer
	for (int i = 0; i < m_layerCount; i++)
	{
		for (auto entity : GAME_ENTITYLIST->getList())
		{
			if (entity->getRenderLayer() == i)
				m_gameWindow_ptr->draw(entity->getSprite());
		}
	}

	m_gameWindow_ptr->display();
}
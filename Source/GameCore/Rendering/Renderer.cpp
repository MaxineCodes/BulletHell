#include "Renderer.h"
#include "../GameGlobals.h"

Renderer::Renderer(std::shared_ptr<sf::RenderWindow> gameRenderWindow)
{
	m_gameWindow_ptr = gameRenderWindow;
}

void Renderer::render()
{
	m_gameWindow_ptr->clear(sf::Color::Black);

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
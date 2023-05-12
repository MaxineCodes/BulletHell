#include "Renderer.h"

Renderer::Renderer(EntityList *entityList, std::shared_ptr<sf::RenderWindow> gameRenderWindow, const int windowWidth, const int windowHeight)
{
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;

	m_gameEntityList = entityList;
	m_gameWindow_ptr = gameRenderWindow;
}

void Renderer::render()
{
	m_gameWindow_ptr->clear(sf::Color::Black);

	// Iterate over every layer
	for (int i = 0; i < m_layerCount; i++)
	{
		for (auto entity : m_gameEntityList->getList())
		{
			if (entity->getRenderLayer() == i)
				m_gameWindow_ptr->draw(entity->getSprite());
		}
	}

	m_gameWindow_ptr->display();
}
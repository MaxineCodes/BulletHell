#include "RenderLayers.h"

RenderLayers::RenderLayers(sf::RenderWindow *renderWindow, const int windowWidth, const int windowHeight)
{
	renderWindow_ptr = renderWindow;

	for (int i = 0; i < renderLayerCount; i++)
	{
		if (!renderLayer[i].create(windowWidth, windowHeight))
			std::cout << "Failed to create render layer" << std::endl;
	}
}

void RenderLayers::draw(sf::Sprite sprite, const int layer)
{
	renderLayer[layer].draw(sprite);
}

void RenderLayers::display()
{
	for (int i = 1; i < renderLayerCount; i++)
	{
		sf::Texture texture = renderLayer[i].getTexture();
		sf::Sprite sprite;
		sprite.setTexture(texture);

		renderWindow_ptr->draw(sprite);
	}
	renderWindow_ptr->display();
}

void RenderLayers::clear(const int layer)
{
	renderLayer[layer].clear();
}

void RenderLayers::clearAllLayers()
{
	for (int i = 0; i < renderLayerCount; i++)
	{
		renderLayer[i].clear();
	}
}

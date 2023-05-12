//
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class RenderLayers
{
private:
	sf::RenderTexture renderLayer[5];
	const int renderLayerCount = sizeof(renderLayer) / sizeof(sf::RenderTexture);

	sf::RenderWindow* renderWindow_ptr;

public:
	RenderLayers(sf::RenderWindow* renderWindow, const int windowWidth, const int windowHeight);
	~RenderLayers() {}

	void draw(sf::Sprite sprite, const int layer);
	void display();
	void clear(const int layer);
	void clearAllLayers();

};


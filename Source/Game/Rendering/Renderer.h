/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	Renderer.h
//
//	Description:
//	 Class which handles all the rendering seperately.
// 
//  Layers:
//   Every entity has a getLayer() function to help us place it on the appropriate layer.
// 
//   These are the general rules for what layer something is rendered to.
//   Ofcourse it's more of a suggestion than set in stone.
// 
//	   Layer 0: Background
//	   Layer 1: Fx over background
//	   Layer 2: Player bullets
//	   Layer 3: Player
// 	   Layer 4: Large enemy bullets
//	   Layer 5: Small enemy bullets
//	   Layer 6: Enemy
//	   Layer 7: Screen-wide fx
//	   Layer 8: User interface
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Entities/EntityList.h"


class Renderer
{
private:
	const int m_layerCount = 7;
	std::shared_ptr<sf::RenderWindow> m_gameWindow_ptr;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

public:
	Renderer() {}
	Renderer(std::shared_ptr<sf::RenderWindow> gameRenderWindow);
	~Renderer() {}

	void draw(sf::Sprite sprite);

	void setBackground();

	void display();

	void render();
};
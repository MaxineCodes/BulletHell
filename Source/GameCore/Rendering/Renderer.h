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
//	   Layer 2: Large enemy bullets
//	   Layer 3: Player bullets
//	   Layer 4: Enemies
// 	   Layer 5: Small enemy bullets
//	   Layer 6: Player
//	   Layer 7: Screen-wide fx
//	   Layer 8: User interface
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../EntityList.h"
//#include "../GameGlobals.h"


class Renderer
{
private:
	int m_windowWidth, m_windowHeight;
	const int m_layerCount = 7;

	std::shared_ptr<sf::RenderWindow> m_gameWindow_ptr;
	EntityList *m_gameEntityList;

public:
	Renderer() {}
	Renderer(EntityList *entityList, 
			 std::shared_ptr<sf::RenderWindow> gameRenderWindow, 
			 const int windowWidth, 
			 const int windowHeight);
	~Renderer() {}

	void render();
};
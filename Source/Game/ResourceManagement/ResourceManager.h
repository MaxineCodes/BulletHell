/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	ResourceManager.h
//
//	Description:
//	 Class handling the resources, taking care of loading textures and other resources into
//	 memory to use it more efficiently.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <filesystem>

#include "TextureHolder.h"


class ResourceManager
{
private:
	std::string m_resourceDirectory = "Res/";

	TextureHolder m_textureHolder;
	
public:
	ResourceManager() {}
	~ResourceManager() {}

	bool loadResources(); // Start loading all the resources. If one fails, returns false.
	sf::Texture& getTexture(const char* textureName);  // Grab a sf::Texture by name, ex: "Hitbox.png" 

	const int getTextureSize(const char* textureName);    // Get the the amount of pixels of the width of the sprite.
	const int getTextureSize(const sf::Texture& texture); // Get the the amount of pixels of the width of the sprite.
};

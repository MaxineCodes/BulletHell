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

	bool loadResources();

	sf::Texture& getTexture(const char* textureName);
};

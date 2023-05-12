/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	TextureHolder.h
//
//	Description:
//	 A holder of sf::Textures (.png files) with an interface to access the data.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


class TextureHolder
{
private:
	std::map<std::string, sf::Texture> m_textureMap;

public:
	TextureHolder() {}
	~TextureHolder() {}

public:
	sf::Texture& get(const char* textureName);
	bool add(std::string& fileName, std::string& filePath);
};
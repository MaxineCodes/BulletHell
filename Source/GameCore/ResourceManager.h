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
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>

class ResourceManager
{
private:
	std::string m_resourceDirectory = "Res/";

	std::map<std::string, sf::Texture> m_textureMap;
	//std::map<std::string, sf::Sound>   soundMap;
	
public:
	ResourceManager() {}
	~ResourceManager() {}
	void initialize();

private:
	bool loadResources();
	bool addTexture(std::string& fileName, std::string& filePath);

public:
	sf::Texture getTexture(std::string& textureName);
};


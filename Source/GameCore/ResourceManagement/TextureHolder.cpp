#include "TextureHolder.h"

sf::Texture& TextureHolder::get(const char* textureName)
{
	std::string texturename = textureName;
	return m_textureMap[texturename];
}

bool TextureHolder::add(std::string& fileName, std::string& filePath)
{
	sf::Texture texture;
	if (!texture.loadFromFile(filePath))
	{
		std::cout << " ERROR: Texture not found: " << filePath << std::endl;
		return false;
	}

	m_textureMap[fileName] = texture;
	std::cout << " Loaded Texture: " << filePath << std::endl;
	return true;
}

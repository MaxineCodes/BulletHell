#include "ResourceManager.h"

void ResourceManager::initialize()
{
	loadResources();
}

bool ResourceManager::loadResources()
{
	for (const auto& entry : std::filesystem::directory_iterator(m_resourceDirectory))
	{
		// Get all resources names in the resources directory
		std::filesystem::path path = entry.path().filename();

		std::string filePath	   = m_resourceDirectory + path.generic_string();
		std::string fileExtension  = path.extension().generic_string();
		std::string fileName       = path.stem().generic_string();

		//textureMap[fileName] 
		if (fileExtension == ".png")
			if (!addTexture(fileName, filePath)) return false;

		//if (fileExtension == ".png")
		//	if (!addTexture(fileName, filePath)) return false;
	}

	return true;
}

bool ResourceManager::addTexture(std::string& fileName, std::string& filePath)
{
	// Load texture
	sf::Texture texture;
	if (!texture.loadFromFile(filePath))
	{
		std::cout << "Texture not found: " << filePath << std::endl;
		return false;
	}

	// Add texture to map
	m_textureMap[fileName] = texture;
	std::cout << "Loaded Texture: " << filePath << std::endl;
	return true;
}

sf::Texture ResourceManager::getTexture(std::string& textureName)
{
	return m_textureMap[textureName];
}

#include "ResourceManager.h"

bool ResourceManager::loadResources()
{
	for (const auto& entry : std::filesystem::directory_iterator(m_resourceDirectory))
	{
		// Get all resources names in the resources directory
		std::filesystem::path path = entry.path().filename();
		std::string filePath	   = m_resourceDirectory + path.generic_string();
		std::string fileExtension  = path.extension().generic_string();
		std::string fileName       = path.filename().generic_string();
		std::string fileStem	   = path.stem().generic_string();

		//textureMap[fileName] 
		if (fileExtension == ".png")
			if (!m_textureHolder.add(fileName, filePath)) return false;

		//if (fileExtension == ".png")
		//	if (!addTexture(fileName, filePath)) return false;
	}

	return true;
}

sf::Texture& ResourceManager::getTexture(const char* textureName)
{
	return m_textureHolder.get(textureName);
}

const int ResourceManager::getTextureSize(const char* textureName)
{
	sf::Texture texture = m_textureHolder.get(textureName);
	return getTextureSize(texture);
}

const int ResourceManager::getTextureSize(const sf::Texture& texture)
{
	const int textureWidth = texture.getSize().x;
	//const int textureHeight = texture.getSize().y;
	return textureWidth;
}

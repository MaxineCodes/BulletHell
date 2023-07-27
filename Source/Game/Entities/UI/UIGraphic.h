//
#pragma once

#include "../Entity.h"


class UIGraphic : public Entity
{
private:
	const int m_renderLayer = 0;

	sf::Sprite m_sprite;
	sf::Texture m_texture;

public:
	UIGraphic() {};
	UIGraphic(const char* textureName, Vector2 position, float scale);
	~UIGraphic() {};

	void draw();

	bool shouldBeDestroyed();
	const int getRenderLayer();
	Vector2 getPosition();
};


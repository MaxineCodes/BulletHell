#include "UIGraphic.h"
#include "../../GameGlobals.h"

UIGraphic::UIGraphic(const char* textureName, Vector2 position, float scale)
{
	m_sprite.setPosition(position.x, position.y);
	m_sprite.setScale(scale, scale);

	m_texture = GAME_RESOURCEMANAGER.get()->getTexture(textureName);
	m_sprite.setTexture(m_texture);
}

void UIGraphic::draw()
{
	GAME_RENDERER->draw(m_sprite);
}

bool UIGraphic::shouldBeDestroyed()
{
	return false;
}

const int UIGraphic::getRenderLayer()
{
	return m_renderLayer;
}

Vector2 UIGraphic::getPosition()
{
	return Vector2(m_sprite.getPosition().x, m_sprite.getPosition().y);
}

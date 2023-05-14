#include "Colllision.h"

#include "../GameGlobals.h"


bool hasCollided(const char* collidedEntityType, Vector2 position, float collisionRange)
{
	std::vector<std::shared_ptr<Entity>> entities = GAME_ENTITYLIST->getListByType(collidedEntityType);

	if (entities.size() > 0)
	{
		float entityCollisionRange = entities[0].get()->getCollisionRange();
		float minimumDistanceToCollide = entityCollisionRange + collisionRange;

		for (unsigned int i = 0; i < entities.size(); i++)
		{
			Vector2 entityPosition = entities[i].get()->getPosition();

			if (minimumDistanceToCollide >= getDistance(position, entityPosition))
				return true;
		}
	}

	return false;
}

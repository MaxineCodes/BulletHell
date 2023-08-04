#include "EntityList.h"
#include "../GameGlobals.h"
#include <string>

void EntityList::update(float deltaTime)
{
    // Update all entities
    for (unsigned int i = 0; i < m_entityList.size(); i++)
    {
        m_entityList[i]->update(deltaTime);
    }
}


void EntityList::lateUpdate(float deltaTime)
{
    // Late update all entities
    for (unsigned int i = 0; i < m_entityList.size(); i++)
    {
        m_entityList[i]->lateUpdate(deltaTime);
    }

    // Iterate over entities to delete from the stack if needed
    std::vector<std::shared_ptr<Entity>>::const_iterator entityItr = m_entityList.cbegin();
    while (entityItr != m_entityList.cend())
    {
        if (entityItr->get()->shouldBeDestroyed())
            entityItr = m_entityList.erase(entityItr);

        else entityItr++;
    }
}

void EntityList::draw()
{
    // draw all entities
    for (unsigned int i = 0; i < m_entityList.size(); i++)
    {
        m_entityList[i]->draw();
    }
}


void EntityList::drawCollisionCircles()
{
    // draw all entities
    for (unsigned int i = 0; i < m_entityList.size(); i++)
    {
        const float collisionRange = m_entityList[i]->getCollisionRange();
        if (collisionRange != 0.0f)
        {
            sf::CircleShape collisionShape(0);
            collisionShape.setRadius(collisionRange);

            const float posX = m_entityList[i]->getPosition().x;
            const float posY = m_entityList[i]->getPosition().y;

            collisionShape.setOrigin(collisionRange, collisionRange);
            collisionShape.setPosition(posX, posY);
            collisionShape.setFillColor(sf::Color(255, 25, 25, 128));

            if (m_entityList[i]->getType() == "Player")
                collisionShape.setFillColor(sf::Color(100, 255, 100, 255));

            if (m_entityList[i]->getType() == "Enemy")
                collisionShape.setFillColor(sf::Color(255, 100, 100, 200));

            if (m_entityList[i]->getType() == "PlayerBullet")
            {
                collisionShape.setFillColor(sf::Color(255, 255, 255, 255));
                collisionShape.setRadius(collisionRange * 2);
            }

            GAME_RENDERER->draw(collisionShape);
        }
    }
}


void EntityList::add(std::shared_ptr<Entity> entity)
{
    m_entityList.push_back(entity);
}

std::vector<std::shared_ptr<Entity>> EntityList::getList()
{
    return m_entityList;
}

std::vector<std::shared_ptr<Entity>> EntityList::getListByType(const char* entityType)
{
    std::vector<std::shared_ptr<Entity>> outputEntities;
    std::string type(entityType);

    for (unsigned int i = 0; i < m_entityList.size(); i++)
    {
        if (m_entityList[i].get()->getType() == type)
            outputEntities.push_back(m_entityList[i]);
    }

    return outputEntities;
}

float EntityList::getEntityCollisionRadiusByType(const char* entityType)
{
    std::string type = entityType;

    for (unsigned int i = 0; i < m_entityList.size(); i++)
    {
        if (m_entityList[i].get()->getType() == type)
            return m_entityList[i].get()->getCollisionRange();
    }

    return 0.0f;
}

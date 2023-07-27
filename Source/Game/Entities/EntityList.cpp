#include "EntityList.h"

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

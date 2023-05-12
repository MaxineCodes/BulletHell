#include "EntityList.h"

void EntityList::updateAllEntities(float deltaTime)
{
    // Update all entities
    for (unsigned int i = 0; i < m_entityList.size(); i++)
    {
        m_entityList[i]->update(deltaTime);
    }
}


void EntityList::lateUpdateAllEntities(float deltaTime)
{
    // Iterate over entities to delete from the stack if needed
    std::vector<std::shared_ptr<Entity>>::const_iterator entityItr = m_entityList.cbegin();
    while (entityItr != m_entityList.cend())
    {
        if (entityItr->get()->shouldBeDestroyed())
            entityItr = m_entityList.erase(entityItr);

        else entityItr++;
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

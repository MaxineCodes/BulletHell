#include "EntityList.h"

void EntityList::updateAllEntities(float deltaTime)
{
    //std::cout << deltaTime << std::endl;

    // Update all entities
    for (unsigned int i = 0; i < m_entityList.size(); i++)
    {
        m_entityList[i]->update(deltaTime);
    }

    // Iterate over entities to delete from the stack
    std::vector<std::shared_ptr<Entity>>::const_iterator itr = m_entityList.cbegin();
    while (itr != m_entityList.cend())
    {
        Vector2 position = itr->get()->getPosition();
        std::string type = itr->get()->getType();

        if (position.y < -100.0f && type == "Bullet")
        {
            itr = m_entityList.erase(itr);
        }
        else
        {
            ++itr;
        }
    }
}

void EntityList::lateUpdateAllEntities(float deltaTime)
{

}

void EntityList::renderAllEntities()
{

}

void EntityList::add(std::shared_ptr<Entity> entity)
{
    m_entityList.push_back(entity);
}

std::vector<std::shared_ptr<Entity>> EntityList::getList()
{
    return m_entityList;
}

void EntityList::lateUpdateAllEntities()
{
    for (unsigned int i = 0; i < m_entityList.size(); i++)
    {
        //if (i == m_deleteList[i])
        //{
        //    m_entityList.
        //}
    }
}

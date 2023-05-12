/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	EntityList.h
//
//	Description:
//	 Blabla.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Entity/Entity.h"


// Class containing all the entities
class EntityList
{
private:
	std::vector<std::shared_ptr<Entity>> m_entityList;
	std::vector<int> m_deleteList;

public:
	EntityList() {};
	void updateAllEntities(float deltaTime);
	void lateUpdateAllEntities(float deltaTime);
	void renderAllEntities();
	void add(std::shared_ptr<Entity> entity);
	std::vector<std::shared_ptr<Entity>> getList();

private:
	void lateUpdateAllEntities();
};
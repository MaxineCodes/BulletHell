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

#include "Entity.h"


// Class containing all the entities
class EntityList
{
private:
	std::vector<std::shared_ptr<Entity>> m_entityList;
	std::vector<int> m_deleteList;

public:
	EntityList() {}
	~EntityList() {}

	void update(float deltaTime);
	void lateUpdate(float deltaTime);
	void draw();
	void drawCollisionCircles();

	void add(std::shared_ptr<Entity> entity);
	std::vector<std::shared_ptr<Entity>> getList();
	std::vector<std::shared_ptr<Entity>> getListByType(const char* entityType);
	float getEntityCollisionRadiusByType(const char* entityType);
};
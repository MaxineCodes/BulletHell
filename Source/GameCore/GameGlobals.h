/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	GameGlobals.h
//
//	Description:
//	 Storing global variables and pointers for access throughout the whole application.
//	 These global variables are assigned in the Game class.
//	 Everything is in CAPS to make it easily readable which variables are GLOBAL.
// 
//	 These variables are assigned inside the Game class in the Game.cpp file.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "LevelSystem/SessionState.h"

#include "ResourceManagement/ResourceManager.h"
#include "Rendering/Renderer.h"
#include "EntityList.h"

#include <memory>


extern int GAME_WINDOWWIDTH;
extern int GAME_WINDOWHEIGHT;
extern int GAME_FRAMERATE;

extern std::unique_ptr<SessionState>	GAME_SESSIONSTATE;
extern std::unique_ptr<Renderer>		GAME_RENDERER;
extern std::unique_ptr<ResourceManager> GAME_RESOURCEMANAGER;
extern std::unique_ptr<EntityList>		GAME_ENTITYLIST;
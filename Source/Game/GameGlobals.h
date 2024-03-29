/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	GameGlobals.h
//
//	Description:
//	 Storing global variables and pointers for access throughout the whole application.
//	 These global variables are assigned in the Game class.
//	 Everything is written in CAPS to make it easily readable which variables are GLOBAL.
// 
//	 The compiler complains if the GameGlobals.h is included in the header file.
//	 So we include it in the .cpp file of the file where we want to use the globals instead.
// 
//	 These variables/pointers are assigned inside the Game.cpp file.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <memory>

#include "../Settings/GameSettings.h"
#include "LevelSystem/SessionState.h"
#include "Rendering/Renderer.h"
#include "ResourceManagement/ResourceManager.h"
#include "Entities/EntityList.h"


// Assigned in Game class constructor
extern GameSettings	GAME_SETTINGS;
extern float GAME_SCALE;

// Assigned in Game::initialize
extern std::unique_ptr<SessionState>	GAME_SESSIONSTATE;
extern std::unique_ptr<Renderer>		GAME_RENDERER;
extern std::unique_ptr<ResourceManager> GAME_RESOURCEMANAGER;
extern std::unique_ptr<EntityList>		GAME_ENTITYLIST;
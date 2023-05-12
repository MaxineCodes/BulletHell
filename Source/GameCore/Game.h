/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	[ Game.h ]
//  The main game instance class.
// 
//>------------------------------------------------------------------------------------------
// 
//  Description:  Where the magic happens! It is quite a simple game class, for quite a simple game.
//				  Create an instance of this, and the game should run.
// 
// 
//                Now for a general overview of the game process:
// 				  
//				  Firstly: Initializes the game. 
//                  Used for things like loading resources, also unpacks the game settings.
// 
//				  Secondly: calls mainMenu.
//                  Not implemented yet, but it should be a main menu with a cute graphic
//                  or something like that.
// 
//				  Thirdly(?): calls start.
//                  Start is when the game first begins, duh. Used for things like spawning in
//                  the player, and starting the scripted events. Any main menu stuff should
//                  happen before this, which I plan to implement later!
// 
//				  After that: initiate the game loop.
//                  Game loop calls the update, lateUpdate, and finally render.
//                  The game loop also calculates the deltaTime variable.
//                  [en.wikipedia.org/wiki/Delta_timing]
// 
//                  The update and lateUpdate are called upon the entities in the
//                  gameEntityList, which is basically a stack of all entities currently
//                  in the game. 
// 
//                  The render works a little differenty, taking all sprites out of the
//                  entities in the gameEntityList, and rendering them on screen.
//                  For more explanation look in the Renderer.h file.
// 
// 
//>------------------------------------------------------------------------------------------	
// 
//	Functions:    void initialize(GameSettings& settings)
//	     		  void mainMenu();
//	     		  void start();
//	     		  void initializeGameloop();
// 
//>------------------------------------------------------------------------------------------				  
// 				  
//	Input:		  GameSettings: Just a container of variables to start the game with.
//                Later on this could potentially read from a settings file.
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "ResourceManagement/ResourceManager.h"
#include "Rendering/Renderer.h"
#include "EntityList.h"
#include "../Settings/GameSettings.h"


// Game instance
class Game
{
private:
    int m_windowWidth, m_windowHeight;
    int m_framerate;
    std::string m_windowTitle;

    std::shared_ptr<sf::RenderWindow> GameWindow;
    sf::VideoMode VideoMode;

    std::unique_ptr<Renderer> m_gameRenderer;
    ResourceManager m_resourceManager;
    EntityList m_gameEntityList;

public:
    Game(GameSettings& settings);
    ~Game() {}

private:
    void initialize(GameSettings& settings);
    void mainMenu();
    void start();
    void initializeGameloop();
};
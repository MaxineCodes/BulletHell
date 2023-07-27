/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	GameSettings.h
//
//	Description:
//	 Just a container for settings variables to pass to the game instance constructor.
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class KeyBinds
{
public:
    // Keybinds
    static const auto MOVE_LEFT = sf::Keyboard::Left;
    static const auto MOVE_RIGHT = sf::Keyboard::Right;
    static const auto MOVE_UP = sf::Keyboard::Up;
    static const auto MOVE_DOWN = sf::Keyboard::Down;
    static const auto SHOOT = sf::Keyboard::X;
    static const auto SLOW = sf::Keyboard::Z;
    static const auto SPECIAL = sf::Keyboard::C;
    static const auto BOMB = sf::Keyboard::V;
    static const auto PAUSE = sf::Keyboard::Escape;
    static const auto AFFIRM = sf::Keyboard::Space;
    static const auto CANCEL = sf::Keyboard::Backspace;
};


class GameSettings
{
public:
    // Application window
    static constexpr const char* WINDOWTITLE = "BulletHell Game";
    static const int WINDOWHEIGHT_TARGET = 1440; // assuming 720
    static const int WINDOWWIDTH = int(WINDOWHEIGHT_TARGET / 3*4); // 720:576
    static const int WINDOWHEIGHT = WINDOWHEIGHT_TARGET;

    // Playable game area
    static const int GAME_WINDOWWIDTH = int(WINDOWHEIGHT_TARGET / 4*3); // 720:480
    static const int GAME_WINDOWHEIGHT = WINDOWHEIGHT_TARGET;

    // Game options
    static const int FRAMERATE = 60;
    static const bool AUDIO_ENABLED = true;

    // Debug options
    static const bool DEBUG_COLLISION_CIRCLES = false;
    static const bool DEBUG_INVINCIBLE = false;

    // Keybinds
    KeyBinds KEYBINDS;

public:
    void print()
    {
        std::cout << "WINDOWTITLE="         << WINDOWTITLE << std::endl;
        std::cout << "WINDOWHEIGHT_TARGET=" << WINDOWHEIGHT_TARGET << std::endl;
        std::cout << "WINDOWWIDTH="         << WINDOWWIDTH << std::endl;
        std::cout << "WINDOWHEIGHT="        << WINDOWHEIGHT << std::endl;
        std::cout << "GAME_WINDOWWIDTH="    << GAME_WINDOWWIDTH << std::endl;
        std::cout << "GAME_WINDOWHEIGHT="   << GAME_WINDOWHEIGHT << std::endl;
        std::cout << "FRAMERATE="           << FRAMERATE << std::endl;

        if(AUDIO_ENABLED)           std::cout << "AUDIO_ENABLED=TRUE" << std::endl;
        else                        std::cout << "AUDIO_ENABLED=FALSE" << std::endl;

        if(DEBUG_COLLISION_CIRCLES) std::cout << "DEBUG_COLLISION_CIRCLES=TRUE" << std::endl;
        else                        std::cout << "DEBUG_COLLISION_CIRCLES=FALSE" << std::endl;

        if(DEBUG_INVINCIBLE)        std::cout << "DEBUG_INVINCIBLE=TRUE" << std::endl;
        else                        std::cout << "DEBUG_INVINCIBLE=FALSE" << std::endl;
    }
};
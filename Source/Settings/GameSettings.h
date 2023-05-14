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
};
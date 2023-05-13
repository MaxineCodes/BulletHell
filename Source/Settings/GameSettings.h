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
    // Window
    static constexpr const char* WINDOWTITLE = "BulletHell Game";
    static const int WINDOWHEIGHT_TARGET = 720;
    static const int WINDOWWIDTH = int(WINDOWHEIGHT_TARGET / 1.5); // 480
    static const int WINDOWHEIGHT = WINDOWHEIGHT_TARGET;
    static const int FRAMERATE = 60;
    // Audio
    static const bool AUDIO_ENABLED = true;
};
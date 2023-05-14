/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	LevelState.h
//
//	Description:
//	 Interface for level state functionality, such as:
//	 ・Keeping track of boss hp
//	 ・Keeping track of enemies killed
//	 ・Starting scripted game events
//	 ・Deciding when to move to the next level
//	
//	 Also interfaces with the session state
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>



class LevelState
{
private:
	const char* m_backgroundTexture = "PurpleSpaceBackground.png";

public:
	const char* getBackgroundTextureName();
};


/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	SessionState.h
//
//	Description:
//	 The session state is responsible for:
//	 ・Keeping track of total enemies killed over the game session.
//	 ・Keeping a counter of score over the session.
//	 ・Keeping track of the player lives.
//	 ・Starting the next levels.
//	
//	 The session is stored as a global pointer, as many entities will access it.
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "LevelState.h"


class SessionState
{
public:
	unsigned int m_playerLives = 3;
	unsigned int m_score = 0;
	unsigned int m_enemyKillCount = 0;

public:
	//void playerHit();
	//void enemyKilled();
};


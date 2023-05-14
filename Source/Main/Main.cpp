/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	- B U L L E T   H E L L   G A M E -
//	   ~ Inspired by Touhou [東方] ~
//
//	A simple SFML game where you dodge bullets.
// 
//>------------------------------------------------------------------------------------------
// 
//  Description:  An experiment on writing a simple 2D game, just to see what it takes.
//                Fast majority of the heavy lifting is done by the SFML library. 
// 
//                Most sprites were made by myself in Aseprite, the character sprites
//                are based on the pixelated Touhou characters found in the Nintendo Switch
//                version of the arcade game Groove Coaster.
// 
//                This bullethell game will include scripted events, levels with variable difficulty, 
//                and a simple UI.
// 
// 
//  Dependencies: *SFML
//	
// 
//  Further Info: The Github Readme contains more information about my process.
//                https://en.wikipedia.org/wiki/Touhou_Project for info on Touhou [東方]
// 
//>------------------------------------------------------------------------------------------
//  
//  Starting date: 11/05/2023 
//
//  Previous name ideas: 西部;弟月響曲の流星   西部;墜落月交響曲   西部;永夜空   西部;不変永
//
//  
//	Credits: Maxine Meijboom
//           [github.com/MaxineCodes]
//           [linkedin.com/in/maxinemeijboom]
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#include "../Game/Game.h"

int main()
{
    // Start the game instance
    GameSettings Settings;
    Game GameApp(Settings);

    return 0;
}
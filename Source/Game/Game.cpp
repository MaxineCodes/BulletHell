#include "Game.h"

// Game globals
// Accessed through GameGlobals.h
int APPLICATION_WINDOWWIDTH;
int APPLICATION_WINDOWHEIGHT;
int GAME_WINDOWWIDTH;
int GAME_WINDOWHEIGHT;
int GAME_FRAMERATE;
int GAME_SCALE;

std::unique_ptr<Renderer>        GAME_RENDERER;
std::unique_ptr<ResourceManager> GAME_RESOURCEMANAGER;
std::unique_ptr<EntityList>      GAME_ENTITYLIST;
std::unique_ptr<SessionState>    GAME_SESSIONSTATE;


Game::Game(GameSettings& settings)
{
    APPLICATION_WINDOWWIDTH = settings.WINDOWWIDTH;
    APPLICATION_WINDOWHEIGHT = settings.WINDOWHEIGHT;
    GAME_WINDOWWIDTH = settings.GAME_WINDOWWIDTH;
    GAME_WINDOWHEIGHT = settings.GAME_WINDOWHEIGHT;
    GAME_FRAMERATE = settings.FRAMERATE;
    GAME_SCALE = 1;

    // Debug prints
    std::cout << "APPLICATION_WINDOWWIDTH=" << APPLICATION_WINDOWWIDTH << std::endl;
    std::cout << "APPLICATION_WINDOWHEIGHT=" << APPLICATION_WINDOWHEIGHT << std::endl;
    std::cout << "GAME_WINDOWWIDTH=" << GAME_WINDOWWIDTH << std::endl;
    std::cout << "GAME_WINDOWHEIGHT=" << GAME_WINDOWHEIGHT << std::endl;
    std::cout << "GAME_FRAMERATE=" << GAME_FRAMERATE << std::endl;
    std::cout << "GAME_SCALE=" << GAME_SCALE << std::endl;

    std::cout << "Creating Game render window" << std::endl;
    sf::VideoMode VideoMode(APPLICATION_WINDOWWIDTH, APPLICATION_WINDOWHEIGHT);
    m_gameWindow = std::make_shared<sf::RenderWindow>(VideoMode, settings.WINDOWTITLE);

    std::cout << "Initializing: GAME_RESOURCEMANAGER" << std::endl;
    GAME_RESOURCEMANAGER = std::make_unique<ResourceManager>();
    if (!GAME_RESOURCEMANAGER->loadResources())
        std::cout << " ERROR: Loading resources failed" << std::endl;

    std::cout << "Initializing: GAME_SESSIONSTATE" << std::endl;
    GAME_SESSIONSTATE = std::make_unique<SessionState>();

    std::cout << "Initializing: GAME_ENTITYLIST" << std::endl;
    GAME_ENTITYLIST = std::make_unique<EntityList>();

    std::cout << "Initializing: GAME_RENDERER" << std::endl;
    GAME_RENDERER = std::make_unique<Renderer>(m_gameWindow);

    std::cout << "Starting Game" << std::endl;
    mainMenu();
    start();
    initializeGameloop();
}


// Initializes the game
void Game::initialize(GameSettings& settings)
{

}


// Fancy main menu :)
void Game::mainMenu()
{

}


// Called before the first update
void Game::start()
{
    auto player = std::make_shared<Player>();
    GAME_ENTITYLIST->add(player);

    const float startPositionX = static_cast<float>(GAME_WINDOWWIDTH) / 2 * 1; // 2:1 ratio
    const float startPositionY = static_cast<float>(GAME_WINDOWHEIGHT) / 5 * 1; // 5:1 ratio

    auto enemy1 = std::make_shared<Destroyer>(Vector2(startPositionX, startPositionY));
    GAME_ENTITYLIST->add(enemy1);
}


void Game::initializeGameloop()
{
    sf::Event Event;
    sf::Time dt;
    sf::Clock deltaClock;

    // Loop di loop
    while (m_gameWindow->isOpen())
    {
        // Poll for game closed
        while (m_gameWindow->pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                m_gameWindow->close();
        }

        // Calculate delta time
        dt = deltaClock.restart();
        float deltaTime = float(dt.asMilliseconds());
        deltaTime = 1;

        // Update
        GAME_ENTITYLIST->updateAllEntities(deltaTime);

        // Late update
        GAME_ENTITYLIST->lateUpdateAllEntities(deltaTime);

        // And of course, render
        GAME_RENDERER->render();
    }
}
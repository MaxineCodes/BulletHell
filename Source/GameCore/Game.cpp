#include "Game.h"

// Game globals
// Accessed through GameGlobals.h
int GAME_WINDOWWIDTH;
int GAME_WINDOWHEIGHT;
int GAME_FRAMERATE;

std::unique_ptr<Renderer>        GAME_RENDERER;
std::unique_ptr<ResourceManager> GAME_RESOURCEMANAGER;
std::unique_ptr<EntityList>      GAME_ENTITYLIST;
std::unique_ptr<SessionState>    GAME_SESSIONSTATE;


Game::Game(GameSettings& settings)
{
    GAME_WINDOWWIDTH = settings.WINDOWWIDTH;
    GAME_WINDOWHEIGHT = settings.WINDOWHEIGHT;
    GAME_FRAMERATE = settings.FRAMERATE;

    // Debug prints
    std::cout << "WINDOWHEIGHT=" << GAME_WINDOWWIDTH << std::endl;
    std::cout << "WINDOWWIDTH=" << GAME_WINDOWHEIGHT << std::endl;
    std::cout << "FRAMERATE=" << GAME_FRAMERATE << std::endl;

    initialize(settings);
}


// Initializes the game
void Game::initialize(GameSettings& settings)
{
    std::cout << "Game::initialize()" << std::endl;

    std::cout << "Creating Game render window" << std::endl;
    sf::VideoMode VideoMode(GAME_WINDOWWIDTH, GAME_WINDOWHEIGHT);
    m_gameWindow = std::make_shared<sf::RenderWindow>(VideoMode, settings.WINDOWTITLE);

    std::cout << "Initializing: GAME_RENDERER" << std::endl;
    GAME_RENDERER = std::make_unique<Renderer>(m_gameWindow);

    std::cout << "Initializing: GAME_RESOURCEMANAGER" << std::endl;
    GAME_RESOURCEMANAGER = std::make_unique<ResourceManager>();
    if (!GAME_RESOURCEMANAGER->loadResources())
        std::cout << " ERROR: Loading resources failed" << std::endl;

    std::cout << "Initializing: GAME_SESSIONSTATE" << std::endl;
    GAME_SESSIONSTATE = std::make_unique<SessionState>();

    std::cout << "Initializing: GAME_ENTITYLIST" << std::endl;
    GAME_ENTITYLIST = std::make_unique<EntityList>();

    std::cout << "Starting Game" << std::endl;
    mainMenu();
    start();
    initializeGameloop();
}


// Fancy main menu :)
void Game::mainMenu()
{

}


// Called before the first update
void Game::start()
{
    std::cout << "Game::start()" << std::endl;

    auto player = std::make_shared<Player>();
    GAME_ENTITYLIST->add(player);
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
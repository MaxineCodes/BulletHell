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

    // Create Render Window
    sf::VideoMode VideoMode(GAME_WINDOWWIDTH, GAME_WINDOWHEIGHT);
    m_gameWindow = std::make_shared<sf::RenderWindow>(VideoMode, settings.WINDOWTITLE);

    // Initialize the renderer
    GAME_RENDERER = std::make_unique<Renderer>(&m_gameEntityList, m_gameWindow, GAME_WINDOWWIDTH, GAME_WINDOWHEIGHT);

    // Initialize the resource manager
    GAME_RESOURCEMANAGER = std::make_unique<ResourceManager>();
    if (!GAME_RESOURCEMANAGER->loadResources())
        std::cout << "Loading resources failed" << std::endl;

    // Initialize the resource manager
    if (!m_resourceManager.loadResources())
        std::cout << "Loading resources failed" << std::endl;

    // Start the game related stuff
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

    auto player = std::make_shared<Player>(&m_gameEntityList, &m_resourceManager);
    m_gameEntityList.add(player);
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
        m_gameEntityList.updateAllEntities(deltaTime);

        // Late update
        m_gameEntityList.lateUpdateAllEntities(deltaTime);

        // And of course, render
        GAME_RENDERER->render();
    }
}
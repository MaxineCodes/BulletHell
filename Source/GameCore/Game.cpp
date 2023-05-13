#include "Game.h"

// Game globals
// Accessed through GameGlobals.h
int GAME_WINDOWWIDTH;
int GAME_WINDOWHEIGHT;
std::unique_ptr<SessionState> GAME_SESSIONSTATE;


Game::Game(GameSettings& settings)
{
    m_windowWidth = settings.WINDOWWIDTH;
    m_windowHeight = settings.WINDOWHEIGHT;
    m_framerate = settings.FRAMERATE;
    m_windowTitle = settings.WINDOWTITLE;

    GAME_WINDOWWIDTH = settings.WINDOWWIDTH;
    GAME_WINDOWHEIGHT = settings.WINDOWHEIGHT;

    // Debug prints
    std::cout << "WINDOWHEIGHT=" << m_windowWidth << std::endl;
    std::cout << "WINDOWWIDTH=" << m_windowHeight << std::endl;
    std::cout << "FRAMERATE=" << m_framerate << std::endl;

    initialize(settings);
}


// Initializes the game
void Game::initialize(GameSettings& settings)
{
    std::cout << "Game::initialize()" << std::endl;

    // Create Render Window
    VideoMode = sf::VideoMode(m_windowWidth, m_windowHeight);
    GameWindow = std::make_shared<sf::RenderWindow>(VideoMode, m_windowTitle);

    // Initialize the renderer
    m_gameRenderer = std::make_unique<Renderer>(&m_gameEntityList, GameWindow, m_windowWidth, m_windowHeight);
    //GAME_SESSIONSTATE = m_gameRenderer;

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
    while (GameWindow->isOpen())
    {
        // Poll for game closed
        while (GameWindow->pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                GameWindow->close();
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
        m_gameRenderer->render();
    }
}
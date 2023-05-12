#include "Game.h"


Game::Game(GameSettings& settings)
{
    m_windowWidth = settings.WINDOWWIDTH;
    m_windowHeight = settings.WINDOWHEIGHT;
    m_framerate = settings.FRAMERATE;
    m_windowTitle = settings.WINDOWTITLE;

    // Debug prints
    std::cout << "WINDOWHEIGHT=" << m_windowWidth << std::endl;
    std::cout << "WINDOWWIDTH=" << m_windowHeight << std::endl;
    std::cout << "FRAMERATE=" << m_framerate << std::endl;

    initialize(settings);
}

Game::~Game()
{

}

// Initializes the game
void Game::initialize(GameSettings& settings)
{
    std::cout << "Game::initialize()" << std::endl;

    // Create Render Window
    VideoMode = sf::VideoMode(m_windowWidth, m_windowHeight);
    GameWindow = std::make_unique<sf::RenderWindow>(VideoMode, m_windowTitle);
    m_renderLayers = std::make_unique<RenderLayers>(*GameWindow, m_windowWidth, m_windowHeight);

    // Initialize the game manager
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

    auto player = std::make_shared<Player>(m_windowWidth, m_windowHeight, &m_gameEntityList, &m_resourceManager);
    m_gameEntityList.add(player);
}
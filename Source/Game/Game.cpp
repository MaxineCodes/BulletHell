#include "Game.h"

// Game globals
// Accessed through GameGlobals.h
float GAME_SCALE;
GameSettings GAME_SETTINGS;
std::unique_ptr<Renderer>        GAME_RENDERER;
std::unique_ptr<ResourceManager> GAME_RESOURCEMANAGER;
std::unique_ptr<EntityList>      GAME_ENTITYLIST;
std::unique_ptr<SessionState>    GAME_SESSIONSTATE;


Game::Game(GameSettings& settings)
{

    GAME_SETTINGS = settings;
    // Debug prints
    settings.print();

    GAME_SCALE = float(GAME_SETTINGS.WINDOWHEIGHT) / float(1440);
    std::cout << "GAME_SETTINGS.WINDOWHEIGHT=" << GAME_SETTINGS.WINDOWHEIGHT << std::endl;
    std::cout << "GAME_SCALE=" << GAME_SCALE << std::endl;

    std::cout << "Creating Game render window" << std::endl;
    sf::VideoMode VideoMode(GAME_SETTINGS.WINDOWWIDTH, GAME_SETTINGS.WINDOWHEIGHT);
    m_gameWindow = std::make_shared<sf::RenderWindow>(VideoMode, GAME_SETTINGS.WINDOWTITLE);

    std::cout << "Initializing: GAME_RESOURCEMANAGER" << std::endl;
    GAME_RESOURCEMANAGER = std::make_unique<ResourceManager>();
    if (!GAME_RESOURCEMANAGER->loadResources())
        std::cout << "[ ! ] ERROR: Loading resources failed" << std::endl;

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


// Fancy main menu :)
void Game::mainMenu()
{
    std::cout << "Starting Main Menu" << std::endl;

    sf::Sprite mainMenuSprite;
    sf::Texture mainMenuTexture = GAME_RESOURCEMANAGER->getTexture("MainMenu.png");
    mainMenuSprite.setPosition(0.0f, 0.0f);
    mainMenuSprite.setScale(30 * GAME_SCALE, 30 * GAME_SCALE);
    mainMenuSprite.setTexture(mainMenuTexture);

    //// Repeat until space is pressed
    while(!sf::Keyboard::isKeyPressed(GAME_SETTINGS.KEYBINDS.AFFIRM))
    {
        GAME_RENDERER->clear(sf::Color::Magenta);
        GAME_RENDERER->draw(mainMenuSprite);
        GAME_RENDERER->display();
    }

    std::cout << "Space pressed, exiting main menu and moving on to the game" << std::endl;
    GAME_RENDERER->clear(sf::Color::Magenta);
}


// Called before the first update
void Game::start()
{
    auto player = std::make_shared<Player>();
    GAME_ENTITYLIST->add(player);

    const float startPositionX = static_cast<float>(GAME_SETTINGS.WINDOWWIDTH) / 2 * 1; // 2:1 ratio , middle
    const float startPositionY = static_cast<float>(GAME_SETTINGS.WINDOWHEIGHT) / 5 * 1; // 5:1 ratio , somewhere close to the bottom

    auto enemy1 = std::make_shared<Destroyer>(Vector2(startPositionX, startPositionY));
    GAME_ENTITYLIST->add(enemy1);

    
    //auto testBullet = std::make_shared<Bullet>(Vector2(startPositionX, startPositionX), Vector2(), 0.0f, 5, "BulletPointBlue.png");
    //GAME_ENTITYLIST->add(testBullet);
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
        //dt = deltaClock.restart();
        float deltaTime = deltaClock.restart().asSeconds();
        //std::cout << "FRAME TIME: " << deltaTime << std::endl;
        deltaTime = deltaTime * 10000; // Multiply it by ten thousand so the numbers we tweak need to in code aren't insanely big.
        deltaTime = deltaTime * GAME_SCALE; // Multiply by game scale, so movement is 0.5x the speed if the game is 0.5x the size.

        // Update
        GAME_ENTITYLIST->update(deltaTime);
        GAME_ENTITYLIST->lateUpdate(deltaTime);

        // Render
        GAME_RENDERER->render();
    }
}
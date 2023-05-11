#include <SFML/Graphics.hpp>

#include "Game.h"


void Game::initializeGameloop()
{
    sf::Event Event;
    sf::Time dt;
    sf::Clock deltaClock;

    while (GameWindow->isOpen())
    {
        // Poll for game closed
        while (GameWindow->pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                GameWindow->close();
            }
        }

        // Calculate delta time
        dt = deltaClock.restart();
        float deltaTime = float(dt.asMilliseconds());
        deltaTime = 1;

        update(deltaTime);
        lateUpdate(deltaTime);
        render();
    }
}

// Process game here
void Game::update(float deltaTime)
{
    sf::Event Event;

    // Poll for game closed
    while (GameWindow->pollEvent(Event))
    {
        if (Event.type == sf::Event::Closed)
        {
            GameWindow->close();
        }
    }

    gameEntityList.updateAllEntities(deltaTime);
}


void Game::lateUpdate(float deltaTime)
{

}


void Game::render()
{
    // Reset canvas
    GameWindow->clear(sf::Color::Black);

    // Render all entities
    for (auto entity : gameEntityList.getList())
    {
        GameWindow->draw(entity->getSprite());
    }

    // Display new frame
    GameWindow->display();
}
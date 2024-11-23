#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int PLAYER_WIDTH = 50;
const int PLAYER_HEIGHT = 50;
const int FALLING_OBJECT_WIDTH = 40;
const int FALLING_OBJECT_HEIGHT = 40;
const int PLAYER_SPEED = 5;
const float SPAWN_RATE = 0.02f; // 2% chance per frame to spawn an object

// Class to represent the falling objects
class FallingObject : public sf::RectangleShape
{
public:
    FallingObject(float x, float y)
    {
        setSize(sf::Vector2f(FALLING_OBJECT_WIDTH, FALLING_OBJECT_HEIGHT));
        setFillColor(sf::Color::Red);
        setPosition(x, y);
        speed = rand() % 5 + 3; // Random speed between 3 and 7
    }

    void update()
    {
        move(0, speed); // Move the object down
    }

    bool isOutOfBounds()
    {
        return getPosition().y > WINDOW_HEIGHT;
    }

private:
    float speed;
};

// Class to represent the player
class Player : public sf::RectangleShape
{
public:
    Player(float x, float y)
    {
        setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
        setFillColor(sf::Color::Blue);
        setPosition(x, y);
    }

    void update()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getPosition().x > 0)
        {
            move(-PLAYER_SPEED, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && getPosition().x < WINDOW_WIDTH - PLAYER_WIDTH)
        {
            move(PLAYER_SPEED, 0);
        }
    }
};

// Class to manage the game logic
class Game
{
public:
    Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Catch the Falling Objects"), score(0), player(WINDOW_WIDTH / 2 - PLAYER_WIDTH / 2, WINDOW_HEIGHT - PLAYER_HEIGHT - 10)
    {
        window.setFramerateLimit(60);
    }

    void run()
    {
        sf::Clock clock;

        while (window.isOpen())
        {
            handleEvents();
            update();
            render();
            sf::Time deltaTime = clock.restart();
        }
    }

private:
    sf::RenderWindow window;
    Player player;
    std::vector<FallingObject> fallingObjects;
    int score;

    void handleEvents()
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    void update()
    {
        // Spawn new falling objects
        if (rand() / float(RAND_MAX) < SPAWN_RATE)
        {
            fallingObjects.push_back(FallingObject(rand() % (WINDOW_WIDTH - FALLING_OBJECT_WIDTH), -FALLING_OBJECT_HEIGHT));
        }

        // Update player and falling objects
        player.update();

        // Update falling objects and check for collisions
        for (auto it = fallingObjects.begin(); it != fallingObjects.end();)
        {
            it->update();

            // Check for collision with the player
            if (it->getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                score++;
                it = fallingObjects.erase(it); // Remove object when caught
            }
            else if (it->isOutOfBounds())
            {
                it = fallingObjects.erase(it); // Remove object if out of bounds
            }
            else
            {
                ++it;
            }
        }
    }

    void render()
    {
        window.clear(sf::Color::White);

        // Draw player and falling objects
        window.draw(player);
        for (const auto &obj : fallingObjects)
        {
            window.draw(obj);
        }

        // Display score
        sf::Font font;
        if (!font.loadFromFile("arial.ttf"))
        {
            std::cerr << "Error loading font!" << std::endl;
            return;
        }
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setString("Score: " + std::to_string(score));
        scoreText.setCharacterSize(30);
        scoreText.setFillColor(sf::Color::Black);
        scoreText.setPosition(10.f, 10.f);
        window.draw(scoreText);

        window.display();
    }
};

int main()
{
    srand(time(0)); // Seed for random number generation

    Game game;
    game.run();

    return 0;
}

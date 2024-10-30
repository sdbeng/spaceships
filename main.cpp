#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

// window dimensions
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// player dimensions
const int PLAYER_WIDTH = 50;
const int PLAYER_HEIGHT = 50;

// player speed
const float PLAYER_SPEED = 0.1f; // if set to -5.0f, the player will move to the left

// player jump speed
const float PLAYER_JUMP_SPEED = 0.2f;

int main()
{
    // create window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Spaceship Game");

    // Load spaceship texture
    sf::Texture spaceshipTexture;
    if (!spaceshipTexture.loadFromFile("spaceship.png"))
    {
        std::cerr << "Error loading spaceship texture" << std::endl;
        return 1;
    }

    // Create spaceship sprite
    sf::Sprite spaceship(spaceshipTexture);
    spaceship.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    spaceship.setScale(0.5f, 0.5f); // scale down the spaceship

    // Load star and planet textures
    sf::Texture starTexture;
    if (!starTexture.loadFromFile("star.png"))
    {
        std::cerr << "Error loading star texture" << std::endl;
        return 1;
    }
    sf::Sprite star(starTexture);
    star.setPosition(100, 100);

    sf::Texture planetTexture;
    if (!planetTexture.loadFromFile("planet.png"))
    {
        std::cerr << "Error loading planet texture" << std::endl;
        return 1;
    }
    sf::Sprite planet(planetTexture);
    planet.setPosition(500, 400);

    // Load sound effect
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("laser_sound.wav"))
    {
        std::cerr << "Error loading sound effect" << std::endl;
        return 1;
    }
    sf::Sound laserSound;
    laserSound.setBuffer(buffer);

    // load background music
    sf::Music music;
    if (!music.openFromFile("background_music.ogg"))
    {
        std::cerr << "Error loading background music" << std::endl;
        return 1;
    }
    music.setLoop(true);
    music.play();

    // Game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Movement ctrl, spaceship
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            spaceship.move(0, -5);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                spaceship.move(0, 5);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                spaceship.move(-5, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                spaceship.move(5, 0);
            }
            // laser sound
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                laserSound.play();
            }

            // Rendering
            window.clear();
            window.draw(spaceship);
            window.draw(star);
            window.draw(planet);
            window.display();
        }
        return 0; // exit success
    }
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread> // For sleep_for
#include <chrono> // For std::chrono::seconds

// window dimensions
// const int WINDOW_WIDTH = 800;
// const int WINDOW_HEIGHT = 600;

int main()
{
    try
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Spaceship Game");

        std::cout << "Window created successfully" << std::endl;
        sf::sleep(sf::seconds(2));

        // Step 1: Load spaceship texture only
        sf::Texture spaceshipTexture;
        if (!spaceshipTexture.loadFromFile("resources/spaceship.png"))
        {
            std::cerr << "Error loading spaceship texture\n";
            return -1;
        }
        std::cout << "Loaded spaceship texture successfully\n";

        // Create a sprite for the spaceship and set its position
        sf::Sprite spaceship(spaceshipTexture);
        spaceship.setPosition(400, 300); // Center it, or adjust as needed

        // Load star and planet textures
        sf::Texture starTexture;
        if (!starTexture.loadFromFile("resources/star.png"))
        {
            std::cerr << "Error loading star texture\n";
            return -1;
        }
        std::cout << "Loaded star successfully\n";
        sf::Sprite star(starTexture);
        star.setPosition(100, 100);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    std::cout << "Close event detected" << std::endl;
                    window.close();
                }
            }
            window.clear();
            window.draw(spaceship); // Draw the spaceship sprite
            window.draw(star);      // Draw the star sprite
            window.display();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}

// player dimensions
// const int PLAYER_WIDTH = 50;
// const int PLAYER_HEIGHT = 50;

// player speed
// const float PLAYER_SPEED = 0.1f; // if set to -5.0f, the player will move to the left

// player jump speed
// const float PLAYER_JUMP_SPEED = 0.2f;

// int main()
// {
//     // create window
//     sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Spaceship Game");

//     // Load spaceship texture
//     sf::Texture spaceshipTexture;
//     if (!spaceshipTexture.loadFromFile("resources/spaceship.png"))
//     {
//         std::cerr << "Error loading spaceship texture\n";
//         return -1;
//     }

//     std::cout << "Loaded spaceship texture successfully\n";
//     // Create spaceship sprite
//     sf::Sprite spaceship(spaceshipTexture);
//     spaceship.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
//     spaceship.setScale(0.5f, 0.5f); // scale down the spaceship

//     // Load star and planet textures
//     sf::Texture starTexture;
//     if (!starTexture.loadFromFile("resources/star.png"))
//     {
//         std::cerr << "Error loading star texture\n";
//         return -1;
//     }
//     std::cout << "Loaded star texture successfully\n";
//     sf::Sprite star(starTexture);
//     star.setPosition(100, 100);

//     sf::Texture planetTexture;
//     if (!planetTexture.loadFromFile("resources/planet.png"))
//     {
//         std::cerr << "Error loading planet texture" << std::endl;
//         return -1;
//     }
//     sf::Sprite planet(planetTexture);
//     planet.setPosition(300, 300);
//     std::cout << "Loaded planet texture successfully\n";

//     // Load sound effect
//     sf::SoundBuffer buffer;
//     if (!buffer.loadFromFile("resources/laser.ogg"))
//     {
//         std::cerr << "Error loading sound effect\n"
//                   << std::endl;
//         return -1;
//     }
//     sf::Sound laserSound;
//     laserSound.setBuffer(buffer);
//     std::cout << "Loaded laser sound successfully\n";

//     // load background music
//     sf::Music music;
//     if (!music.openFromFile("resources/background_music.ogg"))
//     {
//         std::cerr << "Error loading background music\n"
//                   << std::endl;
//         return -1;
//     }
//     std::cout << "Loaded backgrnd music successfully\n";
//     music.setLoop(true);
//     music.play();

//     std::this_thread::sleep_for(std::chrono::seconds(2)); // Add a 2-second delay

//     // Game loop
//     while (window.isOpen())
//     {
//         std::cout << "In outer while loop...: \n";
//         // Process events
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             // Log the event type for debugging
//             std::cout << "Event type: " << event.type << std::endl;
//             // if (event.type == sf::Event::Closed)
//             // {
//             //     window.close();
//             // }
//             switch (event.type)
//             {
//             case sf::Event::Closed:
//                 std::cout << "Event: Window Close Request" << std::endl;
//                 window.close();
//                 break;
//             case sf::Event::KeyPressed:
//                 std::cout << "Event: Key Pressed" << std::endl;
//                 break;
//             case sf::Event::KeyReleased:
//                 std::cout << "Event: Key Released" << std::endl;
//                 break;
//             case sf::Event::MouseButtonPressed:
//                 std::cout << "Event: Mouse Button Pressed" << std::endl;
//                 break;
//             case sf::Event::MouseButtonReleased:
//                 std::cout << "Event: Mouse Button Released" << std::endl;
//                 break;
//             default:
//                 std::cout << "Event type: " << event.type << " (Other event)" << std::endl;
//                 break;
//             }
//         }

//         // Movement ctrl, spaceship
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//         {
//             spaceship.move(0, -5);
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//             {
//                 spaceship.move(0, 5);
//             }
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//             {
//                 spaceship.move(-5, 0);
//             }
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//             {
//                 spaceship.move(5, 0);
//             }
//             // laser sound
//             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//             {
//                 laserSound.play();
//             }

//             // Rendering
//             window.clear();
//             window.draw(spaceship);
//             window.draw(star);
//             window.draw(planet);
//             window.display();
//         }
//         return 0; // exit success
//     }
// }
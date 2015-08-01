#include <SFML/Graphics.hpp>
#include <tmx/MapLoader.h>
#include <Thor/Animations.hpp>

int main()
{

    tmx::MapLoader tl("assets/");
    tl.Load("world.tmx");

    sf::RenderWindow window(sf::VideoMode(tl.GetMapSize().x, tl.GetMapSize().y), "GameWindow");
    window.setFramerateLimit(60);

    sf::Image image;
    image.loadFromFile("assets/player.png");

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite spPlayer(texture);
    spPlayer.setPosition(100.f, 100.f);

    thor::FrameAnimation walk_down;
    walk_down.addFrame(1.f, sf::IntRect(0,0,32,32));
    walk_down.addFrame(1.f, sf::IntRect(32,0,32,32));
    walk_down.addFrame(1.f, sf::IntRect(64,0,32,32));


    thor::FrameAnimation walk_left;
    walk_left.addFrame(1.f, sf::IntRect(0,32,32,32));
    walk_left.addFrame(1.f, sf::IntRect(32,32,32,32));
    walk_left.addFrame(1.f, sf::IntRect(64,32,32,32));

    thor::FrameAnimation walk_right;
    walk_right.addFrame(1.f, sf::IntRect(0,64,32,32));
    walk_right.addFrame(1.f, sf::IntRect(32,64,32,32));
    walk_right.addFrame(1.f, sf::IntRect(64,64,32,32));

    thor::FrameAnimation walk_up;
    walk_up.addFrame(1.f, sf::IntRect(0,96,32,32));
    walk_up.addFrame(1.f, sf::IntRect(32,96,32,32));
    walk_up.addFrame(1.f, sf::IntRect(64,96,32,32));

    thor::FrameAnimation stand;
    stand.addFrame(1.f, sf::IntRect(32,0,32,32));

    thor::Animator<sf::Sprite, std::string> animator;
    animator.addAnimation("walk_down", walk_down, sf::seconds(.5f));
    animator.addAnimation("walk_left", walk_left, sf::seconds(.5f));
    animator.addAnimation("walk_right", walk_right, sf::seconds(.5f));
    animator.addAnimation("walk_up", walk_up, sf::seconds(.5f));
    animator.addAnimation("stand", stand, sf::seconds(.5f));


    animator.playAnimation("stand");

    sf::Clock frameClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
            {
                    return 0;
            }
        }


        window.clear();
        window.draw(tl);

        animator.animate(spPlayer);
        animator.update(frameClock.restart());
        window.draw(spPlayer);

        window.display();
    };

    return 0;
}

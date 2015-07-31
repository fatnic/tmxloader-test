#include <SFML/Graphics.hpp>
#include <tmx/MapLoader.h>

int main()
{

    tmx::MapLoader tl("assets/");
    tl.Load("map.tmx");

    sf::RenderWindow window(sf::VideoMode(tl.GetMapSize().x, tl.GetMapSize().y), "GameWindow");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(tl);
        window.display();
    }

    return 0;
}

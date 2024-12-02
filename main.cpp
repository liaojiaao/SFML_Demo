#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 400), "Example 02",sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape shape(50.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Update
        shape.move(0.2f,0.f);

        //Draw
        window.clear(sf::Color::Red);
        window.draw(shape);
        window.display();
    }

    return 0;
}

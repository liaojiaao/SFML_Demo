#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(640, 400), "Example 05",sf::Style::Default);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
            if(event.type == Event::MouseButtonPressed && Mouse::isButtonPressed(Mouse::Left))
                window.close();
        }
        //Update

        //Draw
        window.clear();

        window.display();
    }

    return 0;
}

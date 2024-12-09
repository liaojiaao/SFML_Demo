#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <ctime>

using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow window(sf::VideoMode(640, 480), "Example 09", sf::Style::Default);
    window.setFramerateLimit(60);

    Texture smileTex;
    Sprite smile;

    if (!smileTex.loadFromFile("../../Pictures/smile.png"))
    {
        throw "can not load smile.png";
    }
    smile.setTexture(smileTex);
    smile.setScale(0.5, 0.5);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        window.clear(Color(125, 200, 125, 200));

        window.draw(smile);

        window.display();
    }

    return 0;
}

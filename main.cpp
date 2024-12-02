#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 400), "Example 02",sf::Style::Default);
    window.setFramerateLimit(60);

    CircleShape circle(50.f);
    RectangleShape rect(Vector2f(50.f,100.f));

    circle.setPosition(Vector2f(0,0));
    rect.setPosition(400,200);

    circle.setFillColor(Color(255,100,200,200));
    rect.setFillColor(Color(100,100,200,200));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Update
        circle.move(0.5,0.2);
        rect.move(-0.5,-0.2);
        rect.rotate(5.f);
        //Draw
        window.clear();

        window.draw(circle);
        window.draw(rect);

        window.display();
    }

    return 0;
}

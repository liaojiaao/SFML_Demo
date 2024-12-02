#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 400), "Example 04",sf::Style::Default);
    window.setFramerateLimit(60);

    CircleShape triangle;
    triangle.setRadius(50);
    triangle.setPointCount(3);
    triangle.setFillColor(Color::Red);
    triangle.setOutlineColor(Color::White);
    triangle.setOutlineThickness(2);

    Vertex line[] = {Vertex(Vector2f(100,400)),Vertex(Vector2f(50,100))};

    ConvexShape convex;
    convex.setPosition(400,200);
    convex.setPointCount(5);
    convex.setPoint(0,Vector2f(0,0));
    convex.setPoint(1,Vector2f(100,0));
    convex.setPoint(2,Vector2f(50,50));
    convex.setPoint(3,Vector2f(100,100));
    convex.setPoint(4,Vector2f(0,100));


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Update

        //Draw
        window.clear();

        window.draw(triangle);
        window.draw(line,2,Lines);
        window.draw(convex);

        window.display();
    }

    return 0;
}

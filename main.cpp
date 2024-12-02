#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

void Update(int &KeyTime,RectangleShape &square,RenderWindow &window);
void Draw(RenderWindow &window,RectangleShape &square);

int main()
{
    int keyTime = 8;
    RenderWindow window(sf::VideoMode(640, 400), "Example 06",sf::Style::Default);
    window.setFramerateLimit(60);

    RectangleShape square(Vector2f(100,100));
    square.setFillColor(Color::Red);
    square.setOrigin(50,50);
    square.setPosition(window.getSize().x/2,window.getSize().y/2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.KeyPressed && event.key.code == Keyboard::Escape)
                window.close();

        }

        Update(keyTime,square,window);
        Draw(window,square);

    }

    return 0;
}

void Update(int &KeyTime,RectangleShape &square,RenderWindow &window)
{
    int timeOut = 1;
    if(KeyTime <timeOut)
    {
        KeyTime++;
        return;
    }
    if(Keyboard::isKeyPressed(Keyboard::A) && square.getPosition().x>0)
    {
        square.move(-5,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::D) && square.getPosition().x< window.getSize().x)
    {
        square.move(5,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::W) && square.getPosition().y>0)
    {
        square.move(0,-5);
    }
    if(Keyboard::isKeyPressed(Keyboard::S) && square.getPosition().y< window.getSize().y)
    {
        square.move(0,5);
    }

    if(Mouse::isButtonPressed(Mouse::Left))
    {
        square.setFillColor(Color::Blue);
    }else
        square.setFillColor(Color::Red);

    if(KeyTime>=timeOut)
        KeyTime=0;

}

void Draw(RenderWindow &window,RectangleShape &square)
{
    window.clear();
    window.draw(square);
    window.display();
}

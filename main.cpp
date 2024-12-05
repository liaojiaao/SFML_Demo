#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{

    RenderWindow window(sf::VideoMode(640, 400), "Example 06", sf::Style::Default);
    window.setFramerateLimit(60);

    CircleShape hoop;
    CircleShape ball;
    int hoopDir = 0;
    float hoopVcc = 1.5;
    int mouseX = 0;
    float ballY = 0;
    float ballAcc = 5;
    bool isShot = false;

    hoop.setRadius(50);
    hoop.setPosition(640 / 2.f, 60);
    hoop.setOrigin(hoop.getRadius(), hoop.getRadius());
    hoop.setFillColor(Color::Black);
    hoop.setOutlineColor(Color::White);
    hoop.setOutlineThickness(2.f);

    ball.setRadius(30);
    ball.setOrigin(ball.getRadius(), ball.getRadius());
    ball.setFillColor(Color::Red);
    ballY = window.getSize().y - ball.getRadius() * 2;
    ball.setPosition(640 / 2.f, ballY);

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
        // Update hoop
        if (hoopDir == 0)
        {
            if (hoop.getPosition().x + hoopVcc < window.getSize().x - hoop.getRadius())
            {
                hoop.move(hoopVcc, 0);
            }
            else
            {
                hoopDir = 1;
            }
        }
        else
        {
            if (hoop.getPosition().x - hoopVcc > hoop.getRadius())
            {
                hoop.move(-hoopVcc, 0);
            }
            else
            {
                hoopDir = 0;
            }
        }

        // update ball by mouse
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            isShot = true;
        }

        if (!isShot)
        {
            mouseX = Mouse::getPosition(window).x;

            if (mouseX < ball.getRadius())
                ball.setPosition(ball.getRadius(), ballY);
            else if (mouseX > window.getSize().x - ball.getRadius())
                ball.setPosition(window.getSize().x - ball.getRadius(), ballY);
            else
                ball.setPosition(mouseX, ballY);
        }

        if (isShot)
        {
            if (ball.getPosition().y < -(ball.getRadius() + 30) || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
            {
                isShot = false;
            }
            ball.move(0, -ballAcc);
        }

        window.clear(Color(125, 200, 125, 200));
        window.draw(hoop);
        window.draw(ball);

        window.display();
    }

    return 0;
}

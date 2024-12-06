#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <ctime>

using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow window(sf::VideoMode(640, 480), "Ball Shooter", sf::Style::Default);
    window.setFramerateLimit(60);

    CircleShape bullet;
    std::vector<CircleShape> vec_bullets;
    RectangleShape enemy;
    std::vector<RectangleShape> enemies;
    CircleShape palyer;

    int shootTimer = 0;
    int bulletCold = 8;
    int enemySpawnTimer = 0;
    int enemyCold = 20;
    float bulletVcc = 5;
    float enemyVcc = 1;
    ulong enemyCount = 8;

    enemy.setFillColor(Color::Red);
    enemy.setSize(Vector2f(40, 30));
    enemy.setOrigin(enemy.getSize().x / 2.f, enemy.getSize().y / 2);

    bullet.setRadius(10);
    bullet.setFillColor(Color::Blue);
    bullet.setOrigin(bullet.getRadius(), bullet.getRadius());

    palyer.setFillColor(Color::Green);
    palyer.setRadius(20);
    palyer.setOrigin(palyer.getRadius(), palyer.getRadius());
    palyer.setPosition(640 / 2.f, 450);

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

        // Update
        // palyer
        palyer.setPosition(Mouse::getPosition(window).x, palyer.getPosition().y);

        if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= bulletCold)
        {
            bullet.setPosition(palyer.getPosition());
            vec_bullets.push_back(CircleShape(bullet));

            shootTimer = 0;
        }

        // bullet
        if (shootTimer < bulletCold)
            shootTimer++;
        for (size_t i = 0; i < vec_bullets.size(); i++)
        {
            vec_bullets[i].move(0, -bulletVcc);

            if (vec_bullets[i].getPosition().y < -bullet.getRadius())
            {
                vec_bullets.erase(vec_bullets.begin() + i);
            }
        }

        // enemy
        if (enemySpawnTimer < enemyCold)
            enemySpawnTimer++;

        if (enemySpawnTimer >= enemyCold && enemies.size() < enemyCount)
        {
            enemySpawnTimer = 0;
            enemy.setPosition(rand() % (int)(window.getSize().x - enemy.getSize().x), -enemy.getSize().y);
            enemies.push_back(RectangleShape(enemy));
        }
        for (size_t i = 0; i < enemies.size(); i++)
        {
            enemies[i].move(0, enemyVcc);

            if (enemies[i].getPosition().y > palyer.getPosition().y + 10)
            {
                enemies.erase(enemies.begin() + i);
            }
        }

        // collision
        for (size_t i = 0; i < enemies.size(); i++)
        {
            if (i >= enemies.size())
                break;
            for (size_t j = 0; j < vec_bullets.size(); j++)
            {
                if (vec_bullets[j].getGlobalBounds().intersects(enemies[i].getGlobalBounds()))
                {
                    vec_bullets.erase(vec_bullets.begin() + j);
                    enemies.erase(enemies.begin() + i);

                    break;
                }
            }
        }

        // Draw
        window.clear(Color(125, 200, 125, 200));

        for (size_t i = 0; i < enemies.size(); i++)
        {
            window.draw(enemies[i]);
        }

        for (size_t i = 0; i < vec_bullets.size(); i++)
        {
            window.draw(vec_bullets[i]);
        }

        window.draw(palyer);

        window.display();
    }

    return 0;
}

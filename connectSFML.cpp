#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <list>
#include <deque>
#include "src/shape/myShape.h"
#include <cmath>


int main()
{
    auto func1 = [](int t)
    {
        sf::Vector2f res;
        res.x = t * t + 4* t + 1;
        res.y = 5 * t;
        return res;
    };

    auto func2 = [](int t)
    {
        sf::Vector2f res;
        res.x = 10 * sin(t / 2);
        res.y =  t;
        return res;
    };
    std::shared_ptr<myShape> ptr_bullet2;
    
    {
        std::shared_ptr<myShape> ptr_bullet = std::make_shared<myShape>(sf::Vector2f(10, 30), sf::Vector2f(300, 50));
        ptr_bullet2 = ptr_bullet;
    }

    sf::RenderWindow window(sf::VideoMode(400, 700), "SFML works!");
    window.setFramerateLimit(60);
    sf::CircleShape shape(50.f);
    shape.setPosition(150, 600);
    shape.setFillColor(sf::Color::Green);

    myShape bullet1(sf::Vector2f(10,30),sf::Vector2f(400, 700), sf::Vector2f(0,50));
    myShape bullet2(sf::Vector2f(10,30), sf::Vector2f(400, 700), sf::Vector2f(300, 50));
    bullet1.SetRule(func1, sf::Vector2f(0, 0));
    bullet2.SetRule(func2, sf::Vector2f(0, 0));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
            }
        }

        ////UPDATE

        bullet1.Update();
        bullet2.Update();

        /// 

        window.clear();
        window.draw(shape);
        window.draw(bullet1);
        window.draw(bullet2);
        window.display();
    }

    return 0;
    
}
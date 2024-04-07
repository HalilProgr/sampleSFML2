#include "Player.h"

Player::Player(): CircleShape(10.f), AbstractEntity(sf::Vector2f(10,10))
{
}

void Player::Update()
{
    for (auto& ev : _deqevents)
    {
        sf::Vector2f offcet(0, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            offcet.x += 5;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            offcet.x -= 5;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            offcet.y -= 5;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            offcet.y += 5;

        move(offcet);
    }
}

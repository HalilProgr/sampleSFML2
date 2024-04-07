#pragma once

#include <functional>
#include <SFML/System/Vector2.hpp>


class AbstractMoveble
{
public:
	AbstractMoveble(sf::Vector2f position);
	virtual ~AbstractMoveble() = default;

	virtual void Update();
	void SetRule(std::function<sf::Vector2f(int t)> func, sf::Vector2f offset);

protected:
	sf::Vector2f GetPosition();
	sf::Vector2f GetOffset();

private:
	int _t;

	sf::Vector2f _position;
	sf::Vector2f _offset;
	std::function<sf::Vector2f(int t)> _func;
};
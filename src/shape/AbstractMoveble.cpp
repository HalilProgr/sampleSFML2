#include "AbstractMoveble.h"


AbstractMoveble::AbstractMoveble( sf::Vector2f position) 
	: _t(0), _position(position)
{}

void AbstractMoveble::Update()
{
	_position += _func(_t + 1) - _func(_t);
	_t += 1;
}

void AbstractMoveble::SetRule(std::function<sf::Vector2f(int t)> func, sf::Vector2f offset)
{
	_func = func;
	_offset = offset;
}

sf::Vector2f AbstractMoveble::GetPosition()
{
	return _position;
}

sf::Vector2f AbstractMoveble::GetOffset()
{
	return _offset;
}

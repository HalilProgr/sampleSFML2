#include "AbstractEntity.h"
#include <iostream>


AbstractEntity::AbstractEntity(sf::Vector2f size, sf::Vector2f window, sf::Vector2f position) :
	AbstractMoveble(position),
	_size(),
	_sizeWindow(window),
	_deleted(false)
{
}

void AbstractEntity::Update()
{
	AbstractMoveble::Update();
	CheakDeleteStatus();
}

void AbstractEntity::ReduceHealth()
{
	_life -= 1;
}

int AbstractEntity::GetHealth()
{
	return _life;
}

AbstractEntity::GeomParam AbstractEntity::GetGeom()
{
	GeomParam res;
	res.position = GetPosition();
	res.size = _size;
	return res;
}

void AbstractEntity::CheakDeleteStatus()
{
	if ((GetPosition().y - GetOffset().y > _sizeWindow.y)
		|| _life <= 0)
		_deleted = true;
	else 
		_deleted = false;
}

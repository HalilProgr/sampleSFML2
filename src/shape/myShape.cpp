#include "myShape.h"


myShape::myShape(const sf::Vector2f size,sf::Vector2f window, const sf::Vector2f position)
	: AbstractEntity(size, window, position), RectangleShape(size)
{
}

void myShape::Update()
{
	AbstractEntity::Update();
	setPosition(GetPosition());
}

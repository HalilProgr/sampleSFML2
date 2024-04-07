#pragma once

#include "SFML/Graphics/RectangleShape.hpp"

#include "AbstractEntity.h"

class myShape : public AbstractEntity, public sf::RectangleShape
{
public:
	myShape(const sf::Vector2f size, sf::Vector2f window, const sf::Vector2f position);
	~myShape() = default;

	virtual void Update() override;
};
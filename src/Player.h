#pragma once

#include <deque>
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "shape/AbstractEntity.h"


class Player : public AbstractEntity, public sf::CircleShape
{
public:
	Player();
	void Update();

private:
	std::deque<sf::Event> _deqevents;
};


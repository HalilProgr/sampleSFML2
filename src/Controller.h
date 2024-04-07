#pragma once
#include <list>
#include <memory>
#include "shape/AbstractEntity.h"
#include "Player.h"


class Controller
{
public:
	Controller();
	~Controller();

	void Update(); // <<<<
	void Show(); // << 

private:
	void CheakCollisions();

	bool CheakCollision(AbstractEntity::GeomParam shape1, AbstractEntity::GeomParam shape2);

private:
	std::list<std::shared_ptr<AbstractEntity>> _ourBullet;
	std::list<std::shared_ptr<AbstractEntity>> _enemes;
	Player _player;
};


#include "Controller.h"

void Controller::Update()
{
	// Обновление геометрии игрока
	_player.Update();

	// Обновление геометрии врагов
	for (auto iter = _enemes.begin(); iter != _enemes.end(); iter++)
	{
		(*iter)->Update();
	}

	// Обновление геометрии пуль игрока 
	for (auto iter = _ourBullet.begin(); iter != _ourBullet.end(); iter++)
	{
		(*iter)->Update();
	}

	// Проверка коллизии
	for (auto iter = _enemes.begin(); iter != _enemes.end(); iter++)
	{
		if (CheakCollision(_player.GetGeom(), (*iter)->GetGeom()))
		{
			(*iter)->ReduceHealth();
			_player.ReduceHealth();
		}

		if ((*iter)->IsDeleted())
		{
			_delete.insert(_delete.begin(), (*iter));
			_enemes.erase(iter);
		}
	}
}

void Controller::CheakCollisions()
{

}

bool Controller::CheakCollision(AbstractEntity::GeomParam shape1, AbstractEntity::GeomParam shape2)
{

	double sh1_xmax = shape1.position.x + shape1.size.x / 2;
	double sh1_xmin = shape1.position.x - shape1.size.x / 2;
	double sh1_ymax = shape1.position.y + shape1.size.y / 2;
    double sh1_ymin = shape1.position.y - shape1.size.y / 2;

	double sh2_xmax = shape1.position.x + shape1.size.x / 2;
	double sh2_xmin = shape1.position.x - shape1.size.x / 2;
	double sh2_ymax = shape1.position.y + shape1.size.y / 2;
	double sh2_ymin = shape1.position.y - shape1.size.y / 2;

	if (sh1_xmax > sh2_xmin && sh1_ymin < sh2_ymax) return true;
	if (sh1_xmin < sh2_xmax && sh1_ymin < sh2_ymax) return true;
	if (sh1_xmin < sh2_xmax && sh1_ymax > sh2_ymax) return true;
	if (sh1_xmax > sh2_xmin && sh1_ymax > sh2_ymin) return true;

	return false;
}

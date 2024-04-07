#include "Controller.h"

void Controller::Update()
{
	// ќбновление геометрии игрока
	_player.Update();

	// ќбновление геометрии врагов
	for (auto iter = _enemes.begin(); iter != _enemes.end(); iter++)
	{
		(*iter)->Update();
	}

	// ќбновление геометрии пуль игрока 
	for (auto iter = _ourBullet.begin(); iter != _ourBullet.end(); iter++)
	{
		(*iter)->Update();
	}

	// ѕроверка коллизии
	CheakCollisions();
}

void Controller::CheakCollisions()
{
	for (auto ourBulletIter = _ourBullet.begin(); ourBulletIter != _ourBullet.end(); ourBulletIter++)
	{
		for (auto enemesIter = _enemes.begin(); enemesIter != _enemes.end(); enemesIter++)
		{
			if (CheakCollision((*ourBulletIter)->GetGeom(), (*enemesIter)->GetGeom()))
			{
				(*enemesIter)->ReduceHealth();
				if ((*enemesIter)->IsDeleted())
				{
					auto tempIter = enemesIter;
					enemesIter--; // TODO: исправить логику 
					_enemes.erase(tempIter);
				}

				(*ourBulletIter)->ReduceHealth();
				if ((*ourBulletIter)->IsDeleted())
				{
					auto tempIter = enemesIter;
					enemesIter--; // TODO: исправить логику 
					_ourBullet.erase(tempIter);
					break;
				}
			}
		}
	}


	for (auto enemesIter = _enemes.begin(); enemesIter != _enemes.end(); enemesIter++)
	{
		if (CheakCollision(_player.GetGeom(), (*enemesIter)->GetGeom()))
		{
			(*enemesIter)->ReduceHealth();
			if ((*enemesIter)->IsDeleted())
			{
				auto tempIter = enemesIter;
				enemesIter--;
				_enemes.erase(tempIter);
			}

			//_player->ReduceHealth();
			//if ((*ourBulletIter)->IsDeleted())
			//{
				///
				/// 
				/// 
			//}
		}
	}
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

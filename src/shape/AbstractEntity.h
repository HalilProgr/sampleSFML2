#pragma once

#include "AbstractMoveble.h"

/// <summary>
/// Класс реализующий абстрактную игровую сущность
/// отвечает за определение коллизии и актуальность сущности.
/// </summary>
class AbstractEntity : public AbstractMoveble
{
public:

	struct GeomParam
	{
		sf::Vector2f position;
		sf::Vector2f size;
	};

	AbstractEntity(sf::Vector2f size, sf::Vector2f window, sf::Vector2f position);

	virtual void Update() override;

	bool IsDeleted() { return _deleted; };

	void ReduceHealth();
	int GetHealth();

	GeomParam GetGeom();

private:
	void CheakDeleteStatus();

private:
	int _life;

	sf::Vector2f _size;
	sf::Vector2f _sizeWindow;

	bool _deleted;
};

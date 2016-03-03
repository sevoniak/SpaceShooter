#include "Enemy.h"


Enemy::Enemy(void)
{
	radius = 2.0f;
	dead = false;
	damageFrames = 0;
}


Enemy::~Enemy(void)
{
}

bool Enemy::isDead() { return dead; }

bool Enemy::isHostile() { return attacking; }

vector<GameObject*> Enemy::getModels() { return objs; }

float Enemy::getRadius() { return radius; }

bool Enemy::damage(int dmg)
{
	if (damageFrames == 0)
	{
		damageFrames = 30;
		enemyHealth -= dmg;
		if (enemyHealth < 1)
			dead = true;
	}
	return dead;
}

int Enemy::getExp() { return exp; }

vector<Bullet*> Enemy::getBullets() { return bullets; }
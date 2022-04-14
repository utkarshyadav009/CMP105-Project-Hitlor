#pragma once
#include<iostream>
#include"Framework/Animation.h"
#include"Framework/Input.h"
#include"Framework/GameObject.h"
#include"collision.h"

class Enemy :public Animation
{

	int health = 500;
public:
	int getHealth() { return health; }
	void resetHealth() { health = 500; }
	void setHealth(int h) { health = health - h; }
	Enemy();
	bool dead = false;
	collision colision;
	enum animation { zombie_idle,zombie_move, zombie_attack, zombie_dead,zombie_hit ,numberofanimation };
	Animation enemyanimation[numberofanimation];
	void zombie_moves(animation zombie_moves, float dt);
};


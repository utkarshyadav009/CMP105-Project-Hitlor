#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#include "Framework/Input.h"
#include"Framework/Animation.h"
#include"Framework/GameObject.h"
#include<string.h>
#include"collision.h"

class Player:public Animation
{
	int health ;

public:

	//void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
	Player();
	collision colision;
	int getHealth() { return health; }
	void resetHealth();
	void setHealth(int h) { health = health - h; }
	enum animation{idle,walkup,walkdown,walkright,walkleft,walkupleft,walkdownleft,walkupright,walkdownright, shootright,shootleft,shootup,shootdown,shootdownright,shootdownleft,shootupright,shootupleft,die_up,die_down,die_right,die_left,die_upleft,die_upright,die_downleft,die_downright,hit,no_of_animations};
	Animation all_animations[no_of_animations];
	animation current_animation;
	void walk(animation walk_animation,float dt);
	void shoot(animation shoot_animation, float dt);
	void die(float dt, std::string direction);
	void stand(float dt);


};


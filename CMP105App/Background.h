#pragma once
#include<iostream>
#include"Framework/Animation.h"
#include"Framework/GameObject.h"

class Background :public Animation {
public:
	Background();

	void update(float dt);
	void mouse(float dt);
	Animation move;
	Animation mouse_anim;


};



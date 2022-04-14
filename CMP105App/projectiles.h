#pragma once
#include"Framework/GameObject.h"
#include "SFML\Graphics.hpp"
#include"collision.h"
#include"Player.h"
#include<vector>
class projectiles: public GameObject
{
	sf::RectangleShape bullet;
public:
	projectiles();
	collision colision;
	enum bullet_movement{up,down,left,right,downright,downleft,upright,upleft};
	float speed = 1000.f;
	void setposition(std::string direction, sf::Vector2f position);
	void bullet_draw(sf::RenderWindow* window);
	sf::Vector2f getPosition() { return bullet.getPosition(); }
	void move(float dt);

	sf::Vector2f velocity;


};


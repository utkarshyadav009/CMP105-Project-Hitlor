#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include"Framework/Collision.h"
#include"Framework/Vector.h"
#include <string>
#include <iostream>
#include<vector>
#include"Background.h"
#include"Player.h"
#include"Enemy.h"
#include"collision.h"
#include"projectiles.h"
#include "windows.h" 

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in, sf::View* view1,GameState* game);
	~Level();
	int move;
	void handleInput(float dt);
	void update(float dt);
	void render();

	bool gamereset = false;
	void reset();
	float speed = 90.f;
	float screen = 240;
	float backscreen = 0;
	float screenback = 960;
	float enemySpeed = 50.f;
	sf::Vector2f velocity;
	bool checkreset() { return gamereset; }
	sf::Vector2f enemyVelocity;
	sf::FloatRect bulletBoundry;
	int no_of_bullets = 0;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	sf::View* view;
	GameState* gameState;
	AudioManager* audio;
	collision colision;
    //background object
	Background game_background;
    sf::Texture background_texture;
	
	void setDead(bool, int,float);

    
    //player object for animation 
    Player main_player;
    sf::Texture player_texture;
	Vector v;

	Player::animation walkanimation;
	Player::animation shootanimation;
	Player::animation dieanimation;
	std::string direction;
	sf::Texture grandma_text;
	sf::Sprite grandma;
	std::vector<projectiles> bullet;
	std::vector<Enemy> enemies;
	sf::Texture enemy_texture;

	



};
#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include"Framework/Collision.h"
#include"Framework/Vector.h"
#include"Menu.h"
#include <string>
#include <iostream>
#define max_no_of_bars 3

class Options
{
public:
	Options(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game);
	~Options();
	sf::RenderWindow* window;
	Input* input;
	sf::View* view;
	GameState* gameState;


	int selectedItem;
	sf::Font font;
	sf::Font title;
	sf::Text Title;
	sf::Text Hitlor_text;
	sf::Text option[max_no_of_bars];
	void beginDraw();
	void endDraw();
	int handleInput(float dt);
	void update(float dt);
	void render();
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItem; }


	sf::Sprite menu_sprite;
	sf::Texture menu_texture;

};
#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include"Framework/Collision.h"
#include"Framework/Vector.h"
#include <string>
#include <iostream>
#include"Level.h"
#include"Options.h"
#define max_no_of_bars 4

class Menu
{
public:
	Menu(sf::RenderWindow* hwnd, Input* in, sf::View* view1,GameState* game);
	~Menu();

	
	int handleInput(float dt);
	void update(float dt);
	void render();
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItem; }


	sf::RenderWindow* window;
	Input* input;
	sf::View* view;
	GameState* gameState;
	AudioManager* audio;
	
	Level* level1;

	void loadlevel(float dt);
	int selectedItem;
	sf::Font font;
	sf::Font title;
	sf::Text press;
	sf::Text Title;
	sf::Text menu[max_no_of_bars];
	void beginDraw();
	void endDraw();


	sf::Sprite menu_sprite;
	sf::Texture menu_texture;

};

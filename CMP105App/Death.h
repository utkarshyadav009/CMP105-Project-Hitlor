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
#include"Level.h"
#define max_no_of_bars 2
class Death
{
public:
	Death(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game);
	~Death();
	sf::RenderWindow* window;
	Input* input;
	sf::View* view;
	GameState* gameState;
	int handleInput(float dt);
	void render();
	void MoveUp();
	void MoveDown();
	void beginDraw();
	void endDraw();
	int GetPressedItem() { return selectedItem; }
	int selectedItem;
	sf::Font font;
	sf::Text death[max_no_of_bars];
	sf::Text deathScreentext;
	sf::Sprite deathScreen;
	sf::Texture deathScreen_texture;
	sf::Font title;
	sf::Text Hitlor_text;


};

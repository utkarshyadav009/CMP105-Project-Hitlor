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
#define max_no_of_bars 2
class Video
{
public:
	Video(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game);
	
	sf::RenderWindow* window;
	Input* input;
	sf::View* view;
	GameState* gameState;

	sf::Font title;
	sf::Text Hitlor_text;
	
	sf::Font font;
	sf::Text video_option[max_no_of_bars];

	sf::Text On_Off;
	
	bool Fullscreen();
	bool fullscreen = false;

	int selectedItem;

	int handleInput(float dt);
	void render();
	void beginDraw();
	void endDraw();

	void MoveUp();
	void MoveDown();

	int GetPressedItem() { return selectedItem; }

	sf::Sprite video_sprite;
	sf::Texture video_texture;
};


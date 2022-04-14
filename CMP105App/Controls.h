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
class Controls
{
	public:
		Controls(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game);
		sf::RenderWindow* window;
		Input* input;
		sf::View* view;
		GameState* gameState;
		int handleInput(float dt);
		void render();
		void beginDraw();
		void endDraw();
		sf::Font font;
		sf::Text back_button;
		sf::Sprite controls;
		sf::Texture control_texture;
		sf::Font title;
		sf::Text Hitlor_text;


};


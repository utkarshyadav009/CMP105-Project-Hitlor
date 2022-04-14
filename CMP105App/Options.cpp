#include "Options.h"
Options::Options(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game)
{
	window = hwnd;
	input = in;
	view = view1;
	gameState = game;

//	Menu menu(window, input, view, gameState);
	//menu1 = new Menu(window, input, view, gameState);


	font.loadFromFile("font/ZOMBIES REBORN.ttf");
	menu_texture.loadFromFile("gfx/menu.png");
	menu_sprite.setTexture(menu_texture);
	
	title.loadFromFile("font/BloodBlocks Project.ttf");
	
	Hitlor_text.setFont(title);
	Hitlor_text.setFillColor(sf::Color::Red);
	Hitlor_text.setString("HITLOR");
	Hitlor_text.setOutlineColor(sf::Color::Black);
	Hitlor_text.setCharacterSize(70);
	Hitlor_text.setPosition(3, 4);

	

	option[0].setFont(font);
	option[0].setFillColor(sf::Color::Red);
	option[0].setString("Control");
	option[0].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 1));

	option[1].setFont(font);
	option[1].setFillColor(sf::Color::White);
	option[1].setString("Video");
	option[1].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 2));

	option[2].setFont(font);
	option[2].setFillColor(sf::Color::White);
	option[2].setString("Back");
	option[2].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 3));
	
	selectedItem = 0;
	//Menu menu(window, input, view, gameState);
	//menu1 = new Menu(window, input, view, gameState);

}
Options::~Options()
{
}

void Options::render()
{
	beginDraw();
	window->draw(menu_sprite);
	window->draw(Title);
	window->draw(Hitlor_text);
	for (int i = 0; i < 3; i++)
	{
		window->draw(option[i]);
	}

	endDraw();

}





void Options::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		option[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		option[selectedItem].setFillColor(sf::Color::Red);
	}
}
void Options::MoveDown()
{
	if (selectedItem + 1 < max_no_of_bars)
	{
		option[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		option[selectedItem].setFillColor(sf::Color::Red);
	}
}
int Options::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		MoveUp();
		input->setKeyUp(sf::Keyboard::Up);
		return 0;
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		MoveDown();
		input->setKeyUp(sf::Keyboard::Down);
		return 0;
	}

	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		switch (GetPressedItem())
		{
			//static bool runOnce = true;
		case 0:
			std::cout << "Controls has been pressed" << std::endl;
			gameState->setCurrentState(State::CONTROLS);
			input->setKeyUp(sf::Keyboard::Enter);
			
			break;
		case 1:
			std::cout << "Video" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			gameState->setCurrentState(State::VIDEO);


			//if (runOnce)
			//{


			//audio->playMusicbyName("MenuScore");
			//runOnce = false;



			break;

		case 2:
			std::cout << "Back button has been pressed" << std::endl;
			//loadmenu(dt);

			gameState->setCurrentState(State::MENU);
			input->setKeyUp(sf::Keyboard::Enter);
			break;
	
		}

		return 0;
	}
}
void Options::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}
void Options::endDraw()
{
	window->display();
}
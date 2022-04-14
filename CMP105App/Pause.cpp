#include "Pause.h"
Pause::Pause(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game)
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



	pause[0].setFont(font);
	pause[0].setFillColor(sf::Color::Red);
	pause[0].setString("Resume");
	pause[0].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 1));

	pause[1].setFont(font);
	pause[1].setFillColor(sf::Color::White);
	pause[1].setString("Options");
	pause[1].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 2));

	pause[2].setFont(font);
	pause[2].setFillColor(sf::Color::White);
	pause[2].setString("Main Menu");
	pause[2].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 3));

	pause[3].setFont(font);
	pause[3].setFillColor(sf::Color::White);
	pause[3].setString("Exit");
	pause[3].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 4));
	selectedItem = 0;
	//Menu menu(window, input, view, gameState);
	//menu1 = new Menu(window, input, view, gameState);

}

void Pause::render()
{

	beginDraw();
	window->draw(menu_sprite);
	window->draw(Title);
	window->draw(Hitlor_text);
	for (int i = 0; i < 4; i++)
	{
		window->draw(pause[i]);
	}

	endDraw();

}

void Pause::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		pause[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		pause[selectedItem].setFillColor(sf::Color::Red);
	}
}
void Pause::MoveDown()
{
	if (selectedItem + 1 < max_no_of_bars)
	{
		pause[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		pause[selectedItem].setFillColor(sf::Color::Red);
	}
}

int Pause::handleInput(float dt)
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
			std::cout << "Resume" << std::endl;
			gameState->setCurrentState(State::LEVEL);
			input->setKeyUp(sf::Keyboard::Enter);

			break;
		case 1:
			std::cout << "Options" << std::endl;
			gameState->setCurrentState(State::OPTIONS);
			input->setKeyUp(sf::Keyboard::Enter);
	


			//if (runOnce)
			//{


			//audio->playMusicbyName("MenuScore");
			//runOnce = false;



			break;

		case 2:
			std::cout << "Main Menu" << std::endl;
			gameState->setCurrentState(State::MENU);
			input->setKeyUp(sf::Keyboard::Enter);
			
			break;
		case 3:
			std::cout << "Back button has been pressed" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			window->close();
			break;
		}

		return 0;
	}
}




Pause::~Pause()
{
}
void Pause::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}
void Pause::endDraw()
{
	window->display();
}
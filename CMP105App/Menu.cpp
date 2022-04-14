#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game)
{
	window = hwnd;
	input = in;
	view = view1;
	gameState = game;
	audio = new AudioManager();
	font.loadFromFile("font/ZOMBIES REBORN.ttf");
	menu_texture.loadFromFile("gfx/menu.png");
	menu_sprite.setTexture(menu_texture);
	title.loadFromFile("font/BloodBlocks Project.ttf");
	menu[0].setFont(title);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("HITLOR");
	menu[0].setOutlineColor(sf::Color::Black);
	menu[0].setCharacterSize(70);
	menu[0].setPosition(3, 4);
	 
	press.setFont(font);
	press.setFillColor(sf::Color::Red);
	press.setCharacterSize(22);
	press.setString("*Press HITLOR to know Hitlor's back story");
	press.setPosition(10, 250);

	selectedItem = 0;

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Play");
	menu[1].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Options");
	menu[2].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(282 / 5, 282 / (max_no_of_bars + 1) * 4));
	
	
	
	Level level(window, input, view,gameState);
	level1 = new Level(window, input, view,gameState);




	audio->addMusic("sfx/MenuScore.ogg", "MenuScore");
	if (gameState->getCurrentState() == State::MENU || gameState->getCurrentState() == State::CREDITS || gameState->getCurrentState() == State::PAUSE)
	{
		static bool runOnce = true;
		{
			if (runOnce)
			{

				audio->stopAllMusic();
				audio->playMusicbyName("MenuScore");
				runOnce = false;
			}
		}
	}
}
Menu::~Menu()
{
}

void Menu::loadlevel(float dt)
{
	level1->handleInput(dt);
	level1->update(dt);
	level1->render();
	

}
void Menu::render()
{
	beginDraw();
	window->draw(menu_sprite);
	window->draw(Title);
	//window->draw(press);
	for (int i = 0; i < 4; i++)
	{
		window->draw(menu[i]);
	}

	endDraw();
	
}
void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}
void Menu::MoveDown()
{
	if (selectedItem + 1 < max_no_of_bars)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
	
}
int Menu::handleInput(float dt)
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
			std::cout << "Hitlor has been pressed" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			break;
		case 1:
			std::cout << "Play Button has been pressed" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			gameState->setCurrentState(State::LEVEL);
			
			
				//if (runOnce)
				//{

					audio->stopAllMusic();
					//audio->playMusicbyName("MenuScore");
					//runOnce = false;
				
			
		
			break;
			
		case 2:
			std::cout << "Option Button has been pressed" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			gameState->setCurrentState(State::OPTIONS);
			break;
		case 3:
			input->setKeyUp(sf::Keyboard::Enter);
			window->close();
			break;
		}

		return 0;
	}
}

	

void Menu::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}
void Menu::endDraw()
{
	window->display();
}
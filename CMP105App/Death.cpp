#include "Death.h"

Death::Death(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game)
{
	window = hwnd;
	input = in;
	view = view1;
	gameState = game;

	//	Menu menu(window, input, view, gameState);
		//menu1 = new Menu(window, input, view, gameState);


	font.loadFromFile("font/ZOMBIES REBORN.ttf");
	deathScreen_texture.loadFromFile("gfx/menu.png");
	deathScreen.setTexture(deathScreen_texture);

	title.loadFromFile("font/BloodBlocks Project.ttf");

	Hitlor_text.setFont(title);
	Hitlor_text.setFillColor(sf::Color::Red);
	Hitlor_text.setString("HITLOR");
	Hitlor_text.setOutlineColor(sf::Color::Black);
	Hitlor_text.setCharacterSize(70);
	Hitlor_text.setPosition(3, 4);

	deathScreentext.setFont(font);
	deathScreentext.setFillColor(sf::Color::Red);
	deathScreentext.setString("You Died");
	deathScreentext.setCharacterSize(70);
	deathScreentext.setPosition(10, 70 );


	death[0].setFont(font);
	death[0].setFillColor(sf::Color::Red);
	death[0].setString("Restart");
	death[0].setPosition(sf::Vector2f(282 / 2, 282 / (max_no_of_bars ) * 1));

	death[1].setFont(font);
	death[1].setFillColor(sf::Color::White);
	death[1].setString("Exit");
	death[1].setPosition(sf::Vector2f(282 / 2, 282 / (max_no_of_bars + 1) * 2));
	selectedItem = 0;
}

void Death::render()
{

	beginDraw();
	window->draw(deathScreen);
	window->draw(Hitlor_text);
	window->draw(deathScreentext);
	for (int i = 0; i < 2; i++)
	{
		window->draw(death[i]);
	}

	endDraw();

}

void Death::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		death[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		death[selectedItem].setFillColor(sf::Color::Red);
	}
}
void Death::MoveDown()
{
	if (selectedItem + 1 < max_no_of_bars)
	{
		death[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		death[selectedItem].setFillColor(sf::Color::Red);
	}
}

int Death::handleInput(float dt)
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
			std::cout << "Restart" << std::endl;
			gameState->setCurrentState(State::MENU);
			input->setKeyUp(sf::Keyboard::Enter);

			break;
		case 1:
			std::cout << "Exit" << std::endl;
			window->close();
			input->setKeyUp(sf::Keyboard::Enter);


			break;

	
		}

		return 0;
	}
}




Death::~Death()
{
}
void Death::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}
void Death::endDraw()
{
	window->display();
}
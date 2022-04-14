#include "Win.h"
Win::Win(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game)
{
	window = hwnd;
	input = in;
	view = view1;
	gameState = game;

	font.loadFromFile("font/ZOMBIES REBORN.ttf");
	winText.loadFromFile("gfx/win.png");
	win.setTexture(winText);

	back_button.setFont(font);
	back_button.setFillColor(sf::Color::Red);
	back_button.setString("Exit");
	back_button.setPosition(sf::Vector2f(200, 200));


	title.loadFromFile("font/BloodBlocks Project.ttf");
	Hitlor_text.setFont(title);
	Hitlor_text.setFillColor(sf::Color::Red);
	Hitlor_text.setString("HITLOR");
	Hitlor_text.setOutlineColor(sf::Color::Black);
	Hitlor_text.setCharacterSize(70);
	Hitlor_text.setPosition(3, 4);
}
void Win::render()
{
	beginDraw();
	window->draw(win);
	window->draw(Hitlor_text);
	window->draw(back_button);
	endDraw();

}
void Win::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}
void Win::endDraw()
{
	window->display();
}

int Win::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		//gameState->setCurrentState(State::MENU);
		input->setKeyUp(sf::Keyboard::Enter);
		window->close();
		return 0;
	}

}
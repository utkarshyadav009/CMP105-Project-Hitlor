#include "Controls.h"
Controls::Controls(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game)
{
	window = hwnd;
	input = in;
	view = view1;
	gameState = game;

	font.loadFromFile("font/ZOMBIES REBORN.ttf");
	control_texture.loadFromFile("gfx/controls.png");
	controls.setTexture(control_texture);

	back_button.setFont(font);
	back_button.setFillColor(sf::Color::Red);
	back_button.setString("Back");
	back_button.setPosition(sf::Vector2f(234,28));
	
	
	title.loadFromFile("font/BloodBlocks Project.ttf");
	Hitlor_text.setFont(title);
	Hitlor_text.setFillColor(sf::Color::Red);
	Hitlor_text.setString("HITLOR");
	Hitlor_text.setOutlineColor(sf::Color::Black);
	Hitlor_text.setCharacterSize(70);
	Hitlor_text.setPosition(3, 4);
}
void Controls::render()
{
	beginDraw();
	window->draw(controls);
	window->draw(Hitlor_text);
	window->draw(back_button);

	endDraw();

}
void Controls::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}
void Controls::endDraw()
{
	window->display();
}

int Controls::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		gameState->setCurrentState(State::OPTIONS);
		input->setKeyUp(sf::Keyboard::Enter);
		return 0;
	}
	
}
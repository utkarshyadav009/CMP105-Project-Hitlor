#include "Video.h"
Video::Video(sf::RenderWindow* hwnd, Input* in, sf::View* view1, GameState* game)
{
	window = hwnd;
	input = in;
	view = view1;
	gameState = game;

	font.loadFromFile("font/ZOMBIES REBORN.ttf");
	
	
	video_texture.loadFromFile("gfx/menu.png");
	video_sprite.setTexture(video_texture);

	title.loadFromFile("font/BloodBlocks Project.ttf");

	Hitlor_text.setFont(title);
	Hitlor_text.setFillColor(sf::Color::Red);
	Hitlor_text.setString("HITLOR");
	Hitlor_text.setOutlineColor(sf::Color::Black);
	Hitlor_text.setCharacterSize(70);
	Hitlor_text.setPosition(3, 4);

	On_Off.setFont(font);
	On_Off.setFillColor(sf::Color::Red);
	On_Off.setString("Off");
	On_Off.setPosition(sf::Vector2f(150,95 ));

	video_option[0].setFont(font);
	video_option[0].setFillColor(sf::Color::Red);
	video_option[0].setString("Set FullScreen: ");
	video_option[0].setPosition(sf::Vector2f(20, 282 / (max_no_of_bars + 1) * 1));

	video_option[1].setFont(font);
	video_option[1].setFillColor(sf::Color::White);
	video_option[1].setString("Back");
	video_option[1].setPosition(sf::Vector2f(20, 282 / (max_no_of_bars + 1) * 2));

	selectedItem = 0;
}

void Video::render()
{
	beginDraw();
	window->draw(video_sprite);
	window->draw(Hitlor_text);
	for (int i = 0; i < 2; i++)
	{
		window->draw(video_option[i]);
	}
	window->draw(On_Off);
	endDraw();

}
void Video::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		video_option[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		video_option[selectedItem].setFillColor(sf::Color::Red);
	}
}
void Video::MoveDown()
{
	if (selectedItem + 1 < max_no_of_bars)
	{
		video_option[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		video_option[selectedItem].setFillColor(sf::Color::Red);
	}
}
bool Video::Fullscreen()
{
	if (fullscreen == false)
	{
		fullscreen = true;
		return false;

	}
	if (fullscreen == true)
	{
		fullscreen = false;
		return true;

	}
}

int Video::handleInput(float dt)
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
			
		case 0:
			//std::cout << "FullScreen" << std::endl;
			
			if (Fullscreen() == false)
			{
				window->create(sf::VideoMode(282, 282), "FullScreen", sf::Style::Fullscreen);
				On_Off.setString("On");
				std::cout << fullscreen << std::endl;
				input->setKeyUp(sf::Keyboard::Enter);
			//	break;
			}
			
			
            else if (Fullscreen()==false)
			{
				std::cout << "Exit FullScreen" << std::endl;
				window->create(sf::VideoMode(1200, 675), "FullScreen",sf::Style::Default);
				On_Off.setString("Off");
				fullscreen = false;
				input->setKeyUp(sf::Keyboard::Enter);
				//break;
			}
			

			break;
		case 1:
			std::cout << "Video" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			gameState->setCurrentState(State::OPTIONS);

		}

		return 0;
	}
}




void Video::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}
void Video::endDraw()
{
	window->display();
}
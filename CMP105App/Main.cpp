// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.
// @author Paul Robertson

#include <iostream>
#include "Level.h"
#include"Player.h"
#include"Menu.h"
#include"Options.h"
#include"Controls.h"
#include"Video.h"
#include"Pause.h"
#include"Death.h"
#include"Win.h"
#include"Framework/GameState.h"



sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) {

	// Compares the aspect ratio of the window to the aspect ratio of the view,
	// and sets the view's viewport accordingly in order to archieve a letterbox effect.
	// A new view (with a new viewport set) is returned.

	float windowRatio = windowWidth / (float)windowHeight;
	float viewRatio = view.getSize().x / (float)view.getSize().y;
	float sizeX = 1;
	float sizeY = 1;
	float posX = 0;
	float posY = 0;

	bool horizontalSpacing = true;
	if (windowRatio < viewRatio)
		horizontalSpacing = false;

	// If horizontalSpacing is true, the black bars will appear on the left and right side.
	// Otherwise, the black bars will appear on the top and bottom.

	if (horizontalSpacing) {
		sizeX = viewRatio / windowRatio;
		posX = (1 - sizeX) / 2.f;
	}

	else {
		sizeY = windowRatio / viewRatio;
		posY = (1 - sizeY) / 2.f;
	}

	view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

	return view;
	
}



int main()
{

	//Create the window
	sf::RenderWindow window(sf::VideoMode(1200, 675), "CMP105");

	// Initialise input and level objects.
	Input input;
	sf::View view;
	GameState* gamestate = new GameState();
	static bool resize = false;
	void reset();

	gamestate->setCurrentState(State::MENU);
	view.setSize(282, 282);
	view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
	view = getLetterboxView(view, 1200, 675);
	Level level(&window, &input, &view,gamestate);
	Menu menu(&window, &input, &view,gamestate);
	Options options(&window, &input, &view, gamestate);
	Controls controls(&window, &input, &view, gamestate);
	Video video(&window, &input, &view, gamestate);
	Pause pause(&window, &input, &view, gamestate);
	Death death(&window, &input, &view, gamestate);
	Win  win(&window, &input, &view, gamestate);
	// Initialise objects for delta time
	sf::Clock clock;
	float deltaTime;
	// Game Loop
	while (window.isOpen())
	{

		// Handle window events.
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				if (resize == false)
				{
					window.setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
					view = getLetterboxView(view, event.size.width, event.size.height);
					resize = true;
				}
				break;
			case sf::Event::KeyPressed:
				// update input class
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				//update input class
				input.setKeyUp(event.key.code);
				break;
			case sf::Event::MouseMoved:
				//update input class
				input.setMousePosition(event.mouseMove.x, event.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLDown(true);
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					input.setMouseRDown(true);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLDown(false);
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					input.setMouseRDown(false);
				}
				break;
			default:
				// don't handle other events
				break;
			}
		}

		// Calculate delta time. How much time has passed 
		// since it was last calculated (in seconds) and restart the clock.
		deltaTime = clock.restart().asSeconds();

		// Call standard game loop functions (input, update and render)
		window.setView(view);
		
		switch (gamestate->getCurrentState())
		{
		case(State::MENU):
			menu.handleInput(deltaTime);
			menu.render();
			
			if (gamestate->getCurrentState() == State::LEVEL)
			{
				std::cout << "LEVEL" << std::endl;
			}
			break;
		case(State::LEVEL):
			
			level.handleInput(deltaTime);
			level.update(deltaTime);
			level.render();
			break;
		case(State::OPTIONS):
			options.handleInput(deltaTime);
			options.render();

			if (gamestate->getCurrentState() == State::OPTIONS)
			{
				//std::cout << "OPTIONS" << std::endl;
			}
			break;
		case(State::CONTROLS):
			controls.handleInput(deltaTime);
			controls.render();
			break;
		case(State::VIDEO):
			video.handleInput(deltaTime);
			video.render();
			break;
		case(State::PAUSE):
			pause.handleInput(deltaTime);
			pause.render();
			break;
		case(State::DEATH):
			death.handleInput(deltaTime);
			death.render();
		window.setView(view);
			level.reset();
			break;
		case(State::CREDITS):
			win.handleInput(deltaTime);
			win.render();
			window.setView(view);
			level.reset();
			break;
		}
		

	}
}


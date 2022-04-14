#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, sf::View* view1,GameState* game)
{
	window = hwnd;
	input = in;
	view = view1;
	gameState = game;

	//loading background 
	background_texture.loadFromFile("gfx/background.png");
	game_background.setPosition(0, -6);
	game_background.setTexture(background_texture);



	//loading main player
	player_texture.loadFromFile("gfx/player.png");

	main_player.setPosition(30, 100);
	main_player.setTexture(player_texture);
	main_player.colision.setCollisionBox(sf::FloatRect(10, 15, 35, 35));
	main_player.colision.setPlayerRadiusCollisionBox(sf::FloatRect(-100, -70, 250, 150));
	main_player.stand(0);

	grandma_text.loadFromFile("gfx/grandma.png");
	grandma.setTexture(grandma_text);
	grandma.setPosition(1121, 100);
	
	//loading enemies
	enemy_texture.loadFromFile("gfx/Zombie2.png");
	for (int i = 0; i < 7; i++)
	{
		enemies.push_back(Enemy());
		enemies[i].setTexture(enemy_texture);
		enemies[i].colision.setCollisionBox(sf::FloatRect(25, 20, 20, 30));
		
	}
	enemies[0].setPosition(450, 70);
	enemies[1].setPosition(450, 122);
	enemies[2].setPosition(696, 70);
	enemies[3].setPosition(696, 122);
	enemies[4].setPosition(950, 70);
	enemies[5].setPosition(950, 122);
	enemies[6].setPosition(-1000, 0);
	
	
	//adding sounds and music

	audio = new AudioManager();
	audio->addMusic("sfx/sewer_sound.ogg", "background_sound");
	audio->addSound("sfx/walking2.ogg", "walking");
	audio->addSound("sfx/shooting1.ogg", "shoot");

}


Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	
		
		if (checkreset())
		{
			static int i = 0;
			if (i == 0)
			{
				view->move(240, 0);
				//std::cout << "BHENCHOD" << std::endl;
				i++;
			}
		}
	
	projectiles temp = projectiles();
	static bool runOnce = true;
	{
		if (runOnce)
		{

			if (audio->getMusic()->getStatus() == sf::SoundSource::Status::Stopped )
			{

				audio->stopAllMusic();
				audio->playMusicbyName("background_sound");
			}
			runOnce = false;
		}
	}

	velocity = sf::Vector2f();

	if (main_player.getPosition().x >  screen)
	{

		view->move(240, 0);
		screen += 240;

		if (backscreen < 2*screen)
		{
			backscreen += 240;

		}

	}
	if (main_player.getPosition().x < backscreen)
	{
		view->move(-240, 0);
		backscreen -= 240;
		if (screen > backscreen)
		{
			screen -= 240;
		}
		

	}
	if (main_player.getPosition().x >= 1121 )
	{
		float yend = main_player.getPosition().y;
		main_player.setPosition(1121, yend);
	}
	
	if (main_player.getPosition().y <= 63)
	{
		float xup = main_player.getPosition().x;
		main_player.setPosition(xup, 63);
	}
	if (main_player.getPosition().y >= 130)
	{
		float x = main_player.getPosition().x;
		main_player.setPosition(x, 130);
	}
	if (main_player.getPosition().x <= -8)
	{
		float yleft = main_player.getPosition().y;
		main_player.setPosition(-8, yleft);
	}
		//walking up
		if (input->isKeyDown(sf::Keyboard::Up))
		{
			direction = "up";
			if (audio->getSound("walking")->getStatus() == sf::SoundSource::Status::Stopped)
			{
				audio->playSoundbyName("walking");

			}			
			walkanimation = Player::walkup;
			v.normalise(velocity);
			velocity.y = -1;
			main_player.walk(walkanimation,dt);
			//std::cout << main_player.getPosition().x << "  ";
			//std::cout << main_player.getPosition().y << std::endl;
 
		}

	
		//walking down 
		if (input->isKeyDown(sf::Keyboard::Down))
		{
			direction = "down";
				if (audio->getSound("walking")->getStatus() == sf::SoundSource::Status::Stopped)
				{
					audio->playSoundbyName("walking");

				}
			walkanimation = Player::walkdown;
			v.normalise(velocity);
			velocity.y = 1;
			main_player.walk(walkanimation,dt);
			//std::cout << main_player.getPosition().x<<"  ";
			//std::cout << main_player.getPosition().y<<std::endl;

		}

		

		//waling left
		if (input->isKeyDown(sf::Keyboard::Left))
		{
			direction = "left";
			if (audio->getSound("walking")->getStatus() == sf::SoundSource::Status::Stopped)
			{
				audio->playSoundbyName("walking");

			}
			walkanimation = Player::walkleft;
			v.normalise(velocity);
			velocity.x = -1;
			main_player.walk(walkanimation,dt);
			//std::cout << main_player.getPosition().x << "\n";
			//std::cout << main_player.getPosition().y << std::endl;

		}

		//walking right 
		if (input->isKeyDown(sf::Keyboard::Right))
		{
			direction = "right";
			if (audio->getSound("walking")->getStatus() == sf::SoundSource::Status::Stopped)
			{
				audio->playSoundbyName("walking");

			}
			walkanimation = Player::walkright;
			v.normalise(velocity);
			velocity.x = 1;
			main_player.walk(walkanimation,dt);
			//std::cout << main_player.getPosition().x << " \n";
			//std::cout << main_player.getPosition().y << std::endl;	

		}

		//waking downleft 
		if (input->isKeyDown(sf::Keyboard::Left) && input->isKeyDown(sf::Keyboard::Down))
		{
			direction = "downleft";
			if (audio->getSound("walking")->getStatus() == sf::SoundSource::Status::Stopped)
			{
				audio->playSoundbyName("walking");

			}
			walkanimation = Player::walkdownleft;
			v.normalise(velocity);
			velocity.x = -1;
			velocity.y = 1;
			main_player.walk(walkanimation,dt);

		}


		//walking upleft
		if (input->isKeyDown(sf::Keyboard::Left) && input->isKeyDown(sf::Keyboard::Up))
		{
			direction = "upleft";
			if (audio->getSound("walking")->getStatus() == sf::SoundSource::Status::Stopped)
			{
				audio->playSoundbyName("walking");

			}
			walkanimation = Player::walkupleft;
			v.normalise(velocity);
			velocity.x = -1;
			velocity.y = -1;
			main_player.walk(walkanimation,dt);

		}

		//walking downright 
		if (input->isKeyDown(sf::Keyboard::Right) && input->isKeyDown(sf::Keyboard::Down))
		{
			direction = "downright";
			if (audio->getSound("walking")->getStatus() == sf::SoundSource::Status::Stopped )
			{
				audio->playSoundbyName("walking");

			}
			walkanimation = Player::walkdownright;
			v.normalise(velocity);
			velocity.x = 1;
			velocity.y = 1;
			main_player.walk(walkanimation,dt);

		}

		//walking upright
		if (input->isKeyDown(sf::Keyboard::Right) && input->isKeyDown(sf::Keyboard::Up))
		{
			direction = "upright";
			if (audio->getSound("walking")->getStatus() == sf::SoundSource::Status::Stopped)
			{
				audio->playSoundbyName("walking");

			}
			walkanimation = Player::walkupright;
			v.normalise(velocity);
			velocity.x = 1;
			velocity.y = -1;
			main_player.walk(walkanimation,dt);
			
		}
		//shooting 
		if (input->isKeyDown(sf::Keyboard::Space))
		{
			projectiles temp = projectiles();
			
			if (audio->getSound("shoot")->getStatus() == sf::SoundSource::Status::Stopped)
			{
				audio->playSoundbyName("shoot");

			}
	
			if (direction == "up")
			{
				temp.velocity.y = -1;
				main_player.shoot(Player::shootup, dt);
				
			}
			if (direction == "down")
			{
				temp.velocity.y = 1;
				main_player.shoot(Player::shootdown, dt);
			}
			if (direction == "left")
			{
				temp.velocity.x = -1;
				main_player.shoot(Player::shootleft, dt);

			}
			if (direction == "right")
			{
				temp.velocity.x = 1;
				main_player.shoot(Player::shootright, dt);

			}
			if (direction == "upright")
			{
				temp.velocity.x = 1;
				temp.velocity.y = -1;
				main_player.shoot(Player::shootupright, dt);
			}
			if (direction == "upleft")
			{
				temp.velocity.x = -1;
				temp.velocity.y = -1;
				main_player.shoot(Player::shootupleft, dt);
			}
			if (direction == "downleft")
			{
				temp.velocity.x = -1;
				temp.velocity.y = 1;
				main_player.shoot(Player::shootdownleft, dt);

			}
			if (direction == "downright")
			{
				temp.velocity.x = 1;
				temp.velocity.y = 1;
				main_player.shoot(Player::shootdownright, dt);
			
			}
	
			temp.setposition(direction, main_player.getPosition());
			bullet.push_back(temp);
			
		}
		v.normalise(velocity);
		main_player.move(velocity* speed* dt);	 


		if (input->isKeyDown(sf::Keyboard::Escape))
		{
			gameState->setCurrentState(State::PAUSE);

		}
}

// Update game objects
void Level::update(float dt)
{	
	
	main_player.colision.setPosition(main_player.getPosition());
	main_player.colision.setPlayerRadiusPosition(main_player.getPosition());
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].colision.setPosition(enemies[i].getPosition());
	}
	game_background.update(dt);

	bulletBoundry.left = (view->getCenter().x) - ((view->getSize().x)/2);
	bulletBoundry.top = (view->getCenter().y) - ((view->getSize().y) / 2);
	bulletBoundry.width = view->getSize().x;
	bulletBoundry.height = view->getSize().y;
	for (int i = 0; i < bullet.size(); i++)
	{
		//no_of_bullets++;
		bullet[i].colision.setCollisionBox(sf::FloatRect(0, 0, 2, 2));
		bullet[i].colision.setPosition(bullet[i].getPosition());
		bullet[i].move(dt);
	//	
		if (!bulletBoundry.contains(bullet[i].getPosition()))
		{//!bulletBoundry.contains(temp.getPosition())
			bullet.erase(bullet.begin()+i);

			
		}
		//input->setKeyUp(sf::Keyboard::Space);
		
	}

	
	for (int j = 0; j < enemies.size(); j++)
	{
		if (enemies[j].colision.checkCollision(main_player.colision.getPlayerRaidus()))
		{
			
			
			if (enemies[j].getPosition().x - main_player.getPosition().x > 30)
			{
				
				enemyVelocity.x = -1;
				enemies[j].zombie_moves(Enemy::zombie_move, dt);
				enemies[j].move(enemyVelocity * enemySpeed * dt);

			}
			//std::cout << enemies[j].getPosition().x - main_player.getPosition().x << std::endl;
			else
			{
				std::cout << "FLIP" << std::endl;
				enemyVelocity.x = 1;
				enemies[j].zombie_moves(Enemy::zombie_move, dt);
				enemies[j].move(enemyVelocity * enemySpeed * dt);
			}
			
		}
		else
		{
			enemies[j].zombie_moves(Enemy::zombie_idle, dt);
		}
		for (int i = 0; i < bullet.size(); i++)
		{

			if (bullet[i].colision.checkCollision(enemies[j].colision.getRect()))
			{
				bullet.erase(bullet.begin() + i);
				enemies[j].zombie_moves(Enemy::zombie_hit, dt);
				enemies[j].setHealth(1);
				

			}
		}

	}





	for (int i = 0; i < enemies.size(); i++)
	{
		


		
	
		if (enemies[i].colision.checkCollision(main_player.colision.getRect()))
		{
			
			//main_player.setPosition((enemies[i].getPosition().x)-30, enemies[i].getPosition().y);
	
			enemies[i].zombie_moves(Enemy::zombie_attack, dt);
			main_player.die(dt,"hit");
			//std::cout << main_player.getHealth() << std::endl;
			main_player.setHealth(100);
			//std::cout << main_player.getHealth() << std::endl; 
			if (main_player.getHealth() <= 0)
			{
				main_player.die(dt, direction);
				view->move(-backscreen, 0);
				gameState->setCurrentState(State::DEATH);

			}
			
		}
		else
		{
			enemySpeed = 20;
		}
		

	}
	//calling update function from the background class for the animation of the background 

	for (int i = 0; i < enemies.size(); i++)
	{
		
		if (enemies[i].getHealth() <= 0)
		{
			enemies.erase(enemies.begin() + i);
		}
		


	}



	if (main_player.getPosition().x > 1110)
	{
			std::cout << "You win" << std::endl;
			view->move(-backscreen, 0);
			gameState->setCurrentState(State::CREDITS);
			
	}
	
}


// Render level
void Level::render()
{
	beginDraw();
	//rendering the background
	window->draw(game_background);

	//rendering the player
	//std::cout << "View X: "<<window->getView().getCenter().x << "   " << "View Y: "<< window->getView().getCenter().x << std::endl;
	//view->setCenter(0, 0);
	window->draw(main_player);

	//main_player.drawDebugCollision(window);
	//rendering enemies
	
	
			//main_player.colision.drawDebugCollision(window);
			//main_player.colision.drawPlayerRadiusDebugCollision(window);
			for (int i = 0; i < enemies.size(); i++)
			{
				window->draw(enemies[i]);
				//enemies[i].colision.drawDebugCollision(window);
			}
//	bullet.bullet_draw(window);
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i].bullet_draw(window);
		bullet[i].colision.drawDebugCollision(window);
		
	}
	//window->draw(grandma);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}
void Level::reset()
{

	background_texture.loadFromFile("gfx/background.png");
	game_background.setPosition(0, -6);
	game_background.setTexture(background_texture);



	//loading main player
	player_texture.loadFromFile("gfx/player.png");
	//main_player.setInput(input);
	//main_player.setWindow(window);
	main_player.setPosition(30, 100);
	main_player.setTexture(player_texture);
	main_player.colision.setCollisionBox(sf::FloatRect(10, 15, 35, 35));
	main_player.colision.setPlayerRadiusCollisionBox(sf::FloatRect(-100, -70, 250, 150));
	main_player.stand(0);

	grandma_text.loadFromFile("gfx/grandma.png");
	grandma.setTexture(grandma_text);
	grandma.setPosition(1121, 100);
//	bool gamereset = false;
	//loading enemies
	enemy_texture.loadFromFile("gfx/Zombie2.png");
	for (int i = 0; i < 7; i++)
	{
		enemies.push_back(Enemy());
		enemies[i].setTexture(enemy_texture);
		enemies[i].colision.setCollisionBox(sf::FloatRect(25, 20, 20, 30));
		enemies[i].resetHealth();
	}
	enemies[0].setPosition(450, 70);
	enemies[1].setPosition(450, 122);
	enemies[2].setPosition(696, 70);
	enemies[3].setPosition(696, 122);
	enemies[4].setPosition(950, 70);
	enemies[5].setPosition(950, 122);
	enemies[6].setPosition(-1000, 0);
	//adding sounds and music

	audio = new AudioManager();


	//audio[0]->addMusic("sfx/MenuScore.ogg", "MenuScore");
	audio->addMusic("sfx/sewer_sound.ogg", "background_sound");

	//if (gameState->getCurrentState() == State::MENU || gameState->getCurrentState() == State::CREDITS || gameState->getCurrentState() == State::PAUSE)
	//{
	//	static bool runOnce = true;
	//	{
	//		if (runOnce)
	//		{

	//			audio[0]->stopAllMusic();
	//			audio[0]->playMusicbyName("MenuScore");
	//			runOnce = false;
	//		}
	//	}
	//	
	//		
	//	
	//}
	//else
	//{

		  //  audio[0]->stopAllMusic();
		//	audio[1]->playMusicbyName("background_sound");


//	}


	 

	audio->addSound("sfx/walking2.ogg", "walking");
	audio->addSound("sfx/shooting1.ogg", "shoot");



	


	static bool run = true;
	float speed = 90.f;
	float screen = 240;
	float backscreen = 0;
	float screenback = 960;
	float enemySpeed = 50.f;
	sf::Vector2f velocity;
	//view->move(200, 0);
	sf::Vector2f enemyVelocity;
	sf::FloatRect bulletBoundry;
	main_player.resetHealth();
	gamereset = true;
}
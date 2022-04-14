#include "projectiles.h"
projectiles::projectiles()
{
	bullet.setSize(sf::Vector2f(2, 2));
	bullet.setFillColor(sf::Color::White);
	bullet.setPosition(sf::Vector2f(100,100));
	colision.setRect(sf::IntRect(0, 0, 2, 2));
}
void projectiles::bullet_draw(sf::RenderWindow* window)
{
	window->draw(bullet);
	
}
void projectiles::move(float dt)
{
		bullet.move(sf::Vector2f(velocity*speed*dt));	
}
void projectiles::setposition(std::string direction, sf::Vector2f position)
{
	//std::cout << direction << std::endl;
	if (direction == "right")
	{
		position += sf::Vector2f(45, 15);
		bullet.setPosition(position);
		colision.setPosition(bullet.getPosition());
	}
	if (direction == "left")
	{
		std::cout << direction<< std::endl;
		position += sf::Vector2f(5, 18);
		bullet.setPosition(position);
		colision.setPosition(bullet.getPosition());
	}
	if (direction == "up")
	{
		std::cout << direction << std::endl;
		position += sf::Vector2f(29, 18);
		bullet.setPosition(position);
		colision.setPosition(bullet.getPosition());
	}
	if (direction == "down")
	{
		std::cout << direction << std::endl;
		position += sf::Vector2f(28, 30);
		bullet.setPosition(position);
		colision.setPosition(bullet.getPosition());
	}
	if (direction == "downleft")
	{
		std::cout << direction << std::endl;
		position += sf::Vector2f(28, 20);
		bullet.setPosition(position);
		colision.setPosition(bullet.getPosition());
	}
	if (direction == "downright")
	{
		std::cout << direction << std::endl;
		position += sf::Vector2f(35, 18);
		bullet.setPosition(position);
		colision.setPosition(bullet.getPosition());
	}
	if (direction == "upleft")
	{
		std::cout << direction << std::endl;
		position += sf::Vector2f(28, 18);
		bullet.setPosition(position);
		colision.setPosition(bullet.getPosition());
	}
	if (direction == "upright")
	{
		std::cout << direction << std::endl;
		position += sf::Vector2f(50, 18);
		bullet.setPosition(position);
		colision.setPosition(bullet.getPosition());
	}
}
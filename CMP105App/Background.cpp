#include"Background.h""
Background::Background()
{
	move.addFrame(sf::IntRect(0, 0, 1252, 288));
	move.addFrame(sf::IntRect(0, 298, 1252, 288));
	move.addFrame(sf::IntRect(0, 596, 1252, 288));
	move.setFrameSpeed(1.f / 10.f);
	mouse_anim.addFrame(sf::IntRect(0, 0, 33, 36));
	mouse_anim.addFrame(sf::IntRect(32, 0, 32, 29));
	mouse_anim.addFrame(sf::IntRect(63, 0, 35, 28));
	mouse_anim.setFrameSpeed(1.f / 10.f);
}

void Background::update(float dt)
{
	move.animate(dt);
	setTextureRect(move.getCurrentFrame());
}

void Background::mouse(float dt)
{
	mouse_anim.animate(dt);
	setTextureRect(move.getCurrentFrame());
}
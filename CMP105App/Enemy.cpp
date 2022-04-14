#include "Enemy.h"
Enemy::Enemy()
{
	enemyanimation[zombie_idle].addFrame(sf::IntRect(3, 82, 56, 66));

	enemyanimation[zombie_move].addFrame(sf::IntRect(3, 82, 56, 66));
	enemyanimation[zombie_move].addFrame(sf::IntRect(75, 85, 56, 66));
	enemyanimation[zombie_move].addFrame(sf::IntRect(148, 82, 56, 66));
	enemyanimation[zombie_move].addFrame(sf::IntRect(222, 85, 56, 66));
	enemyanimation[zombie_move].setFrameSpeed(1.f / 5.f);

	enemyanimation[zombie_attack].addFrame(sf::IntRect(4, 14, 64, 60));
	enemyanimation[zombie_attack].addFrame(sf::IntRect(76, 10, 64, 63));
	enemyanimation[zombie_attack].addFrame(sf::IntRect(147, 20, 57, 54));
	enemyanimation[zombie_attack].addFrame(sf::IntRect(205, 17, 76, 57));
	enemyanimation[zombie_attack].setFrameSpeed(1.f / 5.f);

	enemyanimation[zombie_dead].addFrame(sf::IntRect(148,156,59,70));
	enemyanimation[zombie_dead].addFrame(sf::IntRect(218,156,66,70));
	enemyanimation[zombie_dead].addFrame(sf::IntRect(296,153,66,73));
	enemyanimation[zombie_dead].addFrame(sf::IntRect(365,152,79,75));
	enemyanimation[zombie_dead].addFrame(sf::IntRect(443,152,76,76));
	enemyanimation[zombie_dead].addFrame(sf::IntRect(519,152,76,73));
	enemyanimation[zombie_dead].addFrame(sf::IntRect(1,235,77,69));
	enemyanimation[zombie_dead].setFrameSpeed(1.f / 5.f);

	enemyanimation[zombie_hit].addFrame(sf::IntRect(148, 156, 59, 70));
	enemyanimation[zombie_hit].addFrame(sf::IntRect(218, 156, 66, 70));
	enemyanimation[zombie_hit].setFrameSpeed(1.f / 10.f);

	colision.setRect(sf::IntRect(25, 20, 20, 30));
}

void Enemy::zombie_moves(animation zombie_moves, float dt)
{
	enemyanimation[zombie_moves].animate(dt);
	setTextureRect(enemyanimation[zombie_moves].getCurrentFrame());
}

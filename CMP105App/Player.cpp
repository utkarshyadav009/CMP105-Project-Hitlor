#include "Player.h"
void Player::resetHealth()
{
	health = 500000;
}
Player::Player()
{	
	health = 500000;


	all_animations[idle].addFrame(sf::IntRect(345, 4, 53, 66));

	
	//walking right
	all_animations[walkright].addFrame(sf::IntRect(345, 4, 53, 66));
	all_animations[walkright].addFrame(sf::IntRect(347, 73, 47, 65));
	all_animations[walkright].addFrame(sf::IntRect(343, 137, 53, 65));
	all_animations[walkright].addFrame(sf::IntRect(350, 203, 46, 65));
	all_animations[walkright].setFrameSpeed(1.f / 5.f);

	//walking left
	all_animations[walkleft].addFrame(sf::IntRect(119, 4, 49, 66));
	all_animations[walkleft].addFrame(sf::IntRect(122, 70, 48, 66));
	all_animations[walkleft].addFrame(sf::IntRect(127, 136, 50, 69));
	all_animations[walkleft].addFrame(sf::IntRect(127, 203, 50, 68));
	all_animations[walkleft].setFrameSpeed(1.f / 5.f);

	//walking up
	all_animations[walkup].addFrame(sf::IntRect(230, 5, 62, 66));
	all_animations[walkup].addFrame(sf::IntRect(233, 70, 65, 68));
	all_animations[walkup].addFrame(sf::IntRect(233, 136, 63, 68));
	all_animations[walkup].addFrame(sf::IntRect(236, 204, 60, 65));
	all_animations[walkup].setFrameSpeed(1.f / 5.f);

	//walking down
	all_animations[walkdown].addFrame(sf::IntRect(2, 4, 63, 68));
	all_animations[walkdown].addFrame(sf::IntRect(2, 71, 68, 68));
	all_animations[walkdown].addFrame(sf::IntRect(1, 136, 62, 67));
	all_animations[walkdown].addFrame(sf::IntRect(0, 203, 69, 68));
	all_animations[walkdown].setFrameSpeed(1.f / 5.f);

	//walking down left
	all_animations[walkdownleft].addFrame(sf::IntRect(67, 3, 49, 68));
	all_animations[walkdownleft].addFrame(sf::IntRect(73, 72,  46, 65));
	all_animations[walkdownleft].addFrame(sf::IntRect(70, 139, 50, 64));
	all_animations[walkdownleft].addFrame(sf::IntRect(69, 204, 52, 67));
	all_animations[walkdownleft].setFrameSpeed(1.f / 5.f);

	//walking up left
	all_animations[walkupleft].addFrame(sf::IntRect(170, 6, 55, 64));
	all_animations[walkupleft].addFrame(sf::IntRect(177, 73, 50, 63));
	all_animations[walkupleft].addFrame(sf::IntRect(183, 141, 46, 61));
	all_animations[walkupleft].addFrame(sf::IntRect(180, 205, 50, 63));
	all_animations[walkupleft].setFrameSpeed(1.f / 5.f);

	//walking down right
	all_animations[walkdownright].addFrame(sf::IntRect(397, 2, 54, 69));
	all_animations[walkdownright].addFrame(sf::IntRect(397, 72, 58, 67));
	all_animations[walkdownright].addFrame(sf::IntRect(399, 139, 55, 65));
	all_animations[walkdownright].addFrame(sf::IntRect(398, 203, 64, 67));
	all_animations[walkdownright].setFrameSpeed(1.f / 5.f);

	//walking up right
	all_animations[walkupright].addFrame(sf::IntRect(294, 6, 48, 65));
	all_animations[walkupright].addFrame(sf::IntRect(295, 73, 52, 64));
	all_animations[walkupright].addFrame(sf::IntRect(295, 137, 49, 67));
	all_animations[walkupright].addFrame(sf::IntRect(303, 203, 47, 68));
	all_animations[walkupright].setFrameSpeed(1.f / 5.f);

	/////////////////////////////////////////////////////SHOOTING///////////////////////////////////

	//Shooting right
	all_animations[shootright].addFrame(sf::IntRect(369, 271, 54, 59));
	all_animations[shootright].addFrame(sf::IntRect(376, 332, 60, 58));
	all_animations[shootright].addFrame(sf::IntRect(384, 393, 63, 59));
	all_animations[shootright].addFrame(sf::IntRect(393, 457, 58, 58));
	all_animations[shootright].setFrameSpeed(1.f / 5.f);

	//Shooting left
	all_animations[shootleft].addFrame(sf::IntRect(133, 271, 53, 59));
	all_animations[shootleft].addFrame(sf::IntRect(135 ,332 , 58, 58));
	all_animations[shootleft].addFrame(sf::IntRect(141, 393, 60, 59));
	all_animations[shootleft].addFrame(sf::IntRect(149, 456, 56, 59));
	all_animations[shootleft].setFrameSpeed(1.f / 5.f);


	//Shooting up 
	all_animations[shootup].addFrame(sf::IntRect(243, 271, 55, 59));
	all_animations[shootup].addFrame(sf::IntRect(248, 332, 58, 59));
	all_animations[shootup].addFrame(sf::IntRect(263, 393, 57, 59));
	all_animations[shootup].addFrame(sf::IntRect(271, 456, 57, 59));
	all_animations[shootup].setFrameSpeed(1.f / 5.f);


	//Shooting down
	all_animations[shootdown].addFrame(sf::IntRect(5, 271, 55, 59));
	all_animations[shootdown].addFrame(sf::IntRect(6, 332, 59, 59));
	all_animations[shootdown].addFrame(sf::IntRect(6, 393, 60, 59));
	all_animations[shootdown].addFrame(sf::IntRect(6, 456, 57, 59));
	all_animations[shootdown].setFrameSpeed(1.f / 5.f);

	//Shooting down left
	all_animations[shootdownleft].addFrame(sf::IntRect(68, 271, 56, 59));
	all_animations[shootdownleft].addFrame(sf::IntRect(70, 332, 60, 58));
	all_animations[shootdownleft].addFrame(sf::IntRect(79, 393, 57, 59));
	all_animations[shootdownleft].addFrame(sf::IntRect(83, 456, 57, 59));
	all_animations[shootdownleft].setFrameSpeed(1.f / 5.f);

	//Shooting up left 
	all_animations[shootupleft].addFrame(sf::IntRect(185, 271, 53, 58));
	all_animations[shootupleft].addFrame(sf::IntRect(192, 331, 53, 58));
	all_animations[shootupleft].addFrame(sf::IntRect(200, 393, 59, 59));
	all_animations[shootupleft].addFrame(sf::IntRect(206, 456, 59, 59));
	all_animations[shootupleft].setFrameSpeed(1.f / 5.f);

	//Shooting down right 
	all_animations[shootdownright].addFrame(sf::IntRect(431, 271, 53, 59));
	all_animations[shootdownright].addFrame(sf::IntRect(444, 332, 53, 58));
	all_animations[shootdownright].addFrame(sf::IntRect(451, 393, 56, 59));
	all_animations[shootdownright].addFrame(sf::IntRect(457, 456, 55, 59));
	all_animations[shootdownright].setFrameSpeed(1.f / 5.f);

	//Shooting up right 
	all_animations[shootupright].addFrame(sf::IntRect(306, 271, 57, 59));
	all_animations[shootupright].addFrame(sf::IntRect(311, 332, 63, 58));
	all_animations[shootupright].addFrame(sf::IntRect(326, 393, 57, 59));
	all_animations[shootupright].addFrame(sf::IntRect(335, 456, 57, 59));
	all_animations[shootupright].setFrameSpeed(1.f / 5.f);
	
	all_animations[die_down].addFrame(sf::IntRect(3,519,60,64));
	all_animations[die_down].addFrame(sf::IntRect(3,587,59,64));
	all_animations[die_down].addFrame(sf::IntRect(78,587,59,64));
	all_animations[die_down].addFrame(sf::IntRect(159,587,59,64));
	all_animations[die_down].addFrame(sf::IntRect(247,587,59,64));
	all_animations[die_down].setFrameSpeed(1.f / 5.f);

	all_animations[die_downleft].addFrame(sf::IntRect(78, 519, 60, 64));
	//all_animations[die_downleft].addFrame(sf::IntRect(3, 519, 60, 64));
	all_animations[die_downleft].addFrame(sf::IntRect(3, 587, 59, 64));
	all_animations[die_downleft].addFrame(sf::IntRect(78, 587, 59, 64));
	all_animations[die_downleft].addFrame(sf::IntRect(159, 587, 59, 64));
	all_animations[die_downleft].addFrame(sf::IntRect(247, 587, 59, 64));
	all_animations[die_downleft].setFrameSpeed(1.f / 5.f);

	all_animations[die_left].addFrame(sf::IntRect(149, 519, 46, 64));
	all_animations[die_left].addFrame(sf::IntRect(78, 519, 60, 64));
	all_animations[die_left].addFrame(sf::IntRect(3, 587, 59, 64));
	all_animations[die_left].addFrame(sf::IntRect(78, 587, 59, 64));
	all_animations[die_left].addFrame(sf::IntRect(159, 587, 59, 64));
	all_animations[die_left].addFrame(sf::IntRect(247, 587, 59, 64));
	all_animations[die_left].setFrameSpeed(1.f / 5.f);

	
	all_animations[die_upleft].addFrame(sf::IntRect(210, 519, 47, 64));
	all_animations[die_upleft].addFrame(sf::IntRect(149, 519, 46, 64));
	all_animations[die_upleft].addFrame(sf::IntRect(78, 519, 60, 64));
	all_animations[die_upleft].addFrame(sf::IntRect(3, 587, 59, 64));
	all_animations[die_upleft].addFrame(sf::IntRect(78, 587, 59, 64));
	all_animations[die_upleft].addFrame(sf::IntRect(159, 587, 59, 64));
	all_animations[die_upleft].addFrame(sf::IntRect(247, 587, 59, 64));
	all_animations[die_upleft].setFrameSpeed(1.f / 5.f);

	all_animations[die_up].addFrame(sf::IntRect(271, 519, 55, 64));
	all_animations[die_up].addFrame(sf::IntRect(210, 519, 47, 64));
	all_animations[die_up].addFrame(sf::IntRect(149, 519, 46, 64));
	all_animations[die_up].addFrame(sf::IntRect(78, 519, 60, 64));
	all_animations[die_up].addFrame(sf::IntRect(3, 587, 59, 64));
	all_animations[die_up].addFrame(sf::IntRect(78, 587, 59, 64));
	all_animations[die_up].addFrame(sf::IntRect(159, 587, 59, 64));
	all_animations[die_up].addFrame(sf::IntRect(247, 587, 59, 64));
	all_animations[die_up].setFrameSpeed(1.f / 5.f);

	all_animations[die_upright].addFrame(sf::IntRect(339, 519, 50, 64));
	all_animations[die_upright].addFrame(sf::IntRect(389, 519, 55, 64));
	all_animations[die_upright].addFrame(sf::IntRect(439, 519, 55, 64));
	all_animations[die_upright].addFrame(sf::IntRect(3, 587, 59, 64));
	all_animations[die_upright].addFrame(sf::IntRect(78, 587, 59, 64));
	all_animations[die_upright].addFrame(sf::IntRect(159, 587, 59, 64));
	all_animations[die_upright].addFrame(sf::IntRect(247, 587, 59, 64));
	all_animations[die_upright].setFrameSpeed(1.f / 5.f);

	all_animations[die_right].addFrame(sf::IntRect(389, 519, 55, 64));
	all_animations[die_right].addFrame(sf::IntRect(439, 519, 55, 64));
	all_animations[die_right].addFrame(sf::IntRect(3, 587, 59, 64));
	all_animations[die_right].addFrame(sf::IntRect(78, 587, 59, 64));
	all_animations[die_right].addFrame(sf::IntRect(159, 587, 59, 64));
	all_animations[die_right].addFrame(sf::IntRect(247, 587, 59, 64));
	all_animations[die_right].setFrameSpeed(1.f / 5.f);

	all_animations[die_downright].addFrame(sf::IntRect(439, 519, 55, 64));
	all_animations[die_downright].addFrame(sf::IntRect(3, 587, 59, 64));
	all_animations[die_downright].addFrame(sf::IntRect(78, 587, 59, 64));
	all_animations[die_downright].addFrame(sf::IntRect(159, 587, 59, 64));
	all_animations[die_downright].addFrame(sf::IntRect(247, 587, 59, 64));
	all_animations[die_downright].setFrameSpeed(1.f / 5.f);

	all_animations[hit].addFrame(sf::IntRect(389, 519, 55, 64));
	all_animations[hit].setFrameSpeed(1.f / 5.f);
	colision.setRect(sf::IntRect(10, 15, 35, 35));
	colision.setPlayerRadius(sf::IntRect(-100, -70, 250, 150));
}
void Player::die( float dt,std::string direction)
{
	if (direction == "right")
	{
		all_animations[die_right].animate(dt);
		setTextureRect(all_animations[die_right].getCurrentFrame());
	}
	if (direction == "left")
	{
		all_animations[die_left].animate(dt);
		setTextureRect(all_animations[die_left].getCurrentFrame());
	}
	if (direction == "upright")
	{
		all_animations[die_upright].animate(dt);
		setTextureRect(all_animations[die_upright].getCurrentFrame());
	}
	if (direction == "downright")
	{
		all_animations[die_downright].animate(dt);
		setTextureRect(all_animations[die_downright].getCurrentFrame());
	}
	if (direction == "up")
	{
		all_animations[die_up].animate(dt);
		setTextureRect(all_animations[die_up].getCurrentFrame());
	}
	if (direction == "down")
	{
		all_animations[die_down].animate(dt);
		setTextureRect(all_animations[die_down].getCurrentFrame());
	}
	if (direction == "upleft")
	{
		all_animations[die_upleft].animate(dt);
		setTextureRect(all_animations[die_upleft].getCurrentFrame());
	}
	if (direction == "downright")
	{
		all_animations[die_downright].animate(dt);
		setTextureRect(all_animations[die_downright].getCurrentFrame());
	}
	if (direction == "hit")
	{
		all_animations[hit].animate(dt);
		setTextureRect(all_animations[hit].getCurrentFrame());
	}
}
void Player::walk(animation walk_animation,float dt)
{	
	all_animations[walk_animation].animate(dt);
	setTextureRect(all_animations[walk_animation].getCurrentFrame());

}


void Player::shoot(animation shoot_animation, float dt)
{	
		all_animations[shoot_animation].animate(dt);
		setTextureRect(all_animations[shoot_animation].getCurrentFrame());
		
}

void Player::stand(float dt)
{
	all_animations[idle].animate(dt);
	setTextureRect(all_animations[idle].getCurrentFrame());
	current_animation = idle;
	
}

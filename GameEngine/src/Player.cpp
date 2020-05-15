#include "Player.h"


Player::Player() :
	size{ glm::vec2(150.0f, 20.0f) },
	position{ glm::vec2(300.f, 10.f) },
	velocity{ 5 },
	lives {3}
{

	pushComponent(ComponentType::RENDERER, std::make_shared<Renderer>("resources/shaders/shader.vs",
		"resources/shaders/shader.fs", vertices, 5, indices,
		"resources/textures/player.png"
		));
	pushComponent(ComponentType::TRANSFORM, std::make_shared<Transform>());
}

Player::~Player()
{

}

void Player::update() 
{
	(std::static_pointer_cast<Transform>(components.find(ComponentType::TRANSFORM)->second))->update(position, size, 0);
}


void Player::setPositionX(float val)
{
	position.x += val;
}


glm::vec2 Player::getPosition() const
{
	return position;
}

glm::vec2 Player::getSize() const
{
	return size;
}

void Player::setVelocity(float newVelocity)
{
	velocity = newVelocity;
}

float Player::getVelocity() const
{
	return velocity;
}

int Player::getLives() const
{
	return lives;
}

void Player::setLives(int l)
{
	lives = l;
}

void Player::livesMinus()
{
	lives--;
}

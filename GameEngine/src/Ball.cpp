#include "Ball.h"

Ball::Ball() :
	size{ glm::vec2(15.0f, 15.0f) },
	position{ glm::vec2(300.0f, 70.0f) },
	velocity{ glm::vec2{1.0f, 1.0f} }
{
	pushComponent(ComponentType::RENDERER, std::make_shared<Renderer>("resources/shaders/shader.vs",
		"resources/shaders/shader.fs", vertices, 5, indices,
		"resources/textures/ball.png"
		));
	pushComponent(ComponentType::TRANSFORM, std::make_shared<Transform>());
}

Ball::~Ball()
{

}

glm::vec2 Ball::getPosition() const
{
	return position;
}

glm::vec2 Ball::getSize() const
{
	return size;
}

void Ball::setPosition(glm::vec2 val)
{
	position = val;
}

void Ball::setVelocity(float x, float y)
{
	if (x)
		velocity.x = x;
	if (y)
		velocity.y = y;
}

glm::vec2 Ball::getVelocity()
{
	return velocity;
}

void Ball::update() 
{
	position += velocity;
	if (position.x <= 0.0f) {
		velocity.x = -velocity.x;
		position.x = 0.0f;
	}
	else if (position.x + size.x >= 800) {
		velocity.x = -velocity.x;
		position.x = 800 - size.x;
	}
	if (position.y >= 600.0f) {
		velocity.y = -velocity.y;
		position.y = 600.0f;
	}
	(std::static_pointer_cast<Transform>(components.find(ComponentType::TRANSFORM)->second))->update(position, size, 0);

}

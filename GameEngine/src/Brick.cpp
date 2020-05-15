#include "Brick.h"

Brick::Brick(const glm::vec2& pos, const glm::vec2& size, int value) :
	position{ pos },
	size{ size }
{
	if (value == 2) {

		pushComponent(ComponentType::RENDERER, std::make_shared<Renderer>("resources/shaders/shader.vs",
			"resources/shaders/shader.fs", vertices, 5, indices,
			"resources/textures/block1.png"
			));
		pushComponent(ComponentType::TRANSFORM, std::make_shared<Transform>());
	}
	else if (value == 3) {

		pushComponent(ComponentType::RENDERER, std::make_shared<Renderer>("resources/shaders/shader.vs",
			"resources/shaders/shader.fs", vertices, 5, indices,
			"resources/textures/block2.png"
			));
		pushComponent(ComponentType::TRANSFORM, std::make_shared<Transform>());
	}
}

Brick::~Brick()
{

}

void Brick::update()
{
	if (exist)
		(std::static_pointer_cast<Transform>(components.find(ComponentType::TRANSFORM)->second))->update(position, size, 0);
}

glm::vec2 Brick::getPosition() const
{
	return position;
}

glm::vec2 Brick::getSize() const
{
	return size;
}
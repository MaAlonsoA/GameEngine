#include "SolidBrick.h"

SolidBrick::SolidBrick(const glm::vec2& pos, const glm::vec2& size) :
	position{ pos },
	size{ size }
{

	pushComponent(ComponentType::RENDERER, std::make_shared<Renderer>("resources/shaders/shader.vs",
		"resources/shaders/shader.fs", vertices, 5, indices,
		"resources/textures/solidBrick.png"
		));
	pushComponent(ComponentType::TRANSFORM, std::make_shared<Transform>());
	
}

SolidBrick::~SolidBrick()
{

}

void SolidBrick::update() 
{
	if(exist)
		( std::static_pointer_cast<Transform>(components.find(ComponentType::TRANSFORM)->second) )->update(position, size, 0);
}
glm::vec2 SolidBrick::getPosition() const
{
	return position;
}

glm::vec2 SolidBrick::getSize() const
{
	return size;
}
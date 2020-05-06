#include "SolidBrick.h"

SolidBrick::SolidBrick(glm::vec2 pos, glm::vec2 size) :
	position{ pos },
	size{ size },
	isSolid{ true }
{

	pushComponent(ComponentType::RENDERER, std::make_shared<Renderer>("resources/shaders/shader.vs",
		"resources/shaders/shader.fs", vertices, 5, indices,
		"resources/textures/charly.png"
		));
	pushComponent(ComponentType::TRANSFORM, std::make_shared<Transform>());
	
}

void SolidBrick::update() const
{
	std::static_pointer_cast<Transform>(components.find(ComponentType::TRANSFORM)->second)->update(position, size, 0);
}

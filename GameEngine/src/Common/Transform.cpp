#include "Transform.h"

Transform::Transform()
{

}

Transform::~Transform()
{
	localFather.reset();
}

void Transform::init()
{
	localFather = father.lock();
	lRenderer = std::static_pointer_cast<Renderer>(localFather->getComponents().find(ComponentType::RENDERER)->second);
}

void Transform::update() const
{
	lRenderer->getShader()->use();
	glm::mat4 projection = glm::ortho(-1280.0f, 1280.0f, -1024.0f, 1024.0f, -1.0f, 1.0f);
	lRenderer->getShader()->setUniformMatrix4("u_proj", projection);
	lRenderer->update();
}

void Transform::update( const glm::vec2& position, const glm::vec2& size, float rotate) const
{
	lRenderer->getShader()->use();
	glm::mat4 projection = glm::ortho(-1280.0f, 1280.0f, -1024.0f, 1024.0f, -1.0f, 1.0f);
	std::string name2{ "u_model" };
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position, 0.0f));

	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
	model = glm::scale(model, glm::vec3(size, 1.0f));
	lRenderer->getShader()->setUniformMatrix4("u_proj", projection);
	lRenderer->getShader()->setUniformMatrix4(name2, model);
	lRenderer->update();
}


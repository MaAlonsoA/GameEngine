#include "Transform.h"

Transform::Transform()
{

}

Transform::~Transform()
{
	localFather.reset();
}

void Transform::foo()
{
	localFather = father.lock();
	localShader = std::static_pointer_cast<Renderer>(localFather->getComponents().find(ComponentType::RENDERER)->second)->getShader();
}

void Transform::update() const
{

}


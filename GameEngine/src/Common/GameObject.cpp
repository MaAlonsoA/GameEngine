#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::pushChild(std::shared_ptr<GameObject> child)
{
	child->setFather(shared_from_this());
	children.push_back(child);
}

void GameObject::pushComponent(std::shared_ptr<Component> component)
{
	component->setFather(shared_from_this());
	components.push_back(component);
}

void GameObject::setFather(std::weak_ptr<GameObject> father)
{
	father = father;
}

void GameObject::update()
{
	for (auto& elem : components)
		elem->update();

	for (auto& elem : children)
		elem->update();
}

#include "GameObject.h"
#include <iostream>

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


void GameObject::pushComponent(const ComponentType& type, std::shared_ptr<Component> elem)
{
	components.insert( std::pair<ComponentType, std::shared_ptr<Component>>(type, elem) );
}


void GameObject::setFather(std::weak_ptr<GameObject> father)
{
	father = father;
}


void GameObject::setExist(bool val)
{
	exist = val;
}

bool GameObject::getExist()
{
	return exist;
}

std::map<ComponentType,std::shared_ptr<Component>> GameObject::getComponents() const
{
	return components;
}

void GameObject::objectInit()
{
	components.find(ComponentType::RENDERER)->second->setFather(shared_from_this());
	components.find(ComponentType::TRANSFORM)->second->setFather(shared_from_this());
}

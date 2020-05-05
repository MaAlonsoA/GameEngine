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
	elem->setFather(shared_from_this());
	components.insert( std::pair<ComponentType, std::shared_ptr<Component>>(type, elem) );
}


void GameObject::setFather(std::weak_ptr<GameObject> father)
{
	father = father;
}

void GameObject::update()
{

	for (auto& elem : components) {
		elem.second->update();
	}
		
	
	for (auto& elem : children)
		elem->update();
}

std::map<ComponentType,std::shared_ptr<Component>> GameObject::getComponents() const
{
	return components;
}

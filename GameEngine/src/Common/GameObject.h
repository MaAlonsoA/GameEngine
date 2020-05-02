#pragma once

#include <vector>
#include <memory>

#include "Component.h"

class GameObject : public std::enable_shared_from_this<GameObject> 
{
private:
	std::weak_ptr<GameObject> father;
	std::vector<std::shared_ptr<GameObject>> children;
	std::vector<std::shared_ptr<Component>> components;

public:
	GameObject();
	~GameObject();
	void pushChild(std::shared_ptr<GameObject> child);
	void pushComponent(std::shared_ptr<Component> component);
	void setFather(std::weak_ptr<GameObject> father);
	void update();

};


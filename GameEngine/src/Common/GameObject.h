#pragma once

#include <vector>
#include <memory>
#include <map>

#include "Component.h"


enum class ComponentType : unsigned char {
	RENDERER,
	TRANSFORM,
};
class Component;
class GameObject : public std::enable_shared_from_this<GameObject> 
{
private:
	std::weak_ptr<GameObject> father;
	std::vector<std::shared_ptr<GameObject>> children;
	std::map<ComponentType, std::shared_ptr<Component>> components;

public:
	GameObject();
	~GameObject();
	void pushChild(std::shared_ptr<GameObject> child);
	void pushComponent(const ComponentType& type, std::shared_ptr<Component> elem);
	void setFather(std::weak_ptr<GameObject> father);
	void update();
	std::map<ComponentType, std::shared_ptr<Component>>getComponents() const;
};


#pragma once

#include <vector>
#include <memory>
#include <map>

#include "Component.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


enum class ComponentType : unsigned char {
	RENDERER,
	TRANSFORM,
	BEHAVIOR
};
class Component;
class GameObject : public std::enable_shared_from_this<GameObject> 
{
protected:

	std::weak_ptr<GameObject> father;
	std::vector<std::shared_ptr<GameObject>> children;
	std::map<ComponentType, std::shared_ptr<Component>> components;
	bool exist;

public:
	GameObject();
	~GameObject();
	void pushChild(std::shared_ptr<GameObject> child);
	void pushComponent(const ComponentType& type, std::shared_ptr<Component> elem);
	void setFather(std::weak_ptr<GameObject> father);
	std::map<ComponentType, std::shared_ptr<Component>>getComponents() const;
	void objectInit();
	virtual void update() = 0;
	virtual glm::vec2 getPosition() const = 0;
	virtual glm::vec2 getSize() const = 0;
	virtual inline bool isSolid() = 0;
	void setExist(bool val);
	bool getExist();
};


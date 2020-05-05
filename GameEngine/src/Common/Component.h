#pragma once

#include <memory>

class GameObject;
class Component
{
protected:
	std::weak_ptr<GameObject> father;
public:
	
	void setFather(std::weak_ptr<GameObject> father);
	virtual void update()const = 0;
	
};


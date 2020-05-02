#pragma once

#include <memory>

//#include "GameObject.h"
class GameObject;

class Component
{

private:
	std::weak_ptr<GameObject> father;
	
public:
	void setFather(std::weak_ptr<GameObject> father);
	virtual void update() = 0;
};


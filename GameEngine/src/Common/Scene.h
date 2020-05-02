#pragma once

#include <vector>
#include <memory>

#include "GameObject.h"

class Scene
{
private:
	std::vector < std::shared_ptr<GameObject> > entities;
public:
	Scene();
	~Scene();
	void update();
	void pushGameObject(std::shared_ptr<GameObject > gameObject);
};


#pragma once

#include <vector>
#include <memory>
#include <string>
#include <fstream>

#include "GameObject.h"

class Scene
{
protected:
	std::vector < std::shared_ptr<GameObject> > entities;
public:

	Scene();
	~Scene();
	void update();
	void pushGameObject(std::shared_ptr<GameObject > gameObject);
	void loadFromFile(const std::string& levelPath);
	virtual void initScene(const std::vector<std::vector<unsigned>> & leveData) = 0;
	std::vector < std::shared_ptr<GameObject> > getEntities();
};


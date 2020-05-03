#include "Scene.h"
#include <iostream>
Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::update()
{

	for (auto& elem : entities)
		elem->update();
	
}

void Scene::pushGameObject(std::shared_ptr<GameObject > gameObject)
{
	entities.push_back(gameObject);
}

#include "Scene.h"

Scene::Scene()
{
	
}

Scene::~Scene()
{

}

void Scene::update()
{
	for (const auto& elem : entities)
		elem->update();	
}

void Scene::pushGameObject(std::shared_ptr<GameObject > gameObject)
{
	entities.push_back(gameObject);
}

void Scene::loadFromFile(const std::string& levelPath)
{
	std::ifstream levelFile(levelPath);
	std::string line;
	
	std::vector<std::vector<unsigned>> levelData;

	if (levelFile) {
		while (getline(levelFile, line)) {
			std::vector<unsigned> row;
			for (const auto& elem : line) {
				if (elem != ' ') row.push_back(elem-48);
			}
			levelData.push_back(row);
		}
	}
	initScene( levelData);
}



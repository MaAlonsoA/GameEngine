#include "Level.h"


Level::Level(const std::string& levelPath)
{
	loadFromFile(levelPath);
}

void Level::initScene(const std::vector<std::vector<unsigned>>& levelData)
{

	auto ball{ std::make_shared<Ball>() };
	entities.push_back(ball);
	entities.front()->objectInit();
	std::static_pointer_cast<Transform>(entities.front()->getComponents().find(ComponentType::TRANSFORM)->second)->init();

	auto player{ std::make_shared<Player>() };
	entities.push_back(player);
	entities.at(1)->objectInit();
	std::static_pointer_cast<Transform>(entities.at(1)->getComponents().find(ComponentType::TRANSFORM)->second)->init();
	

	for (unsigned y{ 0 }; y < levelData.size(); y++) {
		for (unsigned x{ 0 }; x < levelData.at(0).size(); x++) {
			if (levelData.at(y).at(x) == 1) {
				pushGameObject(
					std::make_shared<SolidBrick>(
						glm::vec2(50 * x, 600 - (40*y)), glm::vec2(50, 40)
						)
				);
				entities.back()->objectInit();
				std::static_pointer_cast<Transform>(entities.back()->getComponents().find(ComponentType::TRANSFORM)->second)->init();
			}
			if (levelData.at(y).at(x) == 2 || levelData.at(y).at(x) == 3) {
				pushGameObject(
					std::make_shared<Brick>(
						glm::vec2(50 * x, 600 - (40 * y)), glm::vec2(50, 40), levelData.at(y).at(x)
						)
				);
				entities.back()->objectInit();
				std::static_pointer_cast<Transform>(entities.back()->getComponents().find(ComponentType::TRANSFORM)->second)->init();
			}
		}
	}
}

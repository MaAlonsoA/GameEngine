#include "Level.h"


Level::Level(const std::string& levelPath)
{
	loadFromFile(levelPath);
}

void Level::initScene(const std::vector<std::vector<unsigned>>& levelData)
{
	unsigned dataHeight{ static_cast<unsigned>(levelData.size()) };
	unsigned dataWidth{ static_cast<unsigned>(levelData.at(0).size()) };

	float objectWidth{ 1280 / static_cast<float>(dataWidth) };
	float objectHeigth{ 1024 / static_cast<float>(dataHeight) };


	for (unsigned y{ 0 }; y < dataHeight; y++) {
		for (unsigned x{ 0 }; x < dataHeight; x++)
			if (levelData.at(y).at(x) == 1) {
				pushGameObject(
					std::make_shared<SolidBrick>(
						glm::vec2(objectWidth * x, objectHeigth * y), glm::vec2(objectWidth, objectHeigth)
						)
				);
			}
	}
}

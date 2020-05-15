#pragma once

#include "Common/Scene.h"
#include "SolidBrick.h"
#include "Brick.h"
#include "Player.h"
#include "Ball.h"

class Level : public Scene
{
public:
	Level(const std::string& levelPath);
	void initScene(const std::vector<std::vector<unsigned>>& levelData);
};


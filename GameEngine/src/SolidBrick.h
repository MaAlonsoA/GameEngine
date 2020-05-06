#pragma once

#include "Common/GameObject.h"
#include "Common/Renderer.h"
#include "Common/Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class SolidBrick : public GameObject
{

	bool isSolid;

	std::vector <float> vertices{
	0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
	0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};
	std::vector <unsigned> indices{
		0, 1, 3,
		1, 2, 3
	};
	glm::vec2 position;
	glm::vec2 size;


public:
	SolidBrick(glm::vec2 pos, glm::vec2 size);
	void update() const;
};


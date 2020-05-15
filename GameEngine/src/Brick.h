#pragma once

#include "Common/GameObject.h"
#include "Common/Renderer.h"
#include "Common/Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Brick : public GameObject
{
private:
	
	std::vector <float> vertices{
	 0.0f,  0.0f, 0.0f,	 0.0f,  1.0f,
	 0.0f, -1.0f, 0.0f,  0.0f,  0.0f,
	 1.0f,  0.0f, 0.0f,  1.0f,  1.0f,
	 1.0f, -1.0f, 0.0f,  1.0f,  0.0f
	};
	std::vector <unsigned> indices{
		0, 1, 2,
		1, 3, 2
	};
	glm::vec2 position;
	glm::vec2 size;


public:
	Brick(const glm::vec2& pos, const glm::vec2& size, int value);
	~Brick();
	void update();
	inline bool isSolid() { return false; };
	glm::vec2 getPosition() const;
	glm::vec2 getSize() const;
};





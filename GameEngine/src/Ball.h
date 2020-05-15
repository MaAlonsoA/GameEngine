#pragma once

#include "Common/GameObject.h"
#include "Common/Renderer.h"
#include "Common/Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Ball : public GameObject
{
private:
	std::vector <float> vertices{
	0.0f,  0.0f, 0.0f,	0.0f,  1.0f,
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
	glm::vec2 velocity;

public:
	Ball();
	~Ball();
	glm::vec2 getPosition() const;
	void setPosition(glm::vec2 val);
	
	glm::vec2 getSize() const;

	void setVelocity(float x, float y);
	glm::vec2 getVelocity();
	void update();
	inline bool isSolid() { return true; };

};


#pragma once

#include "Common/GameObject.h"
#include "Common/Renderer.h"
#include "Common/Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Player : public GameObject
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
	float velocity;
	int lives;
public:
	Player();
	~Player();
	void update();
	void setPositionX(float val);
	glm::vec2 getPosition() const;
	glm::vec2 getSize() const;
	void setVelocity(float multi);
	float getVelocity() const;
	inline bool isSolid() { return true; };
	int getLives()const;
	void setLives(int l);
	void livesMinus();

};


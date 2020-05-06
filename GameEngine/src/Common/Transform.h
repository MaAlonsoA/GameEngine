#pragma once

#include <memory>

#include "GameObject.h"
#include "Component.h"
#include "Shader.h"
#include "Renderer.h"

class Transform : public Component
{
public:
	std::shared_ptr<GameObject> localFather;
	std::shared_ptr<Renderer> lRenderer;
public:
	Transform();
	~Transform();
	void init();
	void update() const;
	void update(const glm::vec2& position, const glm::vec2& size, float rotate) const;

};


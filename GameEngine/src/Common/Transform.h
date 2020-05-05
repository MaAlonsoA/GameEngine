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
	std::shared_ptr<Shader> localShader;
public:
	Transform();
	~Transform();
	void foo();
	void update() const;
};


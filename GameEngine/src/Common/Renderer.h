#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Shader.h"
#include "Texture.h"
#include "Component.h"

class Renderer : public Component
{
private:
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Texture> texture;
	unsigned int VBO;
	unsigned int VAO;
public:
	Shader loadShader(	const std::string& vertexPath, 
						const std::string& fragmentPath, 
						std::shared_ptr<std::string> geometricPath
					);
	Texture loadTexture(const std::string& texturePath, bool alpha);
	std::shared_ptr<Shader> getShader();
	std::shared_ptr<Texture> getTexture();
	void initRenderer();



};


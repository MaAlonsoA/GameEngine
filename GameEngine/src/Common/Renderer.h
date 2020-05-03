#pragma once

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Component.h"
#include "Shader.h"
#include "Texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Renderer : public Component
{
private:
	unsigned int shaderProgram;
	unsigned int textureProgram;
	std::vector <float> vertices;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int vertexSize;

public:
	unsigned int loadShader(	const std::string& vertexPath, 
								const std::string& fragmentPath
							);
	unsigned int loadTexture(const std::string& texturePath, bool alpha);
	void initRenderer();
	void update();
	Renderer(	const std::string& vertexPath,
				const std::string& fragmentPat,
				const std::vector<float>& vertices,
				unsigned short vertexSize,
				const std::string& texturePath,
				bool alpha
			);

	

};


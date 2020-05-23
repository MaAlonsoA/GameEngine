#pragma once

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Component.h"
#include "Shader.h"
#include "texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Renderer : public Component
{
private:
	VertexArray VAO;
	VertexBuffer VBO;
	IndexBuffer IBO;
	//Shader
	std::shared_ptr<Shader> shader;
	std::vector<float> vertices;
	unsigned vertexSize;
	std::vector<unsigned> indices;
	std::shared_ptr<Shader> loadShader(const std::string& vertexPath, const std::string& fragmentPath);
	//Texture
	std::shared_ptr<Texture> texture;
	std::shared_ptr<Texture> loadTexture(const std::string& texturePath);
	//Uniforms
	bool uniformsEnable;
	std::string uniformName;
	
public:
	//Without texture Constructor
	Renderer(	const std::string& vertexPath,
				const std::string& fragmentPath,
				const std::vector<float>& vertices,
				unsigned vertexSize,
				std::vector<unsigned> indices
			);
	//With texture Constructor
	Renderer(	const std::string& vertexPath,
				const std::string& fragmentPath,
				const std::vector<float>& vertices,
				unsigned vertexSize,
				std::vector<unsigned> indices,
				const std::string& texturePath
			);
	~Renderer();
	void update() const;
	void enableUniform(bool enable);
	std::shared_ptr<Shader> getShader() const;
};


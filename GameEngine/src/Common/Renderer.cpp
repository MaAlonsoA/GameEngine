#include "Renderer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


std::shared_ptr<Shader> Renderer::loadShader(const std::string& vertexPath, const std::string& fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vShaderFile(vertexPath);
	std::ifstream fShaderFile(fragmentPath);

	std::stringstream vShaderSS;
	vShaderSS << vShaderFile.rdbuf();
	std::stringstream fShaderSS;
	fShaderSS << fShaderFile.rdbuf();

	vShaderFile.close();
	fShaderFile.close();

	vertexCode = vShaderSS.str();
	fragmentCode = fShaderSS.str();

	auto shader{ std::make_shared<Shader>(vertexCode,fragmentCode) };
	return shader;
}

std::shared_ptr<Texture> Renderer::loadTexture(const std::string texturePath)
{
	int width{ 512 };
	int height{ 512 };
	int nrChanel;
	const char* src{ texturePath.c_str() };
	stbi_set_flip_vertically_on_load(1);
	unsigned char* textureData{ stbi_load(src, &width, &height, &nrChanel, 0) };
	
	auto texture{std::make_shared<Texture> (textureData, width, height) };
	stbi_image_free(textureData);

	return texture;
}


Renderer::Renderer(const std::string& vertexPath, const std::string& fragmentPath, const std::vector<float>& vertices, unsigned vertexSize, std::vector<unsigned> indices) :
	shader{ loadShader(vertexPath, fragmentPath) },
	vertices{ vertices },
	vertexSize{ vertexSize },
	indices{ indices },
	VBO(vertices, vertices.size() ),
	IBO(indices, indices.size()),
	uniformsEnable { true }
{
	VertexBufferLayout layout;
	layout.push(vertexSize);
	VAO.addBuffer(VBO, layout);
}

Renderer::Renderer(const std::string& vertexPath, const std::string& fragmentPath, const std::vector<float>& vertices, unsigned vertexSize, std::vector<unsigned> indices, const std::string& texturePath) :
	shader{ loadShader(vertexPath, fragmentPath) },
	vertices{ vertices },
	vertexSize{ vertexSize },
	indices{ indices },
	VBO(vertices, vertices.size()),
	IBO(indices, indices.size()),
	uniformsEnable{ true },
	texture {loadTexture(texturePath)}
{
	VertexBufferLayout layout;
	layout.push(vertexSize - 2.0f);
	layout.push(2);
	VAO.addBuffer(VBO, layout);
}

Renderer::~Renderer()
{

}

void Renderer::update() const
{

	shader->use();
	if (texture) {
		shader->setUniform1i("u_Texture", 0);
		texture->bind();
	}
	VAO.bind();
	IBO.bind();
	glDrawElements(GL_TRIANGLES, IBO.getAmount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::enableUniform(bool enable)
{
	uniformsEnable = enable;
}

std::shared_ptr<Shader> Renderer::getShader() const
{
	return shader;
}

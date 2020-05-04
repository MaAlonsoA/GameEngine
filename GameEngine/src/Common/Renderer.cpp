#include "Renderer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

std::shared_ptr<Texture> Renderer::loadTexture(const std::string texturePath, bool alpha)
{
	int width{ 512 };
	int height{ 512 };
	int nrChanel;
	const char* src{ texturePath.c_str() };
	
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
	enableUniforms {false}
{
	VertexBufferLayout layout;
	layout.push<float>(vertexSize);
	VAO.addBuffer(VBO, layout);
}

Renderer::Renderer(const std::string& vertexPath, const std::string& fragmentPath, const std::vector<float>& vertices, unsigned vertexSize, std::vector<unsigned> indices, const std::string& texturePath, bool alpha) :
	shader{ loadShader(vertexPath, fragmentPath) },
	vertices{ vertices },
	vertexSize{ vertexSize },
	indices{ indices },
	VBO(vertices, vertices.size()),
	IBO(indices, indices.size()),
	enableUniforms{ false },
	texture {loadTexture(texturePath, alpha)}
{
	VertexBufferLayout layout;
	layout.push<float>(vertexSize - 2.0f);
	layout.push<float>(2);
	VAO.addBuffer(VBO, layout);
}

Renderer::~Renderer()
{

}

void Renderer::update() const
{
	if (enableUniforms) {
		switch (uniformData.size())
		{
		case 1: shader->setUniform1f(uniformName,  uniformData.at(0) );
		case 2: shader->setUniform4f(uniformName, { uniformData.at(0), uniformData.at(1) });
		case 3: shader->setUniform4f(uniformName, { uniformData.at(0), uniformData.at(1), uniformData.at(2) });
		case 4: shader->setUniform4f(uniformName, { uniformData.at(0), uniformData.at(1), uniformData.at(2), uniformData.at(3) });
		}
	}
	
	shader->setUniform1i("u_Texture", 0);
	shader->use();
	texture->bind();
	VAO.bind();
	IBO.bind();
	glDrawElements(GL_TRIANGLES, IBO.getAmount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::setUniform(bool enable, const std::vector<float>& data, const std::string& name)
{
	enableUniforms = enable;
	uniformData = data;
	uniformName = name;
}
